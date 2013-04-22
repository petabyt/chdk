--[[
********************************
Licence: GPL
(c) 2009-2012 reyalp, rudi, msl, fbonomi
v 0.1
********************************

http://chdk.setepontos.com/index.php?topic=2929.0
based dummy.lua by fbonomi

Script to run CHDK lua scripts, emulating as much of the camera as required in lua
Should be used with lua from "hostlua" in the CHDK source tree
--]]
local usage_string=[[
usage: lua emu.lua <chdk_script> [-conf=<conf_script>] [-a=X -b=Y ...]
    <chdk_script> is the script to be tested
    <conf_script> is a lua script customizing the test case
    -a=X etc set the corresponding script parameter to the given value
]]

-- global environment seen by chdk_script
local camera_env={
}
-- table to track state used by emulated camera functions
local camera_state={
    tick_count=0,               -- sleep, tick count
    image_counter=1000,         -- current image number (IMG_1000.JPG)
    raw=0,
    mem={},                     -- peek and poke
    av96=0,
    bv96=0,
    tv96=0,
    sv96=0,
    ev96=0,
    nd=0,
    disk_size=1024*1024*1024,
    propset=4,                  -- propset 1 - 5
    rec=false,
    vid=false,
    mode=1,
    drive=0,                    -- 0 = single 1 = continuous 2 = timer (on Digic 2) 3 = timer (on Digic 3,4,5)
    flash=0,                    -- 0 = flash auto, 1 = flash on, 2 = flash off
    focus=1000,
    f_mode=0,                   --focus mode, 0=auto, 1=MF, 3=inf., 4=macro, 5=supermacro
    zoom_steps=125,
    zoom=0,
    autostart=0,
    IS_mode=0,
}


local buttons={"up", "down", "left", "right", "set", "shoot_half", "shoot_full", "shoot_full_only", "zoom_in", "zoom_out", "menu", "display"}

-- fill propertycases
local props={}
for i=0, 400 do
    props[i]=0
end

-- root to search for camera modules
local camera_module_root = 'A/CHDK'

-- ***************START OF CAMERA FUNCTIONS*************************
local camera_funcs={ }

-- keys
function camera_funcs.shoot()
    if camera_state.raw > 0 then
        camera_state.tick_count = camera_state.tick_count + 3000
    else
        camera_state.tick_count = camera_state.tick_count + 1000
    end
    camera_state.image_counter = camera_state.image_counter + 1
end

function camera_funcs.press(s)
        print(">press<", s)
end

function camera_funcs.release(s)
        print(">release<", s)
        if s == "shoot_full" or s == "shoot_full_only" then
            camera_state.image_counter = camera_state.image_counter + 1
        end
end

function camera_funcs.click(s)
        print(">click<", s)
        if s == "shoot_full" or s == "shoot_full_only" then
            camera_state.image_counter = camera_state.image_counter + 1
        end
end

function camera_funcs.wheel_left()
        print(">wheel left<")
end

function camera_funcs.wheel_right()
        print(">wheel right<")
end

function camera_funcs.wait_click(n)
        print(">wait click<", n)
end

function camera_funcs.is_key()
        -- needs logic
end

function camera_funcs.is_pressed()
        -- needs logic
end

-- exposure
function camera_funcs.get_av96()
    return camera_state.av96
end

function camera_funcs.get_bv96()
    return camera_state.bv96
end

function camera_funcs.get_tv96()
    return camera_state.tv96
end

function camera_funcs.get_sv96()
    return camera_state.sv96
end

function camera_funcs.get_nd_present()
    return 0
end

function camera_funcs.set_nd_filter(n)
    camera_state.nd=n
end

function camera_funcs.get_ev()
    return camera_state.ev96
end

function camera_funcs.set_ev(n)
    camera_state.ev96=n
end

function camera_funcs.set_tv96_direct(n)
    camera_state.tv96=n
end

function camera_funcs.set_av96_direct(n)
    camera_state.av96=n
end

function camera_funcs.set_tv96(n)
    camera_state.tv96=n
end

function camera_funcs.set_av96(n)
    camera_state.av96=n
end

function camera_funcs.set_sv96(n)
    camera_state.sv96=n
end

function camera_funcs.get_iso_mode()
    return 0
end

function camera_funcs.get_iso_market()
    return 0
end

function camera_funcs.set_iso_mode(n)
    -- needs logic
end

function camera_funcs.set_iso_real(n)
    -- needs logic
end

-- raw
function camera_funcs.set_raw(n)
    if n == 0 or n == 1 then camera_state.raw = n end
end

function camera_funcs.get_raw()
    return camera_state.raw
