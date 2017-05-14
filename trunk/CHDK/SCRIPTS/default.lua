--[[
@title Default Script
@chdk_version 1.3
when run, attempts to reset the CHDK language/codepage to match the camera selection, or build default
]]

bi=get_buildinfo()
if bi.version=="CHDK" then
	chdk_def_lang='ENGLISH'
else
	chdk_def_lang='GERMAN'
end

-- supported languages
langs={
	ENGLISH={font_cp=2,hint="CHDK language changed to english"},
	GERMAN ={font_cp=2,hint="CHDK-Sprache auf deutsch geändert"},
	RUSSIAN={font_cp=1,hint="CHDK language changed to russian"},
}
-- propcase id and value = language name for supported propsets
prop_langs={
	[1]={prop=196,[0]='ENGLISH',[1]='GERMAN',[11]='RUSSIAN'},
	[2]={prop=61, [0]='ENGLISH',[1]='GERMAN',[12]='RUSSIAN'},
	[3]={prop=61, [0]='ENGLISH',[1]='GERMAN',[12]='RUSSIAN'},-- 3-4 assumed to be the same as 2, IDs appear the same based on surrounding, values not tested
	[4]={prop=61, [0]='ENGLISH',[1]='GERMAN',[12]='RUSSIAN'},
	[5]={prop=61, [0]='ENGLISH',[1]='GERMAN',[15]='RUSSIAN'},-- 5, 6 russian value changed (verified sx160, elph130)
	[6]={prop=61, [0]='ENGLISH',[1]='GERMAN',[15]='RUSSIAN'},
	[7]={prop=66, [0]='ENGLISH',[3]='GERMAN',[13]='RUSSIAN'},-- 7 id changed, values go by row rather than col (verified g7x)
}

-- return camera language name, or nil
function get_cam_lang()
	local p=prop_langs[get_propset()]
	if not p then
		print('unsupported propset '..get_propset())
		return
	end
	local pv=get_prop(p.prop)/256
	local lang=p[pv]
	if not lang then
		print('unknown language '..get_propset() .. ':'..pv)
	end
	return lang

end

-- return chdk language name, or nil
function get_chdk_lang()
	local lf=get_config_value(64)
	if lf=="" then
		return chdk_def_lang
	else
		for k,v in pairs(langs) do
			if string.find(lf, k..".LNG")~=nil then
				return k
			end
		end
	end
end

function set_chdk_lang_default()
	set_config_value(64,"")
	set_config_value(65,langs[chdk_def_lang].font_cp)
	print(langs[chdk_def_lang].hint)
end
chdk_lang=get_chdk_lang()
cam_lang=get_cam_lang()

-- if CHDK language and camera language both unknown, reset CHDK to default 
-- matches behavior of original script, unclear if desirable
if not cam_lang and not chdk_lang then
	set_chdk_lang_default()
elseif cam_lang~=chdk_lang then
	if not chdk_lang or cam_lang==chdk_def_lang then
		set_chdk_lang_default()
	elseif langs[cam_lang]~=nil then
		if os.stat("A/CHDK/LANG/"..cam_lang..".LNG") then
			set_config_value(64,"A/CHDK/LANG/"..cam_lang..".LNG")
			set_config_value(65,langs[cam_lang].font_cp)
			print(langs[cam_lang].hint)
		else
			print(cam_lang..".LNG is missing")
		end
	end
elseif cam_lang then
	print(";)")
end
