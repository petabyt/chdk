local _get_raw = get_raw; function get_raw() if _get_raw() then return 1 else return 0 end end
local _get_video_button = get_video_button; function get_video_button() if _get_video_button() then return 1 else return 0 end end
local _get_focus_ok = get_focus_ok; function get_focus_ok() if _get_focus_ok() then return 1 else return 0 end end
local _save_config_file = save_config_file; function save_config_file(...) if _save_config_file(...) then return 1 else return 0 end end
local _load_config_file = load_config_file; function load_config_file(...) if _load_config_file(...) then return 1 else return 0 end end
local _set_mf = set_mf; function set_mf(v) if _set_mf(v) then return 1 else return 0 end end
