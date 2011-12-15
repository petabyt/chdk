/*
 */

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "flt.h"
#include "myio.h"

struct flat_hdr* flat;
unsigned char* flat_buf;
char* filename_elf="";
int FLAG_VERBOSE=0;
int FLAG_DUMP_FLAT=0;


void dump_section(char* name, unsigned char *ptr, int size )
{
    printf("\n\nDump %s",name);
    
    int i;
    for(i=0;i<size;i++)
    {
        if ((i % 16)==0 ) {printf("\n%06x:  ",i);}
        if ((i % 16)==8 ) {printf("| ");}
        printf("%02x ",ptr[i]);
    }
    printf("\n");
}

static 
void print_offs(char *prefix, int offs)
{
    int secoffs = 0;
    char* sect="unkn";
    
    if ( !offs ) {
        printf("%s 0x0\n",prefix);
        return;
    }
    
    if ( offs >=flat->entry && offs<flat->data_start )
       { sect="text"; secoffs=flat->entry;}
    else if  ( offs >=flat->data_start && offs<=flat->data_end )
       { sect="data"; secoffs=flat->data_start;}
    else if  ( offs >flat->data_end && offs<=flat->bss_end )
       { sect="bss"; secoffs=flat->data_end+1;}         
    printf("%s 0x%x (%s+0x%x)\n",prefix, offs,sect,offs-secoffs);
}

char* get_flat_string( int32_t offs )
{
   static char buf[200];

    if  ( offs <0 )
	{
		sprintf(buf," LANGID %d",-offs);
		return buf;
	}

    if  ( offs >flat->data_end || offs<=flat->data_start )
	  return "";

	strncpy( buf, flat_buf+offs, sizeof(buf)-1);
	buf[sizeof(buf)-1]=0;
	return buf;
}

int main(int argc, char **argv)
{

    if ( argc < 2 )
    {
        printf("fltdump.exe filename.flt [-f]\n  -f = dump content of FLAT sections\n");
        return 1;
    }
    
    if ( argc > 2 && argv[2][0]=='-' && argv[2][1]=='f' )
	  { FLAG_DUMP_FLAT=1;}

    char* filename_flt = argv[1];

    int rv;
    if ( (rv=b_file_preload(filename_flt)) <= 0 )
    {
        fprintf(stderr, "Error load file '%s': loaded %d\n",filename_flt,rv);
        return 1;
    }


	flat = (struct flat_hdr*) b_get_buf();
	flat_buf = b_get_buf();

    char magic[5];          // "CFLA"
	memcpy(magic,flat->magic,4);
	magic[4]=0;


	printf("\nFLT Headers:\n");
	printf("->magic        %s (flat rev.%d)\n", magic, flat->rev );

	if ( memcmp(magic,FLAT_MAGIC_NUMBER,4) ) {
		printf("This is not CHDK-FLAT!\n");
		return 1;
	}	

	if ( flat->rev != FLAT_VERSION )
	{
		printf("Bad FLAT revision! It is %d while should be %d\n", flat->rev, FLAT_VERSION);
	}

	printf("->entry(.text) 0x%x (size %d)\n", flat->entry, flat->data_start - flat->entry );
	printf("->data_start   0x%x (size %d)\n", flat->data_start,  flat->data_end - flat->data_start + 1 );
	printf("->data_end     0x%x\n", flat->data_end );
	printf("->bss_end      0x%x (size %d)\n", flat->bss_end, flat->bss_end - flat->data_end );
	printf("->reloc_start  0x%x (size %d)\n", flat->reloc_start, flat->reloc_count*4 );
	printf("->import_start 0x%x (size %d)\n", flat->import_start, flat->import_count*4 );

	print_offs("\n.._module_loader()   =", flat->_module_loader);
	print_offs(".._module_unloader() = ", flat->_module_unloader);
	print_offs(".._module_run()      = ", flat->_module_run);
	print_offs("..MODULE_EXPORT_LIST = ", flat->_module_exportlist);


	if ( flat->rev == FLAT_VERSION )
	{
		struct ModuleInfo* _module_info = (struct ModuleInfo*)(flat_buf + flat->_module_info);
		if ( _module_info->magicnum != MODULEINFO_V1_MAGICNUM ) 
		{
		  printf("Malformed module info - bad magicnum!\n");
		  return 1;
		}
		if ( _module_info->sizeof_struct != sizeof(struct ModuleInfo) ) 
		{
		  printf("Malformed module info - bad sizeof!\n");
		  return 1;
		}


		printf("\nModule info:\n");
		printf("->Module Name: %s\n", get_flat_string(_module_info->moduleName) );
		printf("->Module Ver: %d.%d\n", _module_info->major_ver, _module_info->minor_ver );
		
		char* branches_str[] = {"any branch","CHDK", "CHDK_DE", "CHDK_SDM", "PRIVATEBUILD"};
		int branch = (_module_info->chdk_required_branch>REQUIRE_CHDK_PRIVATEBUILD) ? 
							REQUIRE_CHDK_PRIVATEBUILD : _module_info->chdk_required_branch;
		printf("->Require: %s-build%d. ", branches_str[branch], _module_info->chdk_required_ver );
		if ( _module_info->chdk_required_platfid == 0 )
		  	printf("Any platform.\n");
		else
		  	printf(" Platform #%d only.\n", _module_info->chdk_required_platfid );
		if ( _module_info->flags ) {
			printf("->Flags:");
			if ( _module_info->flags & MODULEINFO_FLAG_SYSTEM )
				printf(" SYSTEM ");
		    printf("\n");
		}
		printf("->Module Info: %s\n", get_flat_string(_module_info->description) );
	}
		
		
	if ( !FLAG_DUMP_FLAT )
	  return 0;

    dump_section( "FLT_header", flat_buf, sizeof(struct flat_hdr) );
    dump_section( "FLT_text", flat_buf+flat->entry, flat->data_start-flat->entry );
    dump_section( "FLT_data", flat_buf+flat->data_start, flat->data_end-flat->data_start+1);
    dump_section( "FLT_bss",  flat_buf+flat->data_end+1, flat->bss_end-flat->data_end );

	int i;
    printf("\nDump relocations 0x%x:\n",flat->reloc_start);
    for( i = 0; i< flat->reloc_count; i++)
        print_offs("Offs: ",*(int*)(flat_buf+flat->reloc_start+i*4));

    printf("\nDump imports 0x%x:\n",flat->import_start);
    for( i = 0; i< flat->import_count; i++)
        print_offs("Offs: ",*(int*)(flat_buf+flat->import_start+i*4));

	return 0;

}


