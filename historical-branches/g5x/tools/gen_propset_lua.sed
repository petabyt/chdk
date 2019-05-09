1 i\
--[[\
GENERATED PROPCASE TABLE\
use propcase.lua instead\
--]]\
return {
/^[[:space:]]*#define\([[:space:]]*\)PROPCASE_/ { 
 s/^[[:space:]]*#define\([[:space:]]*\)PROPCASE_\([A-Z0-9_]*\)\([[:space:]]*\)\([0-9]*\)/  \2=\4,/;
 s/\/\//--/;
 p;
}
$ i\
}
