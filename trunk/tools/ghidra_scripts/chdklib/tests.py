# some tests for stuff that's too annoying to do adhoc
from __main__ import *

from chdklib.logutil import infomsg, warn

from chdklib.analyzeutil import (
    is_likely_before_push_insn,
    is_likely_after_pop_insn,
    is_likely_func_start,
    is_likely_tail_call,
    get_insn_ops_text,
    get_pinsn_at,
    get_tmode_reg_at
)

# for analyzeutil is_likely_before_push_insn
# address, expected result, tmode, mnemonic, [ ops ]
# mnemonic and ops not currently used, saved in case ghidra representation changes
before_push_g7x_100d_data=[
    ['fc0fdf5e', False, 1, 'lsl', ['r0', 'r4', '#0x12']],
    ['fc0fdf52', True, 1, 'mov', ['r0', '#0x0']],
    ['fc0fdf54', True, 1, 'movw', ['r2', '#0x25d']],
    ['fc0fdf58', True, 1, 'adr', ['r1', '[0xfc0fe078]']],
    ['fc0fdf82', False, 1, 'str', ['r3', '[sp,#0x0]']],
    ['fc1f69ac', False, 1, 'add.w', ['r6', 'r0', 'r4, lsl #0x4']],
    ['fc1f6afa', False, 1, 'add.w', ['r1', 'r10', 'r0, lsl #0x4']],
    ['fc0fdfac', False, 1, 'ldr', ['r0', '[r4,#0x4]']],
    ['fc0fe0dc', False, 1, 'ldrd', ['r0', 'r1', '[sp,#0x4]']],
    ['fc0fe242', True, 1, 'str', ['r1', '[r0,#0x14]']],
    ['fc0fe244', True, 1, 'ldr', ['r0', '[r0,#0x8]']],
    ['fc0fe246', True, 1, 'cmp', ['r0', '#0x0']],
    ['fc0fe334', True, 1, 'tst', ['r0', 'r1']],
    ['01106bc4', True, 0, 'orr', ['r1', 'r1', 'r3, lsl #0x10']],
    ['0110657c', True, 0, 'cpy', ['r2', 'r0']],
    ['01106574', False, 0, 'cpy', ['r5', 'r2']],
    ['011063ea', True, 1, 'ldrb.w', ['r3', '[r1,#0x4b]!']],
    ['011063ee', True, 1, 'add', ['r3', 'r3', '#0x1']],
    ['fc347532', True, 1, 'add.w', ['r0', 'r1', 'r0, lsl #0x2']],
    ['fc079d88', False, 1, 'ldr.w', ['r0', 'r0', 'r4', '0x2']],
    ['fc079e26', True, 1, 'bic', ['r0', 'r0', '#0x40000000']],
    ['fc079ec2', True, 1, 'ldr.w', ['r0', 'r2', 'r0', '0x2']],
    ['fc0cdb08', False, 1, 'mov', ['r0', 'r0']],
    ['fc0cdb08', False, 0, 'andeq', ['r0', 'r0', 'r0']],
]

before_push_a540_100b_data=[
    ['ffc02858', False, 0, 'str', ['r3', '[r2,r7,lsl #0x2]']],
    ['ffc0290c', True, 0, 'mov', ['r3', '#0x510']],
    ['ffc02a44', True, 0, 'bic', ['r1', 'r1', '#0x10000000']],
    ['ffc02a90', True, 0, 'ldr', ['r1', '[0xffc02aac]']],
    ['ffc02a94', True, 0, 'ldr', ['r3', '[r1,#0x0]']],
    ['ffc02ae0', False, 0, 'ldr', ['lr', '[sp],#0x4']],
    ['ffc030fc', False, 0, 'add', ['r4', 'r4', '#0xc0000000']],
    ['ffc03144', True, 0, 'add', ['r3', 'r3', '#0x400000']],
    ['ffc03c1c', False, 0, 'andeq', ['r0', 'r0', 'r0']],
    ['ffc080e8', True, 0, 'movs', ['r2', 'r3, lsl #0x10']],
    ['ffc0e588', False, 0, 'add', ['r5', 'r2', 'r3, lsl #0x2']],
    ['ffc0e990', True, 0, 'ldr', ['r2', '[r3,r0,lsl #0x4]']],
    ['ffc0e9a0', True, 0, 'orr', ['r2', 'r2', 'r1']],
    ['ffc0e9a4', True, 0, 'str', ['r2', '[r3,r0,lsl #0x4]']],
    ['ffc0fb80', False, 0, 'bic', ['r3', 'r3', 'r5']],
]

def do_before_push_list(l):
    for v in l:
        addr = toAddr(v[0])
        # insn = getInstructionAt(addr)
        # disassemble directly to force tmode, allow checking invalid
        insn = get_pinsn_at(addr,v[2])
        r = is_likely_before_push_insn(insn)
        if r != v[1]:
            warn('before_push fail %s %s != %s %s'%(addr,r,v[1],insn))

