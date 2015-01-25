--[[
@title dynamic range test
@chdk_version 1.4.0.3939
#overstops=4 "+ stops"
#understops=6 "- stops"
#draw_meter=true "draw meter"
]]
require'hookutil'
require'rawoplib'

props=require'propcase'
capmode=require'capmode'

-- centered 500 px square
meter_size = 500

meter_left = rawop.fb.width/2 - meter_size/2
meter_top = rawop.fb.height/2 - meter_size/2

save_raw=get_raw()
set_raw(1) 
function restore()
	set_raw(save_raw)
	log:close()
end

function meter_bar_width(v)
	return (v * 500)/rawop.fb.white_level
end

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
	self.name = opts.name
	self.dummy = opts.dummy
	if opts.buffer_mode then
		self.buffer_mode = opts.buffer_mode
	else
		self.buffer_mode = 'os'
	end
	if self.buffer_mode == 'table' then
		self.lines={}
	elseif self.buffer_mode ~= 'os' and self.buffer_mode ~= 'sync' then
		error('invalid buffer mode '..tostring(self.buffer_mode))
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
	if self.dummy then
		local nop =function() return end
		self.write=nop
		self.write_data=nop
		self.flush=nop
		self.set=nop
	else
		-- TODO name should accept autonumber or date based options
		if not opts.append then
			os.remove(self.name)
		end
		if self.buffer_mode == 'os' then
			self.fh = io.open(self.name,'ab')
			if not self.fh then
				error('failed to open log')
			end
		end
		self:write_data(self.cols)
		self:flush()
	end
end
function log:prepare_write()
	if self.buffer_mode == 'os' then
		return
	end
	-- if self.buffer_mode == 'sync' or self.buffer_mode then
	self.fh = io.open(self.name,'ab')
	if not self.fh then
		error('failed to open log')
	end
end
function log:finish_write()
	if self.buffer_mode == 'os' then
		return
	end
	self.fh:close()
	self.fh=nil
end

function log:write_csv(data)
	-- TODO should handle CSV quoting
	self.fh:write(string.format("%s\n",table.concat(data,',')))
end
function log:write_data(data)
	if self.buffer_mode == 'table' then
		table.insert(self.lines,data)
		return
	end
	self:prepare_write()
	self:write_csv(data)
	self:finish_write()
end

function log:flush()
	if self.buffer_mode == 'os' then
		if self.fh then
			self.fh:flush()
		end
	elseif self.buffer_mode == 'table' then
		if #self.lines == 0 then
			return
		end
		self:prepare_write()
		for i,data in ipairs(self.lines) do
			self:write_csv(data)
		end
		self:finish_write()
		self.lines={}
	end
	-- 'sync' is flushed every line
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
	self:write_data(data)
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
	if self.dummy then
		return function() end
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
	if self.dummy then
		return function() end
	end
	return function(fmt,...)
		table.insert(self.vals[name],string.format(fmt,...))
	end
end

function log:close()
	if self.buffer_mode == 'table' then
		self:flush()
	end
	if self.fh then
		self.fh:close()
	end
end
-- end log module


--[[
get rgb and combined meter
]]
function get_meter()
	local t0=get_tick_count()
	local m = rawop.meter(meter_left,meter_top,meter_size,meter_size,1,1)
	local r,g1,b,g2 = rawop.meter_rgbg(meter_left,meter_top,meter_size,meter_size,2,2)
	log:set{meter_time=get_tick_count()-t0}

	t0=get_tick_count()
	if draw_meter then
		local low = rawop.fb.black_level + rawop.fb.black_level / 2
		local high = rawop.fb.white_level - rawop.fb.black_level
		-- draw color that contrasts with meter
		local c
		if m > rawop.fb.white_level - rawop.fb.white_level/3 then
			c = low
		else
			c = high
		end
		-- box around meter area
		rawop.fill_rect_rgbg(meter_left - 2,meter_top - 2,meter_size+4,2,c,c,c)
		rawop.fill_rect_rgbg(meter_left - 2,meter_top + meter_size,meter_size+4,2,c,c,c)
		rawop.fill_rect_rgbg(meter_left - 2,meter_top,2,meter_size,c,c,c)
		rawop.fill_rect_rgbg(meter_left + meter_size,meter_top,2,meter_size,c,c,c)

		-- draw max scale
		rawop.fill_rect_rgbg(100,90,500,4,high,high,high)
		rawop.fill_rect_rgbg(100,94,500,4,low,low,low)
		-- draw levels
		rawop.fill_rect_rgbg(100,100,meter_bar_width(m),20,m,m,m)
		rawop.fill_rect_rgbg(100,120,meter_bar_width(m),20,c,c,c)
		rawop.fill_rect_rgbg(100,200,meter_bar_width(r),20,r,low,low)
		rawop.fill_rect_rgbg(100,220,meter_bar_width(r),20,high,low,low)
		rawop.fill_rect_rgbg(100,300,meter_bar_width(g1),20,low,g1,low)
		rawop.fill_rect_rgbg(100,320,meter_bar_width(g1),20,low,high,low)
		rawop.fill_rect_rgbg(100,400,meter_bar_width(g2),20,low,g2,low)
		rawop.fill_rect_rgbg(100,420,meter_bar_width(g2),20,low,high,low)
		rawop.fill_rect_rgbg(100,500,meter_bar_width(b),20,low,low,b)
		rawop.fill_rect_rgbg(100,520,meter_bar_width(b),20,low,low,high)
		-- draw blacklevel scale
		rawop.fill_rect_rgbg(100,550,meter_bar_width(rawop.fb.black_level),4,high,high,high)
		rawop.fill_rect_rgbg(100,554,meter_bar_width(rawop.fb.black_level),4,low,low,low)
	end
	log:set{draw_time=get_tick_count()-t0}
	return m,r,g1,g2,b