end

function camera_funcs.get_raw_count()
    return 100
end

function camera_funcs.get_IS_mode()
    return camera_state.IS_mode
end


-- script status
function camera_funcs.sleep(n)
    camera_state.tick_count=camera_state.tick_count+n
end

function camera_funcs.get_tick_count()
    return camera_state.tick_count
end

function camera_funcs.autostarted()
    return camera_state.autostart
end

function camera_funcs.get_day_seconds()
    local H=os.date("%H")*60*60
    local M=os.date("%M")*60
    local S=os.date("%H")
    return H+M+S
end

function camera_funcs.get_time(c)
  if c=="D" then 
    return os.date("%d")
  elseif c=="M" then 
    return os.date("%m")
  elseif c=="Y" then 
    return os.date("%Y")
  elseif c=="h" then
    return os.date("%H")
  elseif c=="m" then
    return os.date("%M")
  elseif c=="s" then
    return os.date("%S")
  else 
    return 9999
  end
end

-- sd card
function camera_funcs.get_disk_size()
    return camera_state.disk_size
end

function camera_funcs.get_free_disk_space(n)
    return 1000000
end

-- text console
function camera_funcs.cls()
    print(">delete screen<")
end

function camera_funcs.print_screen(n)
    if n == 0 or n == false then
        print(">write log file off<")
    elseif n == -1000 then
        print(">write log file append<")
    else
        print(">write log file on<")
    end
end

function camera_funcs.set_console_layout(n, m, o, p)
    print(">change console layout<", n, m, o, p)
end

function camera_funcs.console_redraw()
    print(">redraw console<")
end

function camera_funcs.set_console_autoredraw(n)
    print(">redraw console<", n)
end

function camera_funcs.draw_string(col,row,msg,c1,c2)
    print("draw string @ " .. col..":"..row.." Colors:"..c1..":","Msg> "..msg)
end

-- lens & focus
function camera_funcs.get_focus()
    return camera_state.focus
end

function camera_funcs.set_focus(n)
    camera_state.focus=n
end

function camera_funcs.get_focus_mode()
    return camera_state.f_mode
end

function camera_funcs.get_dofinfo()
    return {
            hyp_valid = true,
            focus_valid = true,
            aperture = 2679,
            coc = 5,
            focal_length = 5800,
            eff_focal_length = 35000,
            focus = 200,
            near = 135,
            far = 3400,
            dof = 3400 - 135,
            hyp_dist = 2517,
            min_stack_dist = 100
    }
end

function camera_funcs.get_zoom_steps()
    return camera_state.zoom_steps
end

function camera_funcs.get_zoom()
    return camera_state.zoom
end

function camera_funcs.set_zoom(n)
    camera_state.zoom=n
end

function camera_funcs.set_aflock(n)
    if n == 1 then print(">aflock on<") end
    if n == 0 then print(">aflock off<") end
end

--camera
function camera_funcs.shutdown()
    print("shutdown camera ...")
end

function camera_funcs.get_propset()
    return camera_state.propset
end

function camera_funcs.get_prop(prop)
    return props[prop]
end

function camera_funcs.set_prop(prop, val)
    props[prop]=val
end

-- return 1 or 0, depending on system clock... a quick&dirty simulation for shooting process
function camera_funcs.get_shooting()
    if os.date("%S")%3 == 1 then 
        return true
    else
        return false
    end
end

function camera_funcs.get_temperature(n)
    return 40
end

function camera_funcs.peek(n)
    return 0
end

function camera_funcs.get_buildinfo()
    return {
            platform="PC",
            platsub="sub",
            version="PC Emulation CHDK",
            build_number="999",
            build_revision="5555";
            build_date=os.date("%x"),
            build_time=os.date("%X"),
            os="vxworks",
            platformid=0xDEADBEEF,
    }
end

function camera_funcs.get_vbatt()
    return 3000
end

function camera_funcs.get_jpg_count()
    return 1000
end

function camera_funcs.get_image_dir()
    return "A/DCIM/100CANON"
end

function camera_funcs.get_exp_count()
    return camera_state.image_counter
end

function camera_funcs.play_sound(n)
    print("beep", n)
end

function camera_funcs.set_led(n, s)
    if s == 1 then print("LED", n, "on") end
    if s == 0 then print("LED", n, "off") end
end

function camera_funcs.set_backlight(n)
    if n == 1 then print(">Backlight on<") end
    if n == 0 then print(">Backlight off<") end
end

function camera_funcs.get_mode()
    return camera_state.rec, camera_state.vid, camera_state.mode
end

