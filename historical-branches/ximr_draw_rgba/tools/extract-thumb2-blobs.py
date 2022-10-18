#!/usr/bin/env python3

# Extract some other processors firmware blobs for digic6 and later,
# using stubs_entry.S to identify

# use -h for command line syntax and usage

import os
import sys
import io
import argparse

self_dir = os.path.dirname(os.path.abspath(__file__))
# make chdklib available with normal names
sys.path.append(os.path.join(self_dir,'ghidra_scripts'))

# to set verbosity
import chdklib.logutil
from chdklib.logutil import infomsg, warn
from chdklib.stubs_loader import StubsData

class BlobDumper:
    """Dumper of blobs"""
    def __init__(self,filepath):
        self.blocks=[]
        self.filepath = filepath
        self.filesize = os.path.getsize(filepath)
        self.total_size = 0

    def add_block(self,blk):
        b = blk.copy()
        if b['offset'] >= self.filesize:
            warn("block %s start outside file, ignored"%(b['name']))
            b['size']=0

        elif self.filesize - b['offset'] < b['size']:
            warn("block %s end outside file, truncated"%(b['name']))
            b['size'] = self.filesize - b['offset']

        self.total_size += b['size']
        self.blocks.append(b)


    def process_stubs(self,stubs_data):
        smisc = stubs_data.stubs_entry_misc

        rom_base = smisc['ar_rom']['start_adr']

        for ar in smisc['zico_blobs']:
            self.add_block({
                'name':ar['name'],
                'start_adr':ar['src_adr'],
                'offset':ar['src_adr'] - rom_base,
                'size':ar['size'],
            })

        for ar in smisc['omar_blobs']:
            self.add_block({
                'name':ar['name'],
                'start_adr':ar['src_adr'],
                'offset':ar['src_adr'] - rom_base,
                'size':ar['size'],
            })



def process_dump(dump_name,out_dir,stubs_data):
    if not os.path.isfile(dump_name):
        warn("missing %s"%(dump_name))
        return

    dumper = BlobDumper(dump_name)
    if dumper.filesize == 0:
        warn("zero size %s"%(dump_name))
        return

    dumper.process_stubs(stubs_data)

    with open(dump_name,'rb') as fh:
        for b in dumper.blocks:
            oname = os.path.join(out_dir,b['name']+'.bin')
            fh.seek(b['offset'])
            data = fh.read(b['size'])
            infomsg(0,'Write %s 0x%08x %s\n'%(oname,b['start_adr'],b['size']))
            with open(oname,'wb') as ofh:
                ofh.write(data)


def extract_thumb2_blobs_main():
    argparser = argparse.ArgumentParser(description='''\
Extract firmware blobs for cores other than the main CPU from
Digic 6 and later firmware, using CHDK stubs_entry.S info
''',
    formatter_class=argparse.RawDescriptionHelpFormatter)
    argparser.add_argument('platform', help='CHDK platform name, like g7x')
    argparser.add_argument('sub', help='Firmware sub name, like 100d')
    argparser.add_argument("-s", "--source",
        help="CHDK source root, default current tree", action='store',
        default=os.path.abspath(os.path.join(self_dir,'..')))
    argparser.add_argument("-d", "--dumps", help="CHDK dumps root, default PRIMARY_ROOT or source platform dir",action='store')
    argparser.add_argument("-o", "--out", help="Output directory, default dump directory",action='store')
    argparser.add_argument('-v','--verbose',help="Increase verbosity", action='count',default=0)
    argparser.add_argument("--dumpfile", help="specify dump file directly instead of inferring from platform/sub",action='store')

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

    stubsub = platsub

    stubplat = plat

    plat_dir = os.path.join(chdk_root,'platform',stubplat,'sub',stubsub)
    if args.dumpfile:
        dump_name = args.dumpfile
    else:
        dump_name = os.path.join(dump_root,plat,'sub',platsub,'PRIMARY.BIN')

    if args.out:
        out_dir = args.out
    else:
        out_dir = os.path.dirname(dump_name)
        if out_dir == '':
            out_dir = './'

    stubs_entry_name = os.path.join(plat_dir,'stubs_entry.S')

    infomsg(1,'Loading stubs %s %s %s\n'%(stubplat,stubsub,stubs_entry_name))

    if not os.path.isfile(stubs_entry_name):
        sys.stderr.write("ERROR: missing %s\n"%(stubs_entry_name))
        sys.exit(1)

    stubs_data.load_stubs_s(stubs_entry_name,process_comments=True)
    stubs_data.guess_platform_vals()

    process_dump(dump_name,out_dir,stubs_data)



extract_thumb2_blobs_main()
