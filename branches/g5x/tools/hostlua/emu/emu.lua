--[[
********************************
Licence: GPL
(c) 2009-2015 reyalp, rudi, msl, fbonomi
v 0.4
********************************

http://chdk.setepontos.com/index.php?topic=2929.0
based dummy.lua by fbonomi

Script to run CHDK lua scripts, emulating as much of the camera as required in lua
Should be used with lua from "hostlua" in the CHDK source tree
--]]
local usage_string=[[
usage: lua emu.lua <chdk_script> [-conf=<conf_script>] [-modroot=<cam module root>] [-a=X -b=Y ...]
    <chdk_script> is the script to be tested
    <conf_script> is a lua script customizing the test case
    <cam module root> is directory for emulated require to look for SCRIPTS and LUALIB
    -a=X etc set the corresponding script parameter to the given value
]]

-- global environment seen by chdk_script
local camera_env={
}
-- copy the global environment, before we add our own globals
for k,v in pairs(_G) do
    camera_env[k]=v;
end

-- table to track state used by emulated camera functions
-- global so it's accessible to camera funcs
camera_state={
    tick_count      = 0,                -- sleep, tick count
    exp_count       = 1000,             -- current image number (IMG_1000.JPG)
    image_dir       = "A/DCIM/100CANON",-- path of the recent image dir
    jpg_count       = 1000,             -- jpg image counter
    raw             = 0,                -- raw status
    raw_count       = 100,              -- raw image counter
    raw_nr          = 0,                -- noise reduction status (0 = Auto 1 = OFF, 2 = ON)
    mem             = {},               -- peek and poke
    av96            = 320,              -- F3.2
    bv96            = 388,              -- tv96+av96-sv96
    tv96            = 576,              -- 1/60s
    sv96            = 508,              -- ISO200
    iso_market      = 200,              -- Canon ISO value
    iso_mode        = 2,                -- number of ISO mode
    ev96            = 0,                -- exposure correction (APEX96)
    nd              = 0,                -- ND filter status
    disk_size       = 1024*1024*1024,   -- value in byte
    free_disk_space = 1000000,          -- value in byte
    propset         = 4,                -- propset 1 - 6
    rec             = true,             -- status of capture mode (false = play mode)
    vid             = false,            -- status of video mode
    mode            = 258,              -- P mode
    drive           = 0,                -- 0 = single 1 = continuous 2 = timer (on Digic 2) 3 = timer (on Digic 3,4,5)
    video_button    = true,             -- camera has extra video button
    movie_state     = 0,                -- 0 or 1 = movie recording is stopped or paused, 4 = recording, 5 or 6 = recording has stopped, writing movie to SD card
    flash           = 0,                -- 0 = flash auto, 1 = flash on, 2 = flash off
    coc             = 5,                -- coc x 1000
    focus           = 2000,             -- subject distance
    sd_over_modes   = 0x04,             -- 0x01 AutoFocus mode, 0x02  AFL active, 0x04  MF active
    f_mode          = 0,                -- focus mode, 0=auto, 1=MF, 3=inf., 4=macro, 5=supermacro
    focus_state     = 1,                -- focus ok = 1, not ok = 0, MF < 0
    focus_ok        = false,            -- can be true after release/click "shoot_half"
    zoom_steps      = 15,               -- maximum zoomsteps
    zoom            = 0,                -- zoom position
    IS_mode         = 0,                -- 0 = continuous, 1 or 2 = shoot only, 2 or 3 = panning, 3 or 4 = off
    user_av_id      = 1,                -- av id for Av and M mode
    user_tv_id      = 1,                -- tv id for Tv and M mode
    histo_range     = 100,              -- return value of a histogram range
    autostarted     = 0,                -- 0 = false, 1 = true 
    autostart       = 0,                -- autostart status (0 = off, 1 = on, 2 = once)
    alt_mode        = true,             -- alte mode status
    usb_sync        = false,            -- usb sync mode for mulitcam sync
    yield_count     = 25,               -- maximum number of lua VM instructions
    yield_ms        = 10,               -- maximum number of milliseconds
    props           = {},               -- propcase values
    title_line      = 1,                -- CHDK line 1 = on, 0 = off
    remote_timing   = 0,                -- value for high precision USB remote timing
    camera_os       = "dryos",          -- camera OS (vxworks or dryos)
    platformid      = 0xDEADBEEF,       -- platform ID of the camera
    battmax         = 3000,             -- maximum battery value
    battmin         = 2300,             -- minimum battery value
    screen_width    = 360,              -- LCD screen width (360 or 480 px)
    screen_height   = 240               -- LCD screen heigth
}


