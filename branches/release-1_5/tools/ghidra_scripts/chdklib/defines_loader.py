# module to load simple defines from C header files
# 
# License: GPL
#
# Copyright 2020 reyalp (at) gmail.com
#
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# with CHDK. If not, see <http://www.gnu.org/licenses/>.

import os
import re

import chdklib.logutil

class DefinesData:
    """Class to load simple defines from C header files

    This is not a full C parser, it's just meant to scrape simple values
    like propsets and camera.h settings, doesn't handle conditionals etc
    """

    def __init__(self, filename=None, infofunc=None, warnfunc=None):
        if infofunc:
            self.infomsg = infofunc
        else:
            self.infomsg = chdklib.logutil.infomsg

        if warnfunc:
            self.warn = warnfunc
        else:
            self.warn = chdklib.logutil.warn

        self.data = {}
        if filename:
            self.load(filename)


    def process_line(self,line):
        # trim any trailing CR or LF for simplicity
        line = re.sub('\r?\n?$','',line)
        # if line ends with backslash, trim it and store
        if line[-1:] == '\\':
            self.partial_line = self.partial_line + line[:-1]
            return

        line = self.partial_line + line

        self.partial_line = ''
        # in a multiline comment?
        if self.in_comment:
            # check for end, trim it
            if re.match('[*]/',line):
                line = re.sub('.*?[*]/',' ',line)
                self.in_comment = False
            else:
                # not closed yet
                return

        line = re.sub('/[*].*?[*]/',' ',line)

        # note comment code doesn't respect quotes!!
        # remove complete C style comments
        line = re.sub('/[*].*?[*]/',' ',line)
        # remove C++ style comments (could be inside a C style comment, don't care)
        line = re.sub('//.*','',line)
        # unclosed C style comment, trim it
        if re.match('/[*]',line):
            line = re.sub('/[*].*','',line)
            self.in_comment = True

        # empty line
        if len(line) == 0:
            return

        # simple define or undef
        m = re.match('\s*#(define|undef)\s+([^\s]+)\s*$',line)
        if m:
            if m.group(1) == 'define':
                self.data[m.group(2)] = ''
            if m.group(1) == 'undef':
                self.data[m.group(2)] = None
            return

        # define foo bar
        m = re.match('\s*#define\s+([^\s]+)\s+([^\s].*?)\s*$',line)
        if m:
            self.data[m.group(1)] = m.group(2)

    def get(self,name,default=None):
        return self.data.get(name,default)

    def getInt(self,name,default=None):
        if name not in self.data:
            return default
        v = self.data[name]
        # undef'd == default?
        if v is None:
            return default
        if re.match('([+]-)?0x[0-9a-f]+$',v,re.I):
            return int(v,16)
        if re.match('([+]-)?0[0-7]+$',v):
            return int(v,8)
        if re.match('([+]-)?[0-9]+$',v):
            return int(v,10)
        return default

    def show(self):
        for name in self.data:
            self.infomsg(-1,'%s=[%s]\n'%(name,self.get(name)))
            
    def showInts(self):
        for name in self.data:
            v = self.getInt(name)
            if v is not None:
                s = '%10d 0x%08x'%(v,v)
            else:
                s = ' (NaN)'
            self.infomsg(-1,'%-33s=%s\n'%(name,s))

    def load(self,filename):
        self.partial_line = ''
        self.in_comment = False

        for line in open(filename):
            self.process_line(line)

        if self.in_comment:
            self.warn('unterminated comment')

class PropsetData:
    """Load the propset for the platform into dicts of name->id and id->name"""

    def __init__(self, filename, infofunc=None, warnfunc=None):
        self.propset = None
        if infofunc:
            self.infomsg = infofunc
        else:
            self.infomsg = chdklib.logutil.infomsg

        if warnfunc:
            self.warn = warnfunc
        else:
            self.warn = chdklib.logutil.warn

        if filename:
            self.load(filename)

    def load_propset(self,filename):
        self.ps_defs = DefinesData(filename,infofunc=self.infomsg,warnfunc=self.warn)
        for name in self.ps_defs.data:
            propid = self.ps_defs.getInt(name)
            if propid is not None:
                self.by_name[name] = propid
                self.by_id[propid] = name

    def load_platform_propset(self,filename):
        platform_defs = DefinesData(filename,infofunc=self.infomsg,warnfunc=self.warn)
        propset = platform_defs.getInt('CAM_PROPSET')
        if propset:
            propset_h = os.path.join(os.path.dirname(filename),'../../include/propset'+str(propset)+'.h')
            self.load_propset(propset_h)
            self.propset = propset
        else:
            raise ValueError('failed to get CAM_PROPSET')

    def load(self,filename):
        self.by_name = {}
        self.by_id = {}
        bn = os.path.basename(filename)
        if bn == 'platform_camera.h':
            self.load_platform_propset(filename)
        else:
            m = re.match('propset([1-9][0-9]+).h',bn)
            if m:
                self.propset = int(m.group(1))
                self.load_propset(filename)
            else:
                raise ValueError('expected platform.h or propsetN.h')
