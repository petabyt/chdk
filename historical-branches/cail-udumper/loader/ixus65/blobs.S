    .globl blob_copy_and_reset, blob_copy_and_reset_size
    .globl blob_chdk_core, blob_chdk_core_size
    .globl blob_udumper, blob_udumper_size


    .section .blob_copy_and_reset
blob_copy_and_reset_start:
    .incbin RESET_FILE
blob_copy_and_reset_end:



    .section .blob_chdk_core
blob_chdk_core_start:
    .incbin CORE_FILE
blob_chdk_core_end:


    .text
blob_chdk_core_size:
    .long blob_chdk_core_end - blob_chdk_core_start
blob_chdk_core:
    .long blob_chdk_core_start


blob_copy_and_reset_size:
    .long blob_copy_and_reset_end - blob_copy_and_reset_start
blob_copy_and_reset:
    .long blob_copy_and_reset_start




blob_udumper_start:
    .incbin UDUMPER_FILE
blob_udumper_end:

blob_udumper_size:
    .long blob_udumper_end - blob_udumper_start
blob_udumper:
    .long blob_udumper_start
