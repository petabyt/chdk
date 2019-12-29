#Imports a chdk funcs_by_address.csv file
#@category CHDK
#@author reyalp, based on Ghidra/Features/Python/ghidra_scripts/ImportSymbolsScript.py

# for thumb "register" value
from java.math import BigInteger 
progCtx = currentProgram.getProgramContext()
tmodeReg = progCtx.getRegister("TMode")

f = askFile("Select funcs_by_address.csv", "open")

last_address = 0
for line in file(f.absolutePath):  # note, cannot use open(), since that is in GhidraScript
  pieces = line.split(',')
  addr_value = long(pieces[0], 16)
# drop thumb bit
  address = toAddr((addr_value)&0xfffffffe)
# funcs_by_address has duplicates, frequently foo, foo_FW, prefer foo
  if address != last_address:
    # may contain EOL chars
    func_name = pieces[1].rstrip()
    last_address = address
# cleanup buggy thumb stuff
#    removeSymbol(toAddr(long(pieces[0], 16)),func_name)
    print "creating symbol", func_name, "at address", address,"thumb",(addr_value&1)
# fails will create additional labels if another user-created label already exists, replaces auto-generated
    createLabel(address, func_name, True)
# if not disassembled, attempt to start disassembly
    if getInstructionAt(address) is None:
# if thumb, try to set default context reg
# had trouble with setValue throwing ContextChangeException for reasons that aren't clear
        try:
            if addr_value & 1 == 1:
                print "disassemble thumb"
                progCtx.setValue(tmodeReg,address,address,BigInteger("1"))
            else:
                print "disassemble arm"
                progCtx.setValue(tmodeReg,address,address,BigInteger("0"))
            disassemble(address)
        except ghidra.program.model.listing.ContextChangeException:
            print 'set tmode failed at',address