-- TODO not used
local buttons={"up", "down", "left", "right", "set", "shoot_half", "shoot_full", "shoot_full_only", "zoom_in", "zoom_out", "menu", "display"}

-- fill propertycases
for i=0, 400 do
    camera_state.props[i]=0
end

-- root to search for camera modules
local camera_module_root = 'A/CHDK'

camera_funcs=require'camera_funcs'

-- and tidy some things up
camera_env._G=camera_env
camera_env.arg=nil
camera_env.package = {
    loaded={}
}
-- mark stuff that would be loaded on cam as loaded
for i,k in ipairs({'string','debug','package','_G','io','table','math','coroutine','imath'}) do
    camera_env.package.loaded[k] = package.loaded[k]
end
-- make a version of require that runs the module in the camera environment
camera_env.require=function(mname)
    if camera_env.package.loaded[mname] then
        return camera_env.package.loaded[mname]
    end
    -- TODO CHDK now honors package.path, this only does defaults!
    local f=loadfile(camera_module_root..'/SCRIPTS/'..mname..'.lua')
    if not f then
        f=loadfile(camera_module_root..'/LUALIB/'..mname..'.lua')
    end
    if not f then
        error("camera module '"..tostring(mname).."' not found")
    end
    setfenv(f,camera_env)
    camera_env.package.loaded[mname]=f()
    return camera_env.package.loaded[mname]
end

--change to global
--local script_title

