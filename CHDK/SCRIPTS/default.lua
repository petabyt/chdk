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

-- supported languages, name must match CHDK language file name
langs={
	ENGLISH		={font_cp=2,hint="CHDK language changed to english"},
	GERMAN		={font_cp=2,hint="CHDK-Sprache auf deutsch geдndert"},
	FRENCH		={font_cp=2,hint="CHDK language changed to french"},
	DUTCH		={font_cp=2,hint="CHDK language changed to dutch"},
	ITALIAN		={font_cp=2,hint="CHDK language changed to italian"},
	UKRAINIAN	={font_cp=1,hint="Мову CHDK змінено на україньску"},
	INDONESIAN	={font_cp=2,hint="CHDK language changed to indonesian"},
	FINNISH		={font_cp=2,hint="CHDK language changed to finnish"},
	SPANISH		={font_cp=2,hint="CHDK language changed to spanish"},
	RUSSIAN		={font_cp=1,hint="Язык CHDK изменен на русский"},
	PORTUGUESE	={font_cp=2,hint="CHDK language changed to portuguese"},
	GREEK		={font_cp=3,hint="CHDK language changed to greek"},
	POLISH		={font_cp=0,hint="CHDK language changed to polish"},
	CZECH		={font_cp=0,hint="CHDK language changed to czech"},
	HUNGARIAN	={font_cp=0,hint="CHDK language changed to hungarian"},
	TURKISH		={font_cp=4,hint="CHDK language changed to turkish"},
	ROMANIAN	={font_cp=0,hint="CHDK language changed to romanian"},
	-- following 3 not seen in Canon firmware
	CROATIAN	={font_cp=0,hint="CHDK language changed to croatian"},
	-- cp 5 = win1257 unlike others doesn't match list digit of windows CP
	ESTONIAN	={font_cp=5,hint="CHDK language changed to estonian"},
	SLOVAK		={font_cp=0,hint="CHDK language changed to slovak"},
}

