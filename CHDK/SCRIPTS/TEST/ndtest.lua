--[[
@title ND value test
@chdk_version 1.4.1
#shots_per_step=5 "Shots per state"
#start_delay=1 "Start delay, sec"
#nd_shot_ev96=288 "ND shot comp EV96"
#ui_shoot_mode_t=1 "Shoot mode" {Single Quick Cont} table
#ui_log_append=true "Append log"
]]
--[[
Script to test ND control and get the approximate exposure value of the ND filter

Usage:
Put the camera on a tripod or stable surface with aimed at a scene with steady lighting
and run the script. A relatively uniform, neutral scene like a blank wall or sheet of
paper will give better results. The camera should be in P or M mode.

Results:
Results are logged to A/ndtest.csv. The desc column of the final line gives the calculated
ND value.

The meter96 column should not change by more than 1-2 units for shots in a given ND state,
if it does, the scene is probably not stable enough to give good results.

If WARNING appears in the final line, the script detected poor precision or other problems

Options:
* Shots per state - Number of shots to with ND filter on and off
* Start delay - Seconds to wait before shootings starts
* ND shot comp EV96 - Exposure compensation to use for ND on shots. This is intended
  to keep the exposure relatively similar so neither state will be over or under exposed.
  The default should be sufficient. If the value equals the ND value, then there will
  be no perceptible exposure change between ND and no-ND images.
* Shoot mode 
 * Single - Do full half press, auto focus etc between each shots. Should work on most
   cameras, but may give less precise results and is slower
 * Quick - Hold down shutter half way, click full for each shot. Faster and more precise
   than single, but may fail on some cameras.
 * Cont - Shoot in continuous mode. More precise than single, fastest, but requires
   continuous mode enabled in the Canon UI.
* Append log - If checked, each run adds to the existing log. Otherwise the log is replaced
  on each run.


License: GPL

Copyright 2017 reyalp (at) gmail.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
with CHDK. If not, see <http://www.gnu.org/licenses/>.

]]
require'hookutil'
require'rawoplib'
props=require'propcase'

ndtest_version="1.1"


-- log module
log={}
function log:init(opts)
	if not opts then
		error('missing opts');
	end
	self.cols={unpack(opts.cols)}
	self.vals={}
	self.funcs={}
	self.tables={}
	if opts.funcs then
		for n,f in pairs(opts.funcs) do
			if type(f) ~= 'function' then
				error('expected function')
			end
			self.funcs[n] = f
		end
	end
	-- TODO may accept other options than sep later
	if opts.tables then
		for n,sep in pairs(opts.tables) do
			self.tables[n] = {sep=sep}
		end
	end
	self:reset_vals()
	-- checks after vals initialized
	for n, v in pairs(self.funcs) do
		if not self.vals[n] then
			error('missing func col '.. tostring(n))
		end
	end
	for n, v in pairs(self.tables) do
		if not self.vals[n] then
			error('missing table col '.. tostring(n))
		end
	end
	-- TODO name should accept autonumber or date based options
	if opts.append then
		self.fh = io.open(opts.name,'ab')
	else
		self.fh = io.open(opts.name,'wb')
	end
	if not self.fh then
		error('failed to open log')
	end
	self:write_csv(self.cols)
end
function log:write_csv(data)
	-- TODO should handle CSV quoting
	self.fh:write(string.format("%s\n",table.concat(data,',')))
end
function log:write()
	local data={}
	for i,name in ipairs(self.cols) do
		local v
		if self.funcs[name] then
			v=tostring(self.funcs[name]())
		elseif self.tables[name] then
			v=table.concat(self.vals[name],self.tables[name].sep)
		else
			v=self.vals[name]
		end
		table.insert(data,v)
	end
	self:write_csv(data)
	self:reset_vals()
end
function log:reset_vals()
	for i,name in ipairs(self.cols) do
		if self.tables[name] then
			self.vals[name] = {}
		else
			self.vals[name] = ''
		end
	end
end
function log:set(vals)
	for name,v in pairs(vals) do
		if not self.vals[name] then
			error("unknown log col "..tostring(name))
		end
		if self.funcs[name] then
			error("tried to set func col "..tostring(name))
		end
		if self.tables[name] then
			table.insert(self.vals[name],v)
		else
			self.vals[name] = tostring(v)
		end
	end
