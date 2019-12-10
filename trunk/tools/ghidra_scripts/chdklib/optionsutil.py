# module to handle loading / saving python style cfg file

# License: GPL
#
# Copyright 2019 reyalp (at) gmail.com
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


# options_spec defined like
# options_spec = [
#     {
#         'name':'clean_thumb_data',
#         'type':'bool',
#         'default':True,
#         'desc':"""\
# # Undefine data +1 from thumb func adr
# """,
#     },
#    ....
# ]
import os

# Unclear if / how Ghidra props file could be used instead
import ConfigParser

from chdklib.logutil import infomsgf, warnf

def write_options(secname,cfgfile,options_spec,options):
    # lets caller bypass
    if options['skip_create_config']:
        infomsgf(0,"Skip writing config file %s\n",cfgfile)
        return

    infomsgf(0,"Writing config file %s\n",cfgfile)
    try:
        fh = open(cfgfile,"w")
        fh.write('['+secname+']\n')
        for ospec in options_spec:
            k = ospec['name']
            fh.write('# {} {} default={}\n'.format(k,ospec['type'], ospec['default']))
            fh.write(ospec['desc'])
            # this is g_options, to allow merging. Should always have been initialized from defaults, at least
            fh.write('{}={}\n\n'.format(k,options[k]))
        fh.close()

    except IOError:
        warnf('saving default cfg failed')

# returns true if config is missiong sections / values,
# to flag for re-write
def load_options(secname,cfgfile,options_spec,options):
    # initialize with default values
    for ospec in options_spec:
        options[ospec['name']] = ospec['default']

    if not os.path.isfile(cfgfile):
        infomsgf(0,'Config not found %s\n',cfgfile)
        return True

    missing = False
    # lets caller bypass
    if options['skip_load_config']:
        infomsgf(0,'Skip load config %s\n',cfgfile)
    else:
        config = ConfigParser.ConfigParser()
        infomsgf(0,'Load config %s\n',cfgfile)
        config.read(cfgfile)
        if config.has_section(secname):
            for ospec in options_spec:
                k = ospec['name']
                if not config.has_option(secname,k):
                    missing = True
                    continue

                vt = ospec['type']
                if vt == 'bool':
                    options[k] = config.getboolean(secname,k)
                elif vt == 'int':
                    options[k] = config.getint(secname,k)
                elif vt == 'enum':
                    cv = config.get(secname,k)
                    if cv in ospec['vals']:
                        options[k] = cv
                    else:
                        warnf("unexpected cfg option %s %s",k,cv)
                else:
                    warnf("unexpected option desc %s",k)

        else:
            missing = True
    return missing

