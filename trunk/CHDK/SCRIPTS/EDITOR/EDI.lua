--[[
@title EDI - text editor
@param n Newline (1=Windows 2=Unix)
@default n 1
@param y Editor height
@default y 14
@param x Editor width
@default x 40
--new file option doesn`t work yet
--@param a Write new file? [T=1/N=0]
--@default a 0
--]]
--[[
    Version:    2.3
    Author:     Pawel Tokarz aka Outslider
    License:    GPL 3+; see: http://www.gnu.org/licenses/gpl-3.0.html
                in order to use with GPL<3: You can also use it with GPL<3 software.
    
    Changelog for 2.x series:
    - File browser is now merged with an editor

    More info you can find on CHDK Forum http://chdk.setepontos.com/index.php?topic=6465.0
    
    additionally: the biggest file I successfully opened on SX130IS had 916 kB. Opening 962 kB file failed. Other cameras has different size of free memory, nevertheless opening average scripts as 5-10 kb shouldn't cause any problems.
    
--]]

--require "filebrws"

--*****This part is simply taken from FILEBRWS.LUA script******--
function get_input()
    KEYS_TABLE={"left","up","right","down","set","shoot_half","shoot_full","menu","display","erase","zoom_in","zoom_out"}
    REPEATABLE_KEYS_TABLE={"left","up","right","down","zoom_out","zoom_in"}
    PRESSED_KEY=nil
    for key_nr=1, table.getn(REPEATABLE_KEYS_TABLE) do
        if is_pressed(REPEATABLE_KEYS_TABLE[key_nr]) then PRESSED_KEY=REPEATABLE_KEYS_TABLE[key_nr]
            end
        end
    if PRESSED_KEY~=nil then
        repeat
            if get_tick_count()-PRESSED_TIME>350 then sleep(100); return PRESSED_KEY end 
            until not is_pressed(PRESSED_KEY)
        end
    wait_click(60000)
    PRESSED_TIME=get_tick_count()
    for key_nr=1, table.getn(KEYS_TABLE) do
        if is_key(KEYS_TABLE[key_nr]) then PRESSED_KEY=KEYS_TABLE[key_nr]; return KEYS_TABLE[key_nr] end
        end
    end

function init_env()
    PATH={"A/"}
    set_console_layout(1,1,40,CONSOLE_HEIGHT)
    set_console_autoredraw(0)
    end
    
function pwd()
    out=""
    levels=table.getn(PATH)
    for li=1,levels do
        if li==1 then out=PATH[1] end
        if li==2 then out=out..PATH[2] end
        if li>2 then out=out.."/"..PATH[li] end
        end
    return out
    end

function is_dir(dir)
    stat=os.stat(dir)
    if stat~=nil then
        out=stat["is_dir"]
        end
    if stat==nil then
        out=false
        end
    return out
    end

function is_file(file)
    stat=os.stat(file)
    out=stat["is_file"]
    return out
    end
    
function file_mtime(file)
    stat=os.stat(file)
    out=stat["mtime"]
    return out
    end

function file_size(file,string)
    stat=os.stat(file)
    out=stat["size"]
    if string=="h" then
        if out<=1024 then out={out,"B"}
        elseif out>1024 and out<=1024*1024 then out={out/1024,"kB"}
        elseif out>1024*1024 and out<=1024*1024*1024 then out={out/1024/1024,"MB"}
        elseif out>1024*1024*1024 then out={out/1024/1024/1024,"GB"} end
        end
    return out
    end

function cd(dir)
        old_path={}
        for li=1,table.getn(PATH) do old_path[li]=PATH[li] end
        if dir==".." then PATH[table.getn(PATH)]=nil
        elseif dir~="." then PATH[table.getn(PATH)+1]=dir
            end
        print("old_path: ",old_path[table.getn(old_path)])
        if is_dir(pwd())==false then print("cd failed"); PATH={}; for li=1,table.getn(old_path) do PATH[li]=old_path[li] end; return false end
    end

function ls(dir)
    if is_dir(dir) then
        out=os.listdir(dir, true)
        end
    return out
    end

function mk_bar(text,width)
    return(string.sub(string.sub("------------------------ ",26-(width-string.len(text))/2,25)..text..string.sub(" ------------------------",1,(width-string.len(text))/2),1,width-1))
    end

function browser(height)
    DEBBUG=""   --For additional parameters displayed in STATBAR
    CONSOLE_HEIGHT=height
    if CONSOLE_HEIGHT<5 then CONSOLE_HEIGHT=5 end
    init_env()
    browser_pos=1
    shift=0
    ls_dir=ls(pwd())
    first_file_nr=1
    TOPBAR="Select a file"
    STATBAR=pwd()..DEBBUG
    repeat
        STATBAR=pwd()..DEBBUG
        if browser_pos>table.getn(ls_dir) then browser_pos=first_file_nr end
        if browser_pos<first_file_nr then browser_pos=table.getn(ls_dir) end
        if browser_pos>CONSOLE_HEIGHT-4+shift then shift=browser_pos-CONSOLE_HEIGHT+4 end
        if browser_pos<=shift then shift=browser_pos-1 end
        --[[ commented since causes problems
        if ls_dir[1]=="." and browser_pos==1 and shift==0 then
            browser_pos=2
            shift=1
            end
        -]]
        print(mk_bar(TOPBAR,40))
        for line=1, CONSOLE_HEIGHT-3 do
            if ls_dir[line+shift]==nil then print("")
                else
                if table.getn(PATH)==1 then file=pwd()..ls_dir[line+shift] else file=pwd().."/"..ls_dir[line+shift] end
                if is_dir(file) then append="/"; file_descr="< Dir > " end
                if is_file(file) then append=""; size=file_size(file, "h"); file_descr=string.sub("   ",string.len(size[1]),3)..size[1].." "..size[2]..string.sub("  ",string.len(size[2]),2) end
                name=ls_dir[line+shift]..append
                if browser_pos~=line+shift then print("\6 "..name..string.sub("            \6 ",string.len(name),14)..file_descr.."\6") end
                if browser_pos==line+shift then print("\4 "..name..string.sub("\183\183\183\183\183\183\183\183\183\183\183\183\17 ",string.len(name),14)..file_descr.."\6") end
                end
            end
        print(mk_bar(STATBAR,40))
        input=get_input()
        if input=="up" then browser_pos=browser_pos-1 end
        if input=="down" then browser_pos=browser_pos+1 end
        if input=="set" then
            if table.getn(PATH)==1 then selected_file=pwd()..ls_dir[browser_pos] else selected_file=pwd().."/"..ls_dir[browser_pos] end
            if is_dir(selected_file) then
                cd(ls_dir[browser_pos])
                ls_dir=ls(pwd())
                if table.getn(PATH)==1 then first_file_nr=1 else first_file_nr=2 end
                browser_pos=first_file_nr
                shift=0
                STATBAR=pwd()..DEBBUG
                end
            if is_file(selected_file) then
                return selected_file
                end
            end
        until false
    end

--*****The end of the file browser******--



if y<5 then y=5 end
if x<10 then x=10 end
--maximal x and y belong to the user

CONSOLE_HEIGHT=y
CONSOLE_WIDTH=x
set_console_layout(1,1,CONSOLE_WIDTH,CONSOLE_HEIGHT)
EXIT=false
SAVED='S'           --is file saved?
MODE="MOVE"
WRITE_SUBMODE=1
JUMPS={1,4,10,20}
JUMP=1
POS_X=0
POS_Y=1
SHIFT_Y=0
SHIFT_X=0
LETTER_NR=1
WRITE_KEY=0
EDI_VERSION="2.3"

--button configuration doesn't work
FILE_MENU_BUTTON="menu"
INSERT_MENU_BUTTON="display"
CHANGE_SUBMODE_BUTTON="shoot_half"

KEYMAP={{{"a","b","c","d","e","f"},{"g","h","i","j","k","l"},{"m","n","o","p","q","r","s"},{"t","u","v","w","x","y","z"}},{{"A","B","C","D","E","F"},{"G","H","I","J","K","L"},{"M","N","O","P","Q","R","S"},{"T","U","V","W","X","Y","Z"}},{{"1","2","3"},{"4","5","6"},{"7","8","9"},{"0","+","-","*","/","="}}}
ERASE_AS_SPACE={true,false,true} --when ERASE_AS_SPACE[WRITE_SUBMODE]==true then ERASE works as a space, otherwise - as a backspace.
INSERT_MAP={{"newline"},{"(",")","[","]","{","}"},{"<",">",",","'",":",";"},{"_","+","-","/","\\","="},{"@","!","?","#","\"","."},{"~","&","*","|","^","`"},{"ASCII code"}}
FUNCTION_MAP={{"print","shoot"},{"is_key","if"},{"then","end"},{"sleep","wait_click"},{"function","@title"},{"@param","@default"}}
FILE_MENU={{"Save"},{"Save and exit"},{"Exit (no save!)"},{"Clear whole file"},{"About EDI"}}
TOPBAR="EDI - Text editor"
STATUSBAR="statbar"

if n>2 then
    print("Newline setting incorrect")
    print("Using Unix style [\\n]")
    print("Press any key...")
    wait_click(60000)
    n=2
    end
if n<1 then
    print("Newline setting incorrect")
    print("Using Windows style [\\r\\n]")
    print("Press any key...")
    wait_click(60000)
    n=1
    end

if n==1 then CR="\r" end
if n==2 then CR="" end

file=browser(CONSOLE_HEIGHT)
if not is_file(file) then EXIT=true end

FILENAME=""

for li=0,string.len(file) do
    char=string.sub(file,string.len(file)-li,string.len(file)-li)
    if char~="/" then
        FILENAME=char..FILENAME
        else break
        end
    end

--since file browser could set console layout other, than we like:
set_console_layout(1,1,CONSOLE_WIDTH,CONSOLE_HEIGHT)

--lets try to load this file--
file_h=io.open(file,"r")
print("take file content by lines")
FILE_CONTENT={}
line=1
repeat
    FILE_CONTENT[line]=file_h:read("*line")
    FILE_LINESN=line-1
    line=line+1
    until FILE_CONTENT[line-1]==nil
file_h:close()    
print(FILE_LINESN)

function edi_draw()
    if POS_Y>CONSOLE_HEIGHT-4+SHIFT_Y then SHIFT_Y=POS_Y-CONSOLE_HEIGHT+4 end
    if POS_Y<=SHIFT_Y then SHIFT_Y=POS_Y-1 end
    if POS_X>CONSOLE_WIDTH-4+SHIFT_X then SHIFT_X=POS_X-CONSOLE_WIDTH+4 end
    if POS_X<=SHIFT_X then SHIFT_X=POS_X end
    if SHIFT_X<0 then SHIFT_X=0 end
    if SHIFT_Y<0 then SHIFT_Y=0 end
    print(mk_bar(TOPBAR,CONSOLE_WIDTH))
    for line_nr=1, CONSOLE_HEIGHT-3 do
        if FILE_CONTENT[line_nr+SHIFT_Y]==nil then
            draw_line=""
        elseif line_nr+SHIFT_Y ~= POS_Y then
            draw_line=FILE_CONTENT[line_nr+SHIFT_Y]
        elseif line_nr+SHIFT_Y == POS_Y then
            draw_line=string.sub(FILE_CONTENT[line_nr+SHIFT_Y],1,POS_X).."\17"..string.sub(FILE_CONTENT[line_nr+SHIFT_Y],POS_X+1,string.len(FILE_CONTENT[line_nr+SHIFT_Y]))
            end
        draw_line=string.sub(draw_line,SHIFT_X,string.len(draw_line))
        if string.len(draw_line)>CONSOLE_WIDTH-2 then
            draw_line=string.sub(draw_line,1,CONSOLE_WIDTH-2).."\26"
            end
        print(draw_line)
        end
    print(mk_bar(STATUSBAR,CONSOLE_WIDTH))
    end

function edi_move()
    STATUSBAR="[MOVE]["..JUMPS[JUMP].."\18]["..POS_X..","..POS_Y.."]"
--    if string.len(file)<20 then filepath=file else filepath=string.sub(file,1,7).."."..string.sub(file,string.len(file)-12,string.len(file)) end
    TOPBAR="EDI \6 "..FILENAME.." ["..SAVED.."] "
    edi_draw()
    input=get_input()
    if input=="set" then MODE="WRITE" end
    if input=="up" then
        POS_Y=POS_Y-JUMPS[JUMP]
        if POS_Y<1 then POS_Y=table.getn(FILE_CONTENT) end
        if POS_X>string.len(FILE_CONTENT[POS_Y]) then POS_X=string.len(FILE_CONTENT[POS_Y]) end        
        end
    if input=="down" then
        POS_Y=POS_Y+JUMPS[JUMP]
        if POS_Y>FILE_LINESN then POS_Y=1 end
        if POS_X>string.len(FILE_CONTENT[POS_Y]) then POS_X=string.len(FILE_CONTENT[POS_Y]) end
        end
    if input=="left" then
        POS_X=POS_X-1
        if POS_X<0 and POS_Y>1 then POS_Y=POS_Y-1; POS_X=string.len(FILE_CONTENT[POS_Y])
        elseif POS_X<0 and POS_Y==1 then POS_Y=FILE_LINESN; POS_X=string.len(FILE_CONTENT[POS_Y]) end
        end
    if input=="right" then
        POS_X=POS_X+1
        if POS_X>string.len(FILE_CONTENT[POS_Y]) and POS_Y<FILE_LINESN then POS_Y=POS_Y+1; POS_X=0
        elseif POS_X>string.len(FILE_CONTENT[POS_Y]) and POS_Y>=FILE_LINESN then POS_Y=1; POS_X=0 end
        end
    if input=="zoom_in" then
        POS_X=POS_X+5
        if POS_X>string.len(FILE_CONTENT[POS_Y]) and POS_Y<FILE_LINESN then POS_Y=POS_Y+1; POS_X=0
        elseif POS_X>string.len(FILE_CONTENT[POS_Y]) and POS_Y>=FILE_LINESN then POS_Y=1; POS_X=0 end
        end
    if input=="zoom_out" then
        POS_X=POS_X-5
        if POS_X<0 and POS_Y>1 then POS_Y=POS_Y-1; POS_X=string.len(FILE_CONTENT[POS_Y])
        elseif POS_X<0 and POS_Y==1 then POS_Y=FILE_LINESN; POS_X=string.len(FILE_CONTENT[POS_Y]) end
        end
    if input=="shoot_half" then JUMP=JUMP+1 end
    if JUMP>table.getn(JUMPS) then JUMP=1 end
    if input=="menu" then
        todo=menu(FILE_MENU,CONSOLE_WIDTH,CONSOLE_HEIGHT,"File menu",16)
        if todo=="Save" then save() end
        if todo=="Save and exit" then save();exit() end
        if todo=="Exit (no save!)" then exit() end
        if todo=="Clear whole file" then clear() end
        if todo=="About EDI" then about() end
        end
    end

function edi_write()
    delete=0
    write_mode_descript=""
    for li=1,table.getn(KEYMAP[WRITE_SUBMODE]) do
        write_mode_descript=write_mode_descript.."\6"
        for xi=1,table.getn(KEYMAP[WRITE_SUBMODE][li]) do
            write_mode_descript=write_mode_descript..KEYMAP[WRITE_SUBMODE][li][xi]
            end
        end
    write_mode_descript=write_mode_descript.."\6"
    STATUSBAR=write_mode_descript
    TOPBAR="EDI - Text editor - ["..SAVED.."]"
    insertion=""
    edi_draw()
    input=get_input()
    if input=="shoot_half" then
        WRITE_SUBMODE=WRITE_SUBMODE+1
        WRITE_KEY=0
        if WRITE_SUBMODE>table.getn(KEYMAP) then WRITE_SUBMODE=1 end
        end
    if input=="left" and WRITE_KEY==1 then LETTER_NR=LETTER_NR+1; delete=1; SAVED="!"
        elseif input=="left" and WRITE_KEY~=1 then LETTER_NR=1; WRITE_KEY=1; SAVED="!"
        elseif input=="up" and WRITE_KEY==2 then LETTER_NR=LETTER_NR+1; delete=1; SAVED="!"
        elseif input=="up" and WRITE_KEY~=2 then LETTER_NR=1; WRITE_KEY=2; SAVED="!"
        elseif input=="right" and WRITE_KEY==3 then LETTER_NR=LETTER_NR+1; delete=1; SAVED="!"
        elseif input=="right" and WRITE_KEY~=3 then LETTER_NR=1; WRITE_KEY=3; SAVED="!"
        elseif input=="down" and WRITE_KEY==4 then LETTER_NR=LETTER_NR+1; delete=1; SAVED="!"
        elseif input=="down" and WRITE_KEY~=4 then LETTER_NR=1; WRITE_KEY=4; SAVED="!"
        end
    if input=="zoom_in" or (input=="erase" and ERASE_AS_SPACE[WRITE_SUBMODE]==true) then WRITE_KEY=0; insertion=" "; SAVED="!" end
    if input=="zoom_out" or(input=="erase" and ERASE_AS_SPACE[WRITE_SUBMODE]~=true) then
        SAVED="!"
        if POS_X>0 then
            WRITE_KEY=0; delete=1
        elseif POS_X==0 and POS_Y>1 then
            POS_X=string.len(FILE_CONTENT[POS_Y-1])
            FILE_CONTENT[POS_Y-1]=FILE_CONTENT[POS_Y-1]..FILE_CONTENT[POS_Y]
            POS_Y=POS_Y-1
            for line=POS_Y+1,table.getn(FILE_CONTENT)-1 do
                FILE_CONTENT[line]=FILE_CONTENT[line+1]
                end
            FILE_CONTENT[FILE_LINESN]=nil
            FILE_LINESN=FILE_LINESN-1
            end
        end
    if WRITE_KEY~=0 and LETTER_NR~=0 then
        if LETTER_NR>table.getn(KEYMAP[WRITE_SUBMODE][WRITE_KEY]) then LETTER_NR=1 end
        insertion=KEYMAP[WRITE_SUBMODE][WRITE_KEY][LETTER_NR]
        SAVED="!"
        end
    if input=="set" and WRITE_KEY==0 then MODE="MOVE"
        elseif input=="set" and WRITE_KEY~=0 then WRITE_KEY=0; insertion=""
        end
    if input=="display" then
        WRITE_KEY=0; insertion=""; SAVED="!"
        insertion=menu(INSERT_MAP,CONSOLE_WIDTH,CONSOLE_HEIGHT,"Insert a special char")
        if insertion==nil then insertion=menu(FUNCTION_MAP,CONSOLE_WIDTH,CONSOLE_HEIGHT,"Insert a function",10) end
        if insertion==nil then insertion=""; SAVED="S" end
        if insertion=="newline" then
            insertion=""
            delete=0
            SAVED="!"
            for unline=0, FILE_LINESN-POS_Y+1 do
                FILE_CONTENT[FILE_LINESN+1-unline]=FILE_CONTENT[FILE_LINESN-unline]
                end
            FILE_CONTENT[POS_Y]=string.sub(FILE_CONTENT[POS_Y+1],1,POS_X)..CR
            FILE_CONTENT[POS_Y+1]=string.sub(FILE_CONTENT[POS_Y+1],POS_X+1,string.len(FILE_CONTENT[POS_Y+1]))
            POS_X=0;POS_Y=POS_Y+1;FILE_LINESN=FILE_LINESN+1
            end        
        if insertion=="ASCII code" then insertion=insert_ascii() end
        end
    if input=="menu" then
        WRITE_KEY=0; insertion=""
        todo=menu(FILE_MENU,CONSOLE_WIDTH,CONSOLE_HEIGHT,"File menu")
        if todo=="Save" then save() end
        if todo=="Save and exit" then save();exit() end
        if todo=="Exit (no save!)" then exit() end
        if todo=="Clear whole file" then clear() end
        if todo=="About EDI" then about() end
        end
    FILE_CONTENT[POS_Y]=string.sub(FILE_CONTENT[POS_Y],1,POS_X-delete)..insertion..string.sub(FILE_CONTENT[POS_Y],POS_X+1,string.len(FILE_CONTENT[POS_Y]))
    POS_X=POS_X+string.len(insertion)-delete
    end

function insert_ascii()
    exit_loop=false
    code={0,0,0}
    pos=1
    mass="-"
    repeat
        print();print()
        print(mk_bar("Insert char by ASCII",CONSOLE_WIDTH))
        print();print()
        if pos==1 then code_string="\4"..code[1].." "..code[2].." "..code[3] end
        if pos==2 then code_string=" "..code[1].."\4"..code[2].." "..code[3] end
        if pos==3 then code_string=" "..code[1].." "..code[2].."\4"..code[3] end
        print("       Set ASCII code: "..code_string)
        print();print()
        print(mk_bar(mass,CONSOLE_WIDTH))
        for li=11, CONSOLE_HEIGHT do
            print()
            end
        input=get_input()
        if input=="right" then pos=pos+1 end
        if input=="left" then pos=pos-1 end
        if pos>3 then pos=1 end
        if pos<1 then pos=3 end
        if input=="up" then code[pos]=code[pos]+1 end
        if input=="down" then code[pos]=code[pos]-1 end
        if code[pos]>9 then code[pos]=0 end
        if code[pos]<0 then code[pos]=9 end
        ascii=code[1]*100+code[2]*10+code[3]
        --code 0 is legal, but this char makes all the chars after \0 invisible, so it's probably useless; this is just to avoid confusion.
        if ascii<256 and ascii>0 then mass="character: "..string.char(ascii) else mass="bad value" end
        if input=="set" then
            if ascii>255 or ascii<1 then mass="ASCII code must be in range 1-255!"
                else
                return string.char(ascii)
                end
            end
        until exit_loop==true
    end

function menu(tab,width,height,header,item_width)
    set_console_autoredraw(0)
    menu_pos_y=1
    menu_pos_x=1
    menu_shift=0
    exit_menu=false
    if header==nil then header="SELECT ITEM" end
    if height==nil then print("NO HEIGHT GIVEN!");sleep(3000);return false end
    if width==nil then print("NO WIDTH GIVEN!");sleep(3000);return false end
    repeat
        if menu_pos_x<1 and menu_pos_y>1 then menu_pos_y=menu_pos_y-1;menu_pos_x=table.getn(tab[menu_pos_y]) end
        if menu_pos_x<1 and menu_pos_y<=1 then menu_pos_y=table.getn(tab);menu_pos_x=table.getn(tab[menu_pos_y]) end
        if menu_pos_y<1 then menu_pos_y=table.getn(tab) end
        if menu_pos_y>table.getn(tab) then menu_pos_y=1 end
        if menu_pos_x>table.getn(tab[menu_pos_y]) and menu_pos_y<table.getn(tab) then menu_pos_y=menu_pos_y+1;menu_pos_x=1 end
        if menu_pos_x>table.getn(tab[menu_pos_y]) and menu_pos_y>=table.getn(tab) then menu_pos_y=1; menu_pos_x=1 end
        if menu_pos_y>height-4+menu_shift then menu_shift=menu_pos_y-height+4 end
        if menu_pos_y<=menu_shift then menu_shift=menu_pos_y-1 end
        print(mk_bar(header,width))
        for line=1,height-3 do
            if tab[line+menu_shift]==nil then
                draw_line=""
            elseif line+menu_shift==menu_pos_y then
                draw_line=""
                for place=1, table.getn(tab[line+menu_shift]) do
                    item=tab[line+menu_shift][place]
                    if item_width~=nil then item=item..string.sub("                         ",1,item_width-string.len(item)) end
                    if menu_pos_x~=place then draw_line=draw_line.." "..item.." " end
                    if menu_pos_x==place then draw_line=draw_line.."\16"..item.."\17" end
                    end
            elseif line+menu_shift~=menu_pos_y then
                draw_line=""
                for place=1, table.getn(tab[line+menu_shift]) do
                    item=tab[line+menu_shift][place]
                    if item_width~=nil then item=item..string.sub("                         ",1,item_width-string.len(item)) end
                    draw_line=draw_line.." "..item.." "
                    end
                end
            print(draw_line)
            end
        print(mk_bar("SELECT-["..menu_pos_x..","..menu_pos_y.."]",width))
        input=get_input()
        if input=="up" then menu_pos_y=menu_pos_y-1 end
        if input=="down" then menu_pos_y=menu_pos_y+1 end
        if input=="left" then menu_pos_x=menu_pos_x-1 end
        if input=="right" then menu_pos_x=menu_pos_x+1 end
        if input=="set" then exit_menu=true; return tab[menu_pos_y][menu_pos_x] end
        if input=="display" or input=="menu" then exit_menu=true; return nil end
        until exit_menu==true
    end

function save()
    cls()
    console_redraw()
    print(mk_bar("Saving procedure...",CONSOLE_WIDTH))
    print("--make a backup...")
    backup_file=file..".BAK"
    print("  *backup:",backup_file)
    print("--open files")
    file_h=io.open(file,"r")
    backup_file_h=io.open(backup_file,"w")
    if (not file_h or not backup_file_h) then
        print("Error opening files")
        sleep(3000)
        return
        end
    for file_line in file_h:lines() do
        backup_file_h:write(file_line)
        backup_file_h:write("\n")
        end
    file_h:close()
    backup_file_h:close()
    print("--backup done")
    print()
    print("--saving file")    
    file_h=io.open(file,"w")
    if (not file_h) then
        print("Error opening files")
        return
        end
    for line_no,file_line in ipairs(FILE_CONTENT) do
        file_h:write(file_line)
        file_h:write("\n")
        end
    file_h:close()
    SAVED="S"
    print("The file has been saved")
    sleep(2000)
    end
    
function exit()
    cls()
    print("EDI has been terminated.")
    set_console_autoredraw(1)
    set_console_layout(1,1,26,6) -- not sure if these are good values
    EXIT=true
    end
    
function clear()
    ans=menu({{"NO","YES"}},CONSOLE_WIDTH,CONSOLE_HEIGHT,"Are you sure?",5)
    if ans=="YES" then FILE_CONTENT={""}; FILE_LINESN=1; POS_X=0; POS_Y=1; SAVED="!" end
    end
    
function about()
    cls()
    print("   ")
    print("   ")
    print(mk_bar("ABOUT EDI",CONSOLE_WIDTH))
    print("   ")
    print("   EDI - simple text editor")
    print("         for CHDK project")
    print("   ")
    print("   Version:     "..EDI_VERSION)
    print("   Author:      Pawel Tokarz")
    print("   Suggestions: waterwingz,")
    print("                truhli_fredy")
    print("   ")
    print("   More info in README.TXT file")
    print("")
    print(mk_bar("PRESS MENU",CONSOLE_WIDTH))
    for line=1,CONSOLE_HEIGHT-17 do print("") end
    exit_about=false
    repeat
        input=get_input()
        if input=="menu" then exit_about=true end
        until(exit_about==true)
--    ans=menu({{"OK"}},CONSOLE_WIDTH,CONSOLE_HEIGHT-5,"EDI - version: "..EDI_VERSION,5)
--    if ans=="YES" then FILE_CONTENT={""}; FILE_LINESN=1; POS_X=0; POS_Y=1; SAVED="!" end
    end
    

function main_loop()
    insertion=""
    repeat
        if MODE=="MOVE" then edi_move() end
        if MODE=="WRITE" then edi_write() end
        until EXIT==true
    end
    
set_console_autoredraw(0)
main_loop()

