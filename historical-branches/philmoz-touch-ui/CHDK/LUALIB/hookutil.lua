--[[
adds wait_ready method for shoot hooks
usage:
status=hook_name.wait_ready([opts])
opts is an optional table which may contain
timeout: number of ms to wait for hook to be ready, default 10 seconds
timeout_error: boolean - if true (default), throw an error if timeout expires
               otherwise unset hook and return false
--]]
if type(hook_shoot) ~= 'table' then
	error('build does not support shoot hooks')
end

local m={}

m.wait_ready_defaults={
	timeout=10000, -- wait for hook to be reached, in msec
	timeout_error=true, -- call error on timeout
}

for i,name in ipairs{'hook_preshoot','hook_shoot','hook_raw'} do
	local hook =_G[name]
	-- add wait_ready to existing hook tables
	hook.wait_ready=function(opts)
		if not opts then
			opts = m.wait_ready_defaults
		else
			for k,v in pairs(m.wait_ready_defaults) do
				if opts[k] == nil then
					opts[k] = m.wait_ready_defaults[k]
				end
			end
		end
		local t0=get_tick_count()
		while not hook.is_ready() do
			if get_tick_count() - t0 > opts.timeout then
				if opts.timeout_error then
					error(name..' wait_ready timeout')
				end
				hook.set(0) -- clear hook, might hit it just after check
				return false
			end
			sleep(10)
		end
		return true
	end
end
return m