end
--[[
return a function that records time offset from col named base_name
if name is not provided, function expects target aname as arg
]]
function log:dt_logger(base_name,name)
	if not self.vals[base_name] then
		error('invalid base field name')
	end
	if not name then
		return function(name)
			if not self.vals[name] then
				error('invalid col name')
			end
			self.vals[name]=get_tick_count() - self.vals[base_name]
		end
	end
	if not self.vals[name] then
		error('invalid col name')
	end
	return function()
		self.vals[name]=get_tick_count() - self.vals[base_name]
	end
end

--[[
return a printf-like function that appends to table col
]]
function log:text_logger(name)
	if not self.vals[name] then
		error('invalid col name')
	end
	if not self.tables[name] then
		error('text logger must be table field '..tostring(name))
	end
	return function(fmt,...)
		table.insert(self.vals[name],string.format(fmt,...))
	end
end

function log:close()
	if self.fh then
		self.fh:close()
	end
end
-- end log module

function restore()
	set_iso_mode(saved_iso_mode)
	set_nd_filter(0)
	log:close()
end

log:init{
	name="A/ndtest.csv",
	append=ui_log_append,
	-- column names
	cols={
		'date',
		'tick',
		'exp',
		'vbatt',
		'tsensor',
		'topt',
		'free_mem',
		'lua_mem',
		'sd_space',
		'sv',
		'sv96',
		'tv',
		'tv96',
		'av',
		'av96',
		'nd',
		'meter',
		'meter96',
		'desc',
	},
	-- columns automatically set at write time from functions
	funcs={
		date=function()
			return os.date('%m/%d/%Y %H:%M:%S')
		end,
		tick=get_tick_count,
		exp=get_exp_count,
		vbatt=get_vbatt,
		tsensor=function()
			return get_temperature(1)
		end,
		topt=function()
			return get_temperature(0)
		end,
		free_mem=function()
			return get_meminfo().free_size
		end,
		lua_mem=function()
			return collectgarbage('count')
		end,
		sd_space=get_free_disk_space,
	},
	-- columns collected in a table, concatenated at write time
	tables={
		desc=' / ',
	},
}
logdesc=log:text_logger('desc')

meter_size=1200
meter_step=5
meter_left = rawop.get_raw_width()/2 - meter_size/2
meter_count = meter_size/meter_step
meter_top = rawop.get_raw_height()/2 - meter_size/2

function state_results(name,r)
	local t=r.m
	r.sum = 0
	r.min = t[1]
	r.max = t[1]
	for i=1,#t do
		if t[i] > r.max then
			r.max = t[i]
		end
		if t[i] < r.min then
			r.min = t[i]
		end
		r.sum = r.sum + t[i]
	end
	r.avg=r.sum/#t
	r.min96=rawop.raw_to_ev(r.min)
	r.max96=rawop.raw_to_ev(r.max)
	r.avg96=rawop.raw_to_ev(r.avg)
	-- if less than 3 stops above black level, warn
	if r.min96 < rawop.raw_to_ev(rawop.get_black_level()+1) + 96*3 then
		logdesc('WARNING %s underexposed min=%d',name,r.min96)
	end
	-- if > 1/4 below white level, warn
	if r.max96 > rawop.raw_to_ev(rawop.get_white_level()) - 24 then
		logdesc('WARNING %s overexposed max=%d',name,r.max96)
	end
	-- a good scene shouldn't vary more than a few APEX96 units
	if r.max96 - r.min96 > 4 then
		logdesc('WARNING %s variation=%d',name,r.max96-r.min96)
	end
	logdesc('%s:avg=%d (%d) min=%d (%d) max=%d (%d)',name,r.avg,r.avg96,r.min,r.min96,r.max,r.max96)
end

function check_resutl(name,r)
end

function calc_results(nond,nd)
	state_results('no-ND',nond)
	state_results('ND',nd)

	local v=nond.avg96 - nd.avg96 + nd_shot_ev96
	logdesc('ND value=%d',v)
end