end

--[[
very rough for quick look stats
there will usually be two peaks due to greater green sensitivity,
more pronounced with greater exposure
]]
function get_histo_stats()
	-- TODO just reproduce shot_histogram behavior for now
	local t0=get_tick_count()
	histo:update(rawop.fb.active_area.x1,rawop.fb.active_area.y1,
						rawop.fb.active_area.x2 - rawop.fb.active_area.x1,
						rawop.fb.active_area.y2 - rawop.fb.active_area.y1,
						31,31,10)
	log:set{histo_update_time=get_tick_count()-t0}

	local bin=32
	local peak=0
	local peak_count=0
	t0=get_tick_count()
	-- find the "bin" sized range with highest % of pixels
	for v=0,1024-bin do
		local count=histo:range(v,v+bin-1,'count')
		if count > peak_count then
			peak = v
			peak_count = count
		end
	end
	local peak_pct = histo:range(peak,peak+bin-1)
	-- find the peak within the bin
	local count_max=0
	for v=peak,peak+bin-1 do
		local count=histo:range(v,v,'count')
		if count > count_max then
			peak = v
			count_max = count
		end
	end
	local bl_pct,wl_pct = histo:range(1,32),histo:range(1023,1023)
	log:set{histo_calc_time=get_tick_count()-t0}
	return peak,peak_pct,bl_pct,wl_pct
end

function doshot(shotdesc)
	-- pct are actually per thousand
	local peak,peak_pct,bl_pct,wl_pct = get_histo_stats()
	local m,r,g1,g2,b = get_meter()

	log:set{
		shot=shotdesc,
		m=m,
		m96=rawop.raw_to_ev96(m),
		r=r,
		r96=rawop.raw_to_ev96(r),
		g1=g1,
		g1_96=rawop.raw_to_ev96(g1),
		g2=g2,
		g2_96=rawop.raw_to_ev96(g2),
		b=b,
		b96=rawop.raw_to_ev96(b),
		peak=peak,
		['peak%']=string.format("%d.%d",peak_pct/10,peak_pct%10),
		['bl%']=string.format("%d.%d",bl_pct/10,bl_pct%10),
		['wl%']=string.format("%d.%d",wl_pct/10,wl_pct%10),
	}
end

function log_base()
	log:set{shot='base'}
	local bi=get_buildinfo()
	logdesc("%s %s %s %s %s %s %s %s 0x%x",
						bi.platform,bi.platsub,bi.version,bi.build_number,bi.build_revision,
						bi.build_date,bi.build_time,bi.os,bi.platformid)

	-- bv only measured by cam at start
	logdesc("bv96=%d",get_prop(props.BV))
	log:write()
end

if not get_mode() then
	printf("switching to rec")
	set_record(true)
	repeat sleep(10) until get_mode()
	sleep(500)
end

if capmode.get_name() ~= 'P' then
	printf("switching to P")
	if not capmode.set('P') then
		error("set P failed")
	end
	sleep(500)
end

log:init{
	name="A/drtest.csv",
	append=true,
	buffer_mode='table',
	-- column names
	cols={
		'shot',
		'date',
		'time',
		'tick',
		'exp',
		'meter_time',
		'histo_update_time',
		'histo_calc_time',
		'draw_time',
		'tsensor',
		'sv96',
		'tv96',
		'av96',
		'm',
		'm96',
		'r',
		'r96',
		'g1',
		'g1_96',
		'g2',
		'g2_96',
		'b',
		'b96',
		'peak',
		'peak%',
		'bl%',
		'wl%',
		'desc',
	},
	-- columns automatically set at write time from functions
	funcs={
		date=function()
			return os.date('%m/%d/%Y')
		end,
		time=function()
			return os.date('%H:%M:%S')
		end,
		tick=get_tick_count,
		exp=get_exp_count,
		tsensor=function()
			return get_temperature(1)
		end,
		tv96=function()
			return get_prop(props.TV)
		end,
		sv96=function()
			return get_prop(props.SV)
		end,
		av96=function()
			return get_prop(props.AV)
		end
	},
	-- columns collected in a table, concatenated at write time
	tables={
		desc=' / ',
	},
}
logdesc=log:text_logger('desc')

histo=rawop.create_histogram()

-- TODO should focus at inf, possibly set zoom

hook_raw.set(20000)
press('shoot_half')
repeat sleep(10) until get_shooting()
base_tv=get_tv96()
log_base()

tv=base_tv-96*overstops
for i=-overstops,understops do
	set_tv96_direct(tv)
	ecnt=get_exp_count()
	press("shoot_full_only")
	-- wait for shot histo and exp count to be ready
	hook_raw.wait_ready()
	release("shoot_full_only")
	doshot(string.format("%d",-i))
	log:write()
	hook_raw.continue()
	tv = tv+96
end

restore()
