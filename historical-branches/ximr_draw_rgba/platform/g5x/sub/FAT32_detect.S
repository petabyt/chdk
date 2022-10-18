
"    mov     r1, r4\n"              //  pointer to MBR in r1
"    bl      mbr_read_dryos\n"      //  total sectors count in r0 before and after call

// Start of DataGhost's FAT32 autodetection code (Digic6+ version by philmoz)
// Policy: If there is a partition which has type FAT32 or exFat, use the first one of those for image storage
// According to the code below, we can use r1, r2, r3 and r12.
// LR wasn't really used anywhere but for storing a part of the partition signature. This is the only thing
// that won't work with an offset, but since we can load from LR+offset into LR, we can use this to do that :)
"    mov     r7, r4\n"              // Copy the MBR start address so we have something to work with
"    mov     lr, r4\n"              // Save old offset for MBR signature
"    mov     r1, #1\n"              // Note the current partition number
"    b       dg_sd_fat32_enter\n"   // We actually need to check the first partition as well, no increments yet!
"dg_sd_fat32:\n"
"    cmp     r1, #4\n"              // Did we already see the 4th partition?
"    beq     dg_sd_fat32_end\n"     // Yes, break. We didn't find anything, so don't change anything.
"    add     r7, r7, #0x10\n"       // Second partition
"    add     r1, r1, #1\n"          // Second partition for the loop
"dg_sd_fat32_enter:\n"
"    ldrb.w  r2, [r7, #0x1BE]\n"    // Partition status
"    ldrb.w  r3, [r7, #0x1C2]\n"    // Partition type (FAT32 = 0xB)
"    cmp     r3, #0xB\n"            // Is this a FAT32 partition?
"    beq     dg_sd_valid\n"
"    cmp     r3, #0xC\n"            // Not 0xB, is it 0xC (FAT32 LBA) then?
"    beq     dg_sd_valid\n"
"    cmp     r3, #0x7\n"            // exFat?
"    bne     dg_sd_fat32\n"         // No, it isn't. Loop again.
"dg_sd_valid:\n"
"    cmp     r2, #0x00\n"           // It is, check the validity of the partition type
"    beq     dg_sd_ok\n"
"    cmp     r2, #0x80\n"
"    bne     dg_sd_fat32\n"         // Invalid, go to next partition
"dg_sd_ok:\n"
                                    // This partition is valid, it's the first one, bingo!
"    mov     r4, r7\n"              // Move the new MBR offset for the partition detection.

"dg_sd_fat32_end:\n"
// End of DataGhost's FAT32 autodetection code

