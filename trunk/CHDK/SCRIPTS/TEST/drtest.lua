--[[
@title dynamic range test
@chdk_version 1.3
@param a + stops
@default a 4
@param b - stops
@default b 6
@param c - draw meter
@default c 1
@range c 0 1
]]
require'hookutil'
require'rawoplib'

props=require'propcase'
capmode=require'capmode'

overstops=a
understops=b

draw_meter = (c == 1)

save_raw=get_raw()
set_raw(1) 
function restore()
	set_raw(save_raw)
end

function meter_bar_width(v)
	return (v * 500)/rawop.fb.white_level
end
--[[
get rgb and combined meter
]]
function get_meter()
	-- centered 500 px square
	local meter_size = 500

	local x1 = rawop.fb.width/2 - meter_size/2

	local y1 = rawop.fb.height/2 - meter_size/2

	-- TODO a meter matching raw_histogram area / step might be interesting
	local m = rawop.meter(x1,y1,meter_size,meter_size,1,1)
	local r,g1,g2,b = rawop.meter_rgb4(x1,y1,meter_size,meter_size,2,2)
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
		rawop.fill_rect_rgb(x1 - 2,y1 - 2,meter_size+4,2,c,c,c)
		rawop.fill_rect_rgb(x1 - 2,y1 + meter_size,meter_size+4,2,c,c,c)
		rawop.fill_rect_rgb(x1 - 2,y1,2,meter_size,c,c,c)
		rawop.fill_rect_rgb(x1 + meter_size,y1,2,meter_size,c,c,c)

		-- draw max scale
		rawop.fill_rect_rgb(100,90,500,4,high,high,high)
		rawop.fill_rect_rgb(100,94,500,4,low,low,low)
		-- draw levels
		rawop.fill_rect_rgb(100,100,meter_bar_width(m),20,m,m,m)
		rawop.fill_rect_rgb(100,120,meter_bar_width(m),20,c,c,c)
		rawop.fill_rect_rgb(100,200,meter_bar_width(r),20,r,low,low)
		rawop.fill_rect_rgb(100,220,meter_bar_width(r),20,high,low,low)
		rawop.fill_rect_rgb(100,300,meter_bar_width(g1),20,low,g1,low)
		rawop.fill_rect_rgb(100,320,meter_bar_width(g1),20,low,high,low)
		rawop.fill_rect_rgb(100,400,meter_bar_width(g2),20,low,g2,low)
		rawop.fill_rect_rgb(100,420,meter_bar_width(g2),20,low,high,low)
		rawop.fill_rect_rgb(100,500,meter_bar_width(b),20,low,low,b)
		rawop.fill_rect_rgb(100,520,meter_bar_width(b),20,low,low,high)
		-- draw blacklevel scale
		rawop.fill_rect_rgb(100,550,meter_bar_width(rawop.fb.black_level),4,high,high,high)
		rawop.fill_rect_rgb(100,554,meter_bar_width(rawop.fb.black_level),4,low,low,low)
	end
	return m,r,g1,g2,b
end

--[[
very rough for quick look stats
there will usually be two peaks due to greater green sensitivity,
more pronounced with greater exposure
]]
function get_histo_stats()
	local bin=32
	local peak=0
	local peak_pct=0
	-- find the "bin" sized range with highest % of pixels
	for v=0,1024-bin do
		local pct=get_histo_range(v,v+bin-1)
		if pct > peak_pct then
			peak = v
			peak_pct = pct
		end
	end
	-- find the peak within the bin
	local pct_max=0
	for v=peak,peak+bin-1 do
		local pct=get_histo_range(v,v)
		if pct > pct_max then
			peak = v
			ptc_max = pct
		end
	end
	return peak,peak_pct,get_histo_range(0,32),get_histo_range(1023,1023)
end

function logline(desc)
	local fname='A/drtest.csv'
	local st=os.stat(fname)
	local f,err=io.open(fname,'ab')
	if not f then
		error(err)
	end
	if not st then
		f:write('desc,date,tick,exp,tv96,sv96,av96,bv96,m,m96,r,r96,g1,g1_96,g2,g2_96,b,b96,peak,peak%,bl%,wl%,ccd temp\n')
		local bi=get_buildinfo()
		f:write(string.format("%s %s %s %s %s %s %s %s 0x%x\n",
					bi.platform,bi.platsub,bi.version,bi.build_number,bi.build_revision,
					bi.build_date,bi.build_time,bi.os,bi.platformid))
	end
	local peak,peak_pct,bl_pct,wl_pct = 0,0,0,0
	local m,m96,r,r96,g1,g1_96,g2,g2_96,b,b96 = 0,0,0,0,0,0,0,0,0,0
	if desc ~='base' then
		peak,peak_pct,bl_pct,wl_pct = get_histo_stats()
 		m,r,g1,g2,b = get_meter()
		m96=rawop.raw_to_ev96(m)
		r96=rawop.raw_to_ev96(r)
		g1_96=rawop.raw_to_ev96(g1)
		g2_96=rawop.raw_to_ev96(g2)
		b96=rawop.raw_to_ev96(b)
	end
	f:write(string.format('%s,%s,%u,%u,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n',
				desc,
				os.date('%m/%d/%Y %H:%M:%S'),
				get_tick_count(),
				get_exp_count(),
				get_prop(props.TV),
				get_prop(props.SV),
				get_prop(props.AV),
				get_prop(props.BV),
				m,m96,
				r,r96,
				g1,g1_96,
				g2,g2_96,
				b,b96,
				peak,
				peak_pct,
				bl_pct,
				wl_pct,
				get_temperature(1)
			)
		)
	f:close()
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

-- TODO should focus at inf, possibly set zoom
shot_histo_enable(1)

hook_raw.set(20000)
press('shoot_half')
repeat sleep(10) until get_shooting()
base_tv=get_tv96()
logline('base')
tv=base_tv-96*overstops
for i=-overstops,understops do
	set_tv96_direct(tv)
	ecnt=get_exp_count()
	press("shoot_full_only")
	-- wait for shot histo and exp count to be ready
	hook_raw.wait_ready()
	release("shoot_full_only")
	logline(string.format("%d",-i))
	hook_raw.continue()
	tv = tv+96
end

restore()
