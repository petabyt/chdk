--[[
utility functions for 'rawop' code
]]
if type(rawop) ~= 'table' then
	error('rawop not supported')
end
local fb=rawop.fb_info()
-- extended fb info
rawop.fb=fb

local function init_cfa()
	local r={}
	local x=0 
	local y=0
	for i=0,3 do
		local c=bitand(bitshri(fb.cfa_pattern,8*i),0xFF)
		local cn
		if c == 0 then
			cn='r'
		elseif c == 1 then
			if r['g1'] then
				cn='g2'
			else
				cn='g1'
			end
		elseif c == 2 then
			cn='b'
		end
		r[cn] = {x=x,y=y}
		if x == 1 then
			y = y + 1
		end
		x = bitand(x + 1,1)
	end
	fb.cfa_pattern_offsets = r
end
init_cfa()
-- locals to avoid a bunch of nested table lookups on every get call
local cfa_r_x  = fb.cfa_pattern_offsets.r.x
local cfa_r_y  = fb.cfa_pattern_offsets.r.y
local cfa_g1_x = fb.cfa_pattern_offsets.g1.x
local cfa_g1_y = fb.cfa_pattern_offsets.g1.y
local cfa_g2_x = fb.cfa_pattern_offsets.g2.x
local cfa_g2_y = fb.cfa_pattern_offsets.g2.y
local cfa_b_x  = fb.cfa_pattern_offsets.b.x
local cfa_b_y  = fb.cfa_pattern_offsets.b.y

local set_pixel = rawop.set_pixel
local get_pixel = rawop.get_pixel


--[[
return r,g,g,b quad that includes x,y
]]
function rawop.get_pixels_rgb4(x,y)
	x = bitand(x,0xFFFFFFFE)
	y = bitand(y,0xFFFFFFFE)
	return
	 get_pixel(x+cfa_r_x, y+cfa_r_y),
	 get_pixel(x+cfa_g1_x, y+cfa_g1_y),
	 get_pixel(x+cfa_g2_x, y+cfa_g2_y),
	 get_pixel(x+cfa_b_x, y+cfa_b_y)
end

--[[
return r,g,b with average of two Gs
]]
function rawop.get_pixels_rgb(x,y)
	x = bitand(x,0xFFFFFFFE)
	y = bitand(y,0xFFFFFFFE)
	return
	 get_pixel(x+cfa_r_x, y+cfa_r_y),
	 (get_pixel(x+cfa_g1_x, y+cfa_g1_y) + get_pixel(x+cfa_g2_x, y+cfa_g2_y))/2,
	 get_pixel(x+cfa_b_x, y+cfa_b_y)
end

function rawop.set_pixels_rgb4(x,y,r,g1,g2,b)
	x = bitand(x,0xFFFFFFFE)
	y = bitand(y,0xFFFFFFFE)
	set_pixel(x+cfa_r_x, y+cfa_r_y,r)
	set_pixel(x+cfa_g1_x, y+cfa_g1_y,g1)
	set_pixel(x+cfa_g2_x, y+cfa_g2_y,g2)
	set_pixel(x+cfa_b_x, y+cfa_b_y,b)
end

function rawop.set_pixels_rgb(x,y,r,g,b)
	x = bitand(x,0xFFFFFFFE)
	y = bitand(y,0xFFFFFFFE)
	set_pixel(x+cfa_r_x, y+cfa_r_y,r)
	set_pixel(x+cfa_g1_x, y+cfa_g1_y,g)
	set_pixel(x+cfa_g2_x, y+cfa_g2_y,g)
	set_pixel(x+cfa_b_x, y+cfa_b_y,b)
end

function rawop.fill_rect_rgb(xstart,ystart,width,height,r,g,b)
	xstart = bitand(xstart,0xFFFFFFFE)
	ystart = bitand(ystart,0xFFFFFFFE)
	local xr = xstart + cfa_r_x
	local yr = ystart + cfa_r_y
	local xg1 = xstart + cfa_g1_x
	local yg1 = ystart + cfa_g1_y
	local xg2 = xstart + cfa_g2_x
	local yg2 = ystart + cfa_g2_y
	local xb = xstart + cfa_b_x
	local yb = ystart + cfa_b_y
	local ymax = ystart + height
	while yr < ymax do
		local x=0
		while x < width do
			set_pixel(x + xr,yr,r)
			set_pixel(x + xg1,yg1,g)
			set_pixel(x + xg2,yg2,g)
			set_pixel(x + xb,yb,b)
			x = x + 2
		end
		yr = yr + 2
		yg1 = yg1 + 2
		yg2 = yg2 + 2
		yb = yb + 2
	end
end

function rawop.rect_rgb(x,y,width,height,linewidth,r,g,b)
	if width < 2*linewidth or height < 2*linewidth or linewidth < 2 then
		return
	end
	rawop.fill_rect_rgb(x,y,width,linewidth,r,g,b)
	rawop.fill_rect_rgb(x,y + height-linewidth,width,linewidth,r,g,b)
	rawop.fill_rect_rgb(x,y+linewidth,linewidth,height-2*linewidth,r,g,b)
	rawop.fill_rect_rgb(x + width - linewidth,y+linewidth,linewidth,height-2*linewidth,r,g,b)
end

--[[
meter in RGB
x, y, start on the nearest even value
xstep and ystep must be even
]]
function rawop.meter_rgb4(x,y,xcount,ycount,xstep,ystep)
	x = bitand(x,0xFFFFFFFE)
	y = bitand(y,0xFFFFFFFE)
	if bitand(xstep,1) == 1 or bitand(ystep,1) == 1 then
		return
	end
	return
	 rawop.meter(x+cfa_r_x,y+cfa_r_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_g1_x,y+cfa_g1_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_g2_x,y+cfa_g2_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_b_x,y+cfa_b_y,xcount,ycount,xstep,ystep)
end

--[[
as above, but meter only the first green
]]
function rawop.meter_rgb(x,y,xcount,ycount,xstep,ystep)
	x = bitand(x,0xFFFFFFFE)
	y = bitand(y,0xFFFFFFFE)
	if bitand(xstep,1) == 1 or bitand(ystep,1) == 1 then
		return
	end
	return
	 rawop.meter(x+cfa_r_x,y+cfa_r_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_g1_x,y+cfa_g1_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_b_x,y+cfa_b_y,xcount,ycount,xstep,ystep)
end