after_pop_g7x_100d_data=[
    ['fc0e4ca2', True, 1, 'mov', ['r0', '#0x0']],
    ['fc0e4ca4', True, 1, 'adr', ['r1', '[0xfc0e4ce4]']],
    ['fc0f7ddc', False, 1, 'sub.w', ['sp', 'sp', '#0x310']],
    ['fc0f7de4', False, 1, 'mov', ['r7', 'r1']],
    ['01109ebc', True, 0, 'cmp', ['r1', 'r0']],
]

after_pop_a540_100b_data=[
    ['ffe3f610', True, 0, 'mov', ['r3', 'r2']],
    ['ffe3f6ac', True, 0, 'str', ['r1', '[r0,#0x40]']],
    ['ffe3f6f0', False, 0, 'ldr', ['r1', '[r5,#0x40]']],
]

def do_after_pop_list(l):
    for v in l:
        addr = toAddr(v[0])
        # insn = getInstructionAt(addr)
        # disassemble directly to force tmode, allow checking invalid
        insn = get_pinsn_at(addr,v[2])
        r = is_likely_after_pop_insn(insn)
        if r != v[1]:
            warn('after_pop fail %s %s != %s %s'%(addr,r,v[1],insn))

# note, doesn't exercise options. Could store kwargs in list
likely_func_start_g7x_100d_data=[
    ['fc087b00', True],
    ['fc087b58', False],
    ['fc087b60', True],
    ['010e7126', True],
    ['fc0e743c', True],
]

likely_func_start_a540_100b_data=[
    ['ffc4520c', True],
    ['ffd453c8', True],
    ['ffd45454', True],
    ['ffd45590', False],
    ['ffd45610', True],
]

def do_likely_func_start_list(l):
    for v in l:
        addr = toAddr(v[0])
        r = is_likely_func_start(addr)
        if r != v[1]:
            warn('tail_call fail %s %s != %s'%(addr,r,v[1]))


likely_tail_call_g7x_100d_data=[
    ['fc0e29cc', True],
    ['fc0e29de', False],
    ['fc0e4ca6', True],
]

likely_tail_call_a540_100b_data=[
    ['ffed91ec', False],
    ['ffc02af8', True],
    ['ffc04678', True],
]


def do_likely_tail_call_list(l):
    for v in l:
        addr = toAddr(v[0])
        r = is_likely_tail_call(addr)
        if r != v[1]:
            warn('tail_call fail %s %s != %s'%(addr,r,v[1]))



# correct dump must be selected in ghidra
# > from chdklib.tests import test_g7x, test_a540
# > test_g7x()
def test_g7x():
    infomsg(0,'running g7x 100d tests\n')
    do_before_push_list(before_push_g7x_100d_data)
    do_after_pop_list(after_pop_g7x_100d_data)
    do_likely_func_start_list(likely_func_start_g7x_100d_data)
    do_likely_tail_call_list(likely_tail_call_g7x_100d_data)
    infomsg(0,'done\n')

def test_a540():
    infomsg(0,'running a540 100b tests\n')
    do_before_push_list(before_push_a540_100b_data)
    do_after_pop_list(after_pop_a540_100b_data)
    do_likely_func_start_list(likely_func_start_a540_100b_data)
    do_likely_tail_call_list(likely_tail_call_a540_100b_data)
    infomsg(0,'done\n')

# helper for interactive testing in console
# output suitable for table above
# force disassemble instead of using listing 't' for thumb, 'a' for arm, True for auto
# > from chdklib.tests import check_before_push_insn as cbpi
# > cbpi('ffdeadbe')
def check_before_push_insn(a,force=None):
    addr = toAddr(a)
    if force is None:
        insn = getInstructionAt(addr)
        tmode = get_tmode_reg_at(addr)
    else:
        if force == 't':
            tmode = 1
        elif force == 'a':
            tmode = 0
        else:
            tmode = get_tmode_reg_at(addr)
        insn = get_pinsn_at(addr,tmode)

    ops = get_insn_ops_text(insn)
    mne = insn.getMnemonicString()
    r = is_likely_before_push_insn(insn)
    rstr = "['%s', %s, %d, '%s', [%s]],"%(addr, r, tmode, mne, ', '.join(["'%s'"%format(x) for x in ops]))
    return rstr

# helper to check for func start seq
# > from chdklib.tests import check_func_start as cfs
# > cfs('ffdeadbe')
def check_func_start(a, **kwargs):
    addr = toAddr(a)
    r = is_likely_func_start(addr, **kwargs)
    return "['%s', %s],"%(addr,r)

# helper for interactive testing in console
# output suitable for table above
# > from chdklib.tests import check_after_pop_insn as capi
# > capi('ffdeadbe')
def check_after_pop_insn(a,force=None):
    addr = toAddr(a)
    insn = getInstructionAt(addr)
    tmode = get_tmode_reg_at(addr)

    ops = get_insn_ops_text(insn)
    mne = insn.getMnemonicString()
    r = is_likely_after_pop_insn(insn)
    rstr = "['%s', %s, %d, '%s', [%s]],"%(addr, r, tmode, mne, ', '.join(["'%s'"%format(x) for x in ops]))
    return rstr


# helper to check for tail call seq
def check_tail_call(a, **kwargs):
    addr = toAddr(a)
    r = is_likely_tail_call(addr, **kwargs)
    return "['%s', %s],"%(addr,r)

