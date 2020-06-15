#!/usr/bin/env python3

# This script generates checksums for use with the firmware_crc module
# use -h for command line syntax and usage

import os
import sys
import zlib
import io
import argparse

self_dir = os.path.dirname(os.path.abspath(__file__))
# make chdklib available with normal names
sys.path.append(os.path.join(self_dir,'ghidra_scripts'))

# to set verbosity
import chdklib.logutil
from chdklib.logutil import infomsg, warn
from chdklib.stubs_loader import StubsData

def crc32_file_chunk(fh,offset,size):
    fh.seek(offset)
    data=fh.read(size)
    return zlib.crc32(data)

def fwsums_main():
    argparser = argparse.ArgumentParser(description='''\
Generate crc32 checks of Canon firmware for the firmware_crc module (fwcrc.flt).
Output is a list of address, size, crc lines in hex.
Module is available from Miscellaneous Stuff -> Tools -> Checksum Canon firmware in the CHDK menu.
''',
    formatter_class=argparse.RawDescriptionHelpFormatter)
    argparser.add_argument('platform', help='CHDK platform name, like ixus130_elph140')
    argparser.add_argument('sub', help='Firmware sub name, like 100a')
    argparser.add_argument("-s", "--source",
        help="CHDK source root, default current tree", action='store',
        default=os.path.abspath(os.path.join(self_dir,'..')))
    argparser.add_argument("-d", "--dumps", help="CHDK dumps root, default PRIMARY_ROOT or source platform dir",action='store')
    argparser.add_argument("-o", "--out", help="Output file, default stdout",action='store')
    argparser.add_argument('-v','--verbose',help="Increase verbosity", action='count',default=0) 

    args = argparser.parse_args()

    chdklib.logutil.verbosity = args.verbose

    stubs_data = StubsData(warnfunc=warn) # only warnings, no info

    plat = args.platform
    platsub = args.sub
    chdk_root = args.source
    if args.dumps:
        dump_root = args.dumps
    else:
        dump_root = os.environ.get('PRIMARY_ROOT',os.path.join(chdk_root,'platform'))

    plat_dir = os.path.join(chdk_root,'platform',plat,'sub',platsub)
    dump_name = os.path.join(dump_root,plat,'sub',platsub,'PRIMARY.BIN')

    infomsg(1,'%s %s %s %s\n'%(plat,platsub,plat_dir,dump_name))

    if not os.path.isfile(dump_name):
        sys.stderr.write("ERROR: missing %s\n"%(dump_name))
        sys.exit(1)

    dump_size = os.path.getsize(dump_name)
    if dump_size == 0:
        sys.stderr.write("ERROR: zero byte dump %s\n"%(dump_name))
        sys.exit(1)

    stubs_entry_name = os.path.join(plat_dir,'stubs_entry.S')
    if not os.path.isfile(stubs_entry_name):
        sys.stderr.write("ERROR: missing %s\n"%(stubs_entry_name))
        sys.exit(1)


    stubs_data.load_stubs_s(stubs_entry_name,process_comments=True)
    stubs_data.guess_platform_vals()
    smisc = stubs_data.stubs_entry_misc
    check_blocks = []

    romcode_start = smisc.get('main_fw_start')
    # not default to get(), may be literal None
    if not romcode_start:
        romcode_start = smisc['ar_rom']['start_adr']

    rom_base = smisc['ar_rom']['start_adr']

    check_blocks.append({
        'name':'ROMCODE',
        'start_adr':romcode_start,
        'offset':romcode_start - rom_base,
        'size':smisc['main_fw_code_end'] - romcode_start + 1,
    })
    for ar_name in ('ar_ramcode','ar_btcmcode','ar_ramdata'):
        ar = smisc.get(ar_name)
        if not ar:
            continue

        check_blocks.append({
            'name':ar['name'],
            'start_adr':ar['src_adr'],
            'offset':ar['src_adr'] - rom_base,
            'size':ar['size'],
        })

    for ar in smisc['zico_blobs']:
        check_blocks.append({
            'name':ar['name'],
            'start_adr':ar['src_adr'],
            'offset':ar['src_adr'] - rom_base,
            'size':ar['size'],
        })

    dump_file = open(dump_name,'rb')
    total_size = 0
    infomsg(1,'%-8s %-10s %-10s %-7s %-10s\n'%('name','start_adr','offset','size','crc32'))
    for b in check_blocks:
        b['crc32'] = crc32_file_chunk(dump_file,b['offset'],b['size']) & 0xffffffff
        infomsg(1,'%-8s 0x%08x 0x%08x %7d 0x%08x\n'%(b['name'],b['start_adr'],b['offset'],b['size'],b['crc32']))
        total_size = total_size + b['size']

    dump_file.close()

    infomsg(1,"%d blocks %d bytes %d%%\n"%(len(check_blocks),total_size,100*total_size/dump_size))

    if args.out:
        outfile = open(args.out,'w', newline='\n')
    else:
        outfile = sys.stdout

    for b in check_blocks:
        outfile.write('%x %x %x\n'%(b['start_adr'],b['size'],b['crc32']))

    if args.out:
        outfile.close()


fwsums_main()