function camera_funcs.set_record(n)
    if n == 1  or n == true then
        camera_state.rec = true
        print("record mode")
    elseif n == 0  or n == false then
        camera_state.rec = false
        print("play mode")
    end
end

function camera_funcs.get_drive_mode()
    return camera_state.drive
end

function camera_funcs.get_flash_mode()
    return camera_state.flash
end

-- motion detection
function camera_funcs.md_detect_motion()
    return 1
end

-- histogram
function camera_funcs.shot_histo_enable(s)
    local x=n
end

function camera_funcs.get_histo_range(n1,n2)
    return 100
end

-- ***************END OF CAMERA FUNCTIONS*************************

-- copy the global environment
for k,v in pairs(_G) do
    camera_env[k]=v;
end
-- import the base camera functions
for k,v in pairs(camera_funcs) do
    camera_env[k]=v;
end
-- and tidy some things up
camera_env._G=camera_env
camera_env.arg=nil
-- make a version of require that runs the module in the camera environment
camera_env.require=function(mname)
	-- TODO this shouldn't really use the global package table!
	if package.loaded[mname] then
		return package.loaded[mname]
	end
	local f=loadfile(camera_module_root..'/SCRIPTS/'..mname..'.lua')
	if not f then
		f=loadfile(camera_module_root..'/LUALIB/'..mname..'.lua')
	end
	if not f then
		error("camera module '"..tostring(mname).."' not found")
	end
	setfenv(f,camera_env)
	package.loaded[mname]=f()
	return package.loaded[mname]
end

local script_title

local script_params={
}

local header_item_funcs={
    title=function(line,line_num)
        local s=line:match("%s*@[Tt][Ii][Tt][Ll][Ee]%s*(.*)")
        if s then 
            if script_title then
                print("warning, extra @title line",line_num)
            else
                script_title = s
                print("title:",s)
            end
            return true
        end
    end,
    param=function(line,line_num)
        local param_name,param_desc=line:match("%s*@[Pp][Aa][Rr][Aa][Mm]%s*([A-Za-z])%s*(.*)")
        if param_name and param_desc then
            if not script_params[param_name] then
                script_params[param_name] = { desc=param_desc }
            elseif script_params[param_name].desc then
                print("warning, extra @param",param_name,"line",line_num)
            else
                script_params[param_name].desc = param_desc
            end
            print("param",param_name,param_desc)
            return true
        end
    end,
    default=function(line,line_num)
        local param_name,param_default=line:match("%s*@[Dd][Ee][Ff][Aa][Uu][Ll][Tt]%s*([A-Za-z])%s*([0-9]+)")
        if param_name and param_default then
            if not script_params[param_name] then
                script_params[param_name] = { default=param_default }
            elseif script_params[param_name].default then
                print("warning, extra @default",param_name,param_default,"line",line_num)
            else
                script_params[param_name].default = tonumber(param_default)
            end
            print("default",param_name,param_default)
            return true
        end
    end,
}

function parse_script_header(scriptname)
    local line_num
    line_num = 0
    for line in io.lines(scriptname) do 
        for k,f in pairs(header_item_funcs) do
            if f(line,line_num) then
                break
            end
        end
        line_num = line_num + 1
    end
    if not script_title then
        script_title="<no title>"
    end
    -- set the params to their default values
    for name,t in pairs(script_params) do
        if t.default then
            camera_env[name] = t.default
        else
            print("warning param",name,"missing default value")
            camera_env[name] = 0
        end
    end
end

function usage()
    error(usage_string,0)
end

chdk_script_name=arg[1]
if not chdk_script_name then
    usage()
end

parse_script_header(chdk_script_name)

local i=2
while arg[i] do
    local opt,val=arg[i]:match("-([%w_]+)=(.*)")
    if opt and val then
        opt=opt:lower()
        print(opt,"=",val)
		-- TODO this isn't actually implemented!
        if opt == "conf" then
            print("conf_script=",val)
            conf_script=val
        elseif opt == "modroot" then
            print("modroot",val)
            camera_module_root=val
        elseif opt:match("^%l$") then
            local n=tonumber(val)
            if n then
                print("param",opt,"=",val)
                camera_env[opt]=val
            else
                print("expected number for",opt,"not",val)
            end
        end
    else 
        print("bad arg",tostring(arg[i]))
    end
    i=i+1
end
local chdk_script_f,err = loadfile(chdk_script_name)
if err then
    error("error loading " .. chdk_script_name .. " " .. err)
end
setfenv (chdk_script_f, camera_env)
local status,result = pcall(chdk_script_f)
if not status then
    error("error running " .. chdk_script_name .. " " .. result)
end