function run()
	local nd_vals={
		m={},
		m96={},
	}
	local nond_vals={
		m={},
		m96={},
	}
	local vals=nond_vals

	local bi=get_buildinfo()
	logdesc("ndtest v:%s",ndtest_version);
	logdesc("platform:%s-%s-%s-%s %s %s",
						bi.platform,bi.platsub,bi.build_number,bi.build_revision,
						bi.build_date,bi.build_time)

	local shoot_mode = string.lower(ui_shoot_mode_t.value)
	logdesc('shoot_mode=%s nd_shot_ev96=%d',shoot_mode,nd_shot_ev96)
	if shoot_mode == 'cont' and get_prop(props.DRIVE_MODE) ~= 1 then
		error('Canon cont mode not set')
	end

	if get_nd_present() == 0 then
		error('ND not enabled in port')
	end

	saved_iso_mode=get_iso_mode()
	sleep(start_delay*1000)
	-- preshoot to meter
	press'shoot_half'
	repeat sleep(10) until get_shooting()
	release'shoot_half'

	-- ensure shooting has gone back to false so initial overrides will be SET_LATER
	repeat sleep(10) until not get_shooting()
	sleep(50)

	logdesc('start tv96=%s sv96=%s av96=%s',get_prop(props.TV),get_prop(props.SV),get_prop(props.AV))
	local sv96=get_prop(props.SV)
	local tv96=get_prop(props.TV)
	local av96=get_prop(props.AV)
	sleep(100)
	-- ND only, check if ND was in on auto exposure
	if get_nd_present() == 1 and get_prop(props.AV) ~= get_prop(props.MIN_AV) then
		error('AE used ND, try darker scene')
	elseif get_nd_present() == 2 and get_prop(props.ND_FILTER_STATE) == 1 then
		error('ND on in Canon UI')
	end

	set_tv96_direct(tv96)
	set_sv96(sv96)
	if get_nd_present() ~= 1 then
		set_av96(av96)
	end
	set_nd_filter(2)

	-- set shoot hook for cont mode
	hook_shoot.set(10000)
	-- set hook in raw for exposure
	hook_raw.set(10000)

	if shoot_mode ~= 'single' then
		press('shoot_half')
		repeat sleep(10) until get_shooting()
	end

	if shoot_mode == 'cont' then
		press('shoot_full_only')
	end

	local shots=shots_per_step*2
	local nd_state=false
	for i=1,shots do
		print("shot",i,"/",shots)

		wait_click(10)
		if is_key('menu') then
			logdesc('user exit')
			log:write()
			break
		end
		if shoot_mode == 'single' then
			repeat sleep(10) until not get_shooting()
			sleep(50)
			set_sv96(sv96)
			set_tv96_direct(tv96)
			if get_nd_present() ~= 1 then
				set_av96(av96)
			end
			if nd_state then
				set_nd_filter(1)
			end

			sleep(50)
			press('shoot_half')
			repeat sleep(10) until get_shooting()
			sleep(50)
		end

		if shoot_mode ~= 'cont' then
			press('shoot_full_only')
		end
		-- wait until the hook is reached
		hook_shoot.wait_ready()

		-- in quick, setting in raw hook seems to fail on elph130
		if shoot_mode == 'quick' and nd_state then
			set_nd_filter(1)
		end

		if shoot_mode ~= 'cont' then
			release('shoot_full_only')
		end
		if shoot_mode == 'single' then
			release('shoot_half')
		end
		-- allow shooting to proceed
		hook_shoot.continue()

		-- wait for the image to be captured
		hook_raw.wait_ready()
		local meter = rawop.meter(meter_left,meter_top,
								meter_count,meter_count,
								meter_step,meter_step)

		tv96=get_prop(props.TV)
		local meter96=rawop.raw_to_ev(meter)
		local av96=get_prop(props.AV)
		local tvus=tv96_to_usec(tv96)
		local av1k=av96_to_aperture(av96)
		log:set{
			meter=meter,
			meter96=meter96,
			sv=sv96_to_iso(sv96_real_to_market(sv96)),
			sv96=sv96,
			av=string.format("%d.%03d",av1k/1000,((av1k%1000))),
			av96=av96,
			tv=string.format("%d.%06d",tvus/1000000,((tvus%1000000))),
			tv96=tv96,
			nd=nd_state,
		}
		table.insert(vals.m,meter)
		table.insert(vals.m96,meter96)
		if i == shots_per_step then
			nd_state=true
			tv96 = tv96 - nd_shot_ev96
			vals=nd_vals
		end
		if shoot_mode ~= 'single' and i ~= shots then
			set_sv96(sv96)
			set_tv96_direct(tv96)
			if get_nd_present() ~= 1 then
				set_av96(av96)
			end
			if shoot_mode == 'cont' and nd_state then
				set_nd_filter(1)
			end
		end
		if i == shots then
			calc_results(nond_vals,nd_vals)
			-- clear ND prop so it doesn't confuse Canon UI check in later runs
			if get_nd_present() == 2 then 
				set_prop(props.ND_FILTER_STATE,0)
			end

		end
		hook_raw.continue()

		log:write()
		collectgarbage('step')
	end
	hook_shoot.set(0)
	hook_raw.set(0)
	release('shoot_full')
end
run()
-- allow final shot to end before restore
repeat sleep(10) until not get_shooting()
sleep(1000)
restore()