-- propcase id and value = language name for supported propsets
prop_langs={
	[1]={prop=196,[0]='ENGLISH',[1]='GERMAN',[2]='FRENCH',[3]='DUTCH',[5]='FINNISH',[6]='ITALIAN',[9]='SPANISH',[11]='RUSSIAN',[12]='PORTUGUESE',[13]='GREEK',[14]='POLISH',[15]='CZECH',[16]='HUNGARIAN',[17]='TURKISH',},
	[2]={prop=61, [0]='ENGLISH',[1]='GERMAN',[2]='FRENCH',[3]='DUTCH',[5]='FINNISH',[6]='ITALIAN',[8]='UKRAINIAN',[10]='SPANISH',[12]='RUSSIAN',[13]='PORTUGUESE',[14]='GREEK',[15]='POLISH',[16]='CZECH',[17]='HUNGARIAN',[18]='TURKISH',[23]='ROMANIAN'},
	-- 3-4 assumed to be the same as 2, IDs appear the same based on surrounding, values not tested
	[3]={prop=61, [0]='ENGLISH',[1]='GERMAN',[2]='FRENCH',[3]='DUTCH',[5]='FINNISH',[6]='ITALIAN',[8]='UKRAINIAN',[10]='SPANISH',[12]='RUSSIAN',[13]='PORTUGUESE',[14]='GREEK',[15]='POLISH',[16]='CZECH',[17]='HUNGARIAN',[18]='TURKISH',[23]='ROMANIAN'},
	[4]={prop=61, [0]='ENGLISH',[1]='GERMAN',[2]='FRENCH',[3]='DUTCH',[5]='FINNISH',[6]='ITALIAN',[8]='UKRAINIAN',[10]='SPANISH',[12]='RUSSIAN',[13]='PORTUGUESE',[14]='GREEK',[15]='POLISH',[16]='CZECH',[17]='HUNGARIAN',[18]='TURKISH',[23]='ROMANIAN'},
	-- 5, 6 identical, values changed from 2 (verified sx160, elph130)
	[5]={prop=61, [0]='ENGLISH',[1]='GERMAN',[2]='FRENCH',[3]='DUTCH',[5]='ITALIAN',[6]='UKRAINIAN',[8]='INDONESIAN',[10]='FINNISH',[13]='SPANISH',[15]='RUSSIAN',[16]='PORTUGUESE',[17]='GREEK',[18]='POLISH',[19]='CZECH',[20]='HUNGARIAN',[21]='TURKISH',[26]='ROMANIAN'},
	[6]={prop=61, [0]='ENGLISH',[1]='GERMAN',[2]='FRENCH',[3]='DUTCH',[5]='ITALIAN',[6]='UKRAINIAN',[8]='INDONESIAN',[10]='FINNISH',[13]='SPANISH',[15]='RUSSIAN',[16]='PORTUGUESE',[17]='GREEK',[18]='POLISH',[19]='CZECH',[20]='HUNGARIAN',[21]='TURKISH',[26]='ROMANIAN'},
	-- 7 id changed, values go by row rather than col (verified g7x)
	[7]={prop=66, [0]='ENGLISH',[2]='ROMANIAN',[3]='GERMAN',[5]='TURKISH',[6]='FRENCH',[7]='SPANISH',[9]='DUTCH',[10]='GREEK',[13]='RUSSIAN',[15]='PORTUGUESE',[16]='POLISH',[18]='FINNISH',[19]='CZECH',[21]='ITALIAN',[22]='HUNGARIAN',[24]='UKRAINIAN',[26]='INDONESIAN'},
	-- 8 untested, but 7 and 9 are identical
	[8]={prop=66, [0]='ENGLISH',[2]='ROMANIAN',[3]='GERMAN',[5]='TURKISH',[6]='FRENCH',[7]='SPANISH',[9]='DUTCH',[10]='GREEK',[13]='RUSSIAN',[15]='PORTUGUESE',[16]='POLISH',[18]='FINNISH',[19]='CZECH',[21]='ITALIAN',[22]='HUNGARIAN',[24]='UKRAINIAN',[26]='INDONESIAN'},
	[9]={prop=66, [0]='ENGLISH',[2]='ROMANIAN',[3]='GERMAN',[5]='TURKISH',[6]='FRENCH',[7]='SPANISH',[9]='DUTCH',[10]='GREEK',[13]='RUSSIAN',[15]='PORTUGUESE',[16]='POLISH',[18]='FINNISH',[19]='CZECH',[21]='ITALIAN',[22]='HUNGARIAN',[24]='UKRAINIAN',[26]='INDONESIAN'},
	-- 10 id changed, values not changed from 7
	[10]={prop=68, [0]='ENGLISH',[2]='ROMANIAN',[3]='GERMAN',[5]='TURKISH',[6]='FRENCH',[7]='SPANISH',[9]='DUTCH',[10]='GREEK',[13]='RUSSIAN',[15]='PORTUGUESE',[16]='POLISH',[18]='FINNISH',[19]='CZECH',[21]='ITALIAN',[22]='HUNGARIAN',[24]='UKRAINIAN',[26]='INDONESIAN'},
	-- 11 id changed, values not changed
	[11]={prop=69, [0]='ENGLISH',[2]='ROMANIAN',[3]='GERMAN',[5]='TURKISH',[6]='FRENCH',[7]='SPANISH',[9]='DUTCH',[10]='GREEK',[13]='RUSSIAN',[15]='PORTUGUESE',[16]='POLISH',[18]='FINNISH',[19]='CZECH',[21]='ITALIAN',[22]='HUNGARIAN',[24]='UKRAINIAN',[26]='INDONESIAN'},
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
		lf=string.upper(lf)
		for k,v in pairs(langs) do
			if string.find(lf, k..".LNG")~=nil then
				return k
			end
			if string.len(k) > 8 then
				-- check for most likely 8.3 name
				local k2=string.sub(k,1,6)..'~1.LNG'
				if string.find(lf, k2)~=nil then
					return k
				end
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
		-- note assumes cam can handle long name (generally true)
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