local chdk_version = {0, 0, 0, 0}

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
    version=function(line, line_num)
        local s=line:match("%s*@chdk_version%s*([%d%.]+)")
        if s then
            if table.concat(chdk_version, ".") ~= "0.0.0.0" then
                print("warning, extra @chdk_version line", line_num)
            else
                local cv = {}
                for v in string.gmatch(s, "%d+") do cv[#cv + 1] = tonumber(v) end
                if s:sub(1, 1) ~= "." and s:sub(-1) ~= "." and #cv > 1 and #cv <= 4 then
                    for i = 1, #cv do chdk_version[i] = cv[i] end
                    print("@chdk_version:", table.concat(chdk_version, "."))
                else
                    print("warning, wrong @chdk_version line", line_num)
                end
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
            print("@default",param_name,param_default)
            return true
        end
    end,
    hash_number=function(line, line_num)
        local var_name, var_default, text, val_range = line:match('^%s*#([%w_]+)=(%-?%d+)%s+"([^"]+)"%s+%[(%-?%d+%s+%-?%d+)%]')
        if val_range == nil then
            var_name, var_default, text = line:match('^%s*#([%w_]+)=(%-?%d+)%s+"([^"]+)"%s*$')
            val_range = "-65535 65535"
        end
        if var_name and var_default and val_range then
            local range = {}
            for val in string.gmatch(val_range, "%S+") do
                range[#range + 1] = tonumber(val)
            end
            var_default = tonumber(var_default)
            if range and #range == 2 then
                if range[1] > range[2] then range[1], range[2] = range[2], range[1] end
                if range[1] > var_default or range[2] < var_default then var_default = nil end
            end
            if var_default then
                if not script_params[var_name] then
                    script_params[var_name] = { default=var_default }
                    print(string.format("#number %s %d [%d %d]", var_name, var_default, range[1], range[2]))
                else
                    print("warning, double #parameter", var_name, var_default, "line", line_num)
                end
                return true
            else
                print("warning, default value for numbers not in range! line:", line_num)
            end
        end
    end,
    hash_long=function(line, line_num)
        local var_name, var_default, text = line:match('^%s*#([%w_]+)=(%d+)%s+"([^"]+)"%s+long')
        if var_name and var_default then
            var_default = tonumber(var_default)
            if var_default >= 0 or var_default < 10000000 then
                if not script_params[var_name] then
                    script_params[var_name] = { default=var_default }
                    print("#long  ",var_name,var_default)
               else
                    print("warning, double #parameter", var_name, var_default, "line", line_num)
                end
                return true
            else
                print("warning, wrong default value for long! line:", line_num)
            end
        end
    end,
    hash_bool=function(line, line_num)
        local var_name, var_default, text = line:match('^%s*#([%w_]+)=(%d+)%s+"([^"]+)"%s+bool')
        if var_name and var_default then
            var_default = tonumber(var_default)
            if var_default == 0 or var_default == 1 then
                if not script_params[var_name] then
                    script_params[var_name] = { default=var_default }
                    print("#bool  ", var_name, var_default)
                else
                    print("warning, double #parameter", var_name, var_default, "line", line_num)
                end
                return true
            else
                print("warning, wrong default value for bool! line:", line_num)
            end
        end
    end,
    hash_bool2=function(line, line_num)
        local var_name, var_default, text = line:match('^%s*#([%w_]+)=(true)%s+"([^"]+)"%s*$')
        if (var_name == nil) then
            var_name, var_default, text = line:match('^%s*#([%w_]+)=(false)%s+"([^"]+)"%s*$')
        end
        if var_name then
            if (var_default == 'false') or (var_default == 'true') then
                var_default = (var_default == 'true')
                if script_params[var_name] == nil then
                    script_params[var_name] = { default=var_default }
                    print("#bool  ", var_name, var_default)
                else
                    print("warning, double #parameter", var_name, var_default, "line", line_num)
                end
                return true
            else
                print("warning, wrong default value for bool! line:", line_num)
            end
        end
    end,
    hash_values=function(line, line_num)
        local var_name, var_default, text, val_range, val_ext = line:match('^%s*#([%w_]+)=(%-?%d+)%s+"([^"]+)"%s+{([%w%p%s]+)}%s*(%a*)')
        if var_name and var_default and val_range and val_ext then
            local values, lua_offset = {}, (val_ext == "table") and 0 or (#val_ext == 0) and 1 or nil
            for val in string.gmatch(val_range, "%S+") do
                if #val > 0 then values[#values + 1] = val end
            end
            var_default = tonumber(var_default)
            if lua_offset and #values > 0 and values[var_default + lua_offset] then
                if not script_params[var_name] then
                    if lua_offset == 0 then
                        values.index = var_default
                        values.value = values[var_default]
                        script_params[var_name] = { default = values }
                    else
                        script_params[var_name] = { default = var_default }
                    end
                    print(string.format("#values %s %d {%s} %s", var_name, var_default, table.concat(values," "), val_ext))
                else
                    print("warning, double #parameter", var_name, var_default, "line", line_num)
                end
                return true
            else
                print("warning, wrong default value for values! line:", line_num)
            end
        end
    end,
}

function parse_script_header(scriptname)
    local line_num
    line_num = 1
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
        if t.default ~= nil then
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
        if opt == "conf" then
            print("conf =",val)
            conf_script=val
        elseif opt == "modroot" then
            print("modroot =",val)
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
if conf_script then
    dofile(conf_script)
end

-- import the base camera functions, after conf so it can modify
for k,v in pairs(camera_funcs) do
    camera_env[k]=v
end

local chdk_script_f,err = loadfile(chdk_script_name)
if err then
    error("error loading " .. chdk_script_name .. " " .. err)
end
if chdk_version[1] == 1 and chdk_version[2] == 3 then
    print("load wrap13.lua")
    camera_env.require("wrap13")
end
setfenv (chdk_script_f, camera_env)
print("=== START =============================")
local status,result = pcall(chdk_script_f)
if not status then
    error("error running " .. chdk_script_name .. " " .. result)
end
