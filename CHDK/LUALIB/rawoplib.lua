--[[
utility functions for 'rawop' code
]]
if type(rawop) ~= 'table' then
	error('rawop not supported')
end
local fb=rawop.fb_info()
-- extended fb info
rawop.fb=fb

-- locals to avoid a bunch of nested table lookups on every get call
local cfa_r_x  = fb.cfa_offsets.r.x
local cfa_r_y  = fb.cfa_offsets.r.y
local cfa_g1_x = fb.cfa_offsets.g1.x
local cfa_g1_y = fb.cfa_offsets.g1.y
local cfa_g2_x = fb.cfa_offsets.g2.x
local cfa_g2_y = fb.cfa_offsets.g2.y
local cfa_b_x  = fb.cfa_offsets.b.x
local cfa_b_y  = fb.cfa_offsets.b.y

--[[
local set_pixel = rawop.set_pixel
local get_pixel = rawop.get_pixel
]]

function rawop.rect_rgbg(x,y,width,height,linewidth,r,g1,b,g2)
	if width < 2*linewidth or height < 2*linewidth or linewidth < 2 then
		return
	end
	rawop.fill_rect_rgbg(x,y,width,linewidth,r,g1,b,g2)
	rawop.fill_rect_rgbg(x,y + height-linewidth,width,linewidth,r,g1,b,g2)
	rawop.fill_rect_rgbg(x,y+linewidth,linewidth,height-2*linewidth,r,g1,b,g2)
	rawop.fill_rect_rgbg(x + width - linewidth,y+linewidth,linewidth,height-2*linewidth,r,g1,b,g2)
end

--[[
meter in RGB
x, y, start on the nearest even value
xstep and ystep must be even
]]
function rawop.meter_rgbg(x,y,xcount,ycount,xstep,ystep)
	x = bitand(x,0xFFFFFFFE)
	y = bitand(y,0xFFFFFFFE)
	if bitand(xstep,1) == 1 or bitand(ystep,1) == 1 then
		return
	end
	return
	 rawop.meter(x+cfa_r_x,y+cfa_r_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_g1_x,y+cfa_g1_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_b_x,y+cfa_b_y,xcount,ycount,xstep,ystep),
	 rawop.meter(x+cfa_g2_x,y+cfa_g2_y,xcount,ycount,xstep,ystep)
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
