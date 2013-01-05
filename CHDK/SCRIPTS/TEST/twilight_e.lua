--[[
********************************
Licence: GPL
(c) 2012 msl
thx rudi for cordic & script check
v0.3
********************************
@title Twilight

@param a Current Date?
@default a 1
@range a 0 1

@param y Year
@default y 0
@values y 2012 2013 2014 2015 2016 2017 2018 2019 2020

@param m Month
@default m 0
@values m Jan Feb Mar Apr May Jun Jul Aug Sep Oct Nov Dez

@param d Day
@default d 30
@range d 1 31

@param s Daylight Saving Time?
@default s 0
@range s 0 1
]]

--FUNCTIONS------------------------------

-- Split string and write in array  -> string.split(string,delimiter)
function string:split(delimiter)
    local result = { }
    local from = 1
    local delim_from, delim_to = string.find(self, delimiter, from )
    while delim_from do
        table.insert( result, string.sub(self, from , delim_from-1 ) )
        from = delim_to + 1
        delim_from, delim_to = string.find(self, delimiter, from )
    end
    table.insert( result, string.sub(self, from ) )
    return result
end

-- remove leading & trailing spaces -> string.trim(string)
function string:trim()
  return (string.gsub(self, "^%s*(.-)%s*$", "%1"))
end

function load_data(dfile)
    if os.stat(dfile) then
        local file = io.open(dfile)
        local line_id = 0
                for line in file:lines(dfile) do
                    if string.find(line, "#") == nil then
                        local array = string.split(line,";")
                        if table.getn(array) > 3 then
                            array[2] = tonumber(array[2])
                            array[3] = tonumber(array[3])
                            array[4] = tonumber(array[4])
                            if (type(array[1]) == "string") then
                                array[1] = string.trim(array[1])
                                if (type(array[2]) == "number") and (array[2] <= 1800 or array[2] >= -1800) then
                                    if (type(array[3]) == "number") and (array[3] <= 1800 or array[3] >= -1800) then
                                        if (type(array[4]) == "number") and (array[4] <= 12   or array[4] >= -12)   then
                                            line_id = line_id + 1
                                            location[line_id] = {}
                                            location[line_id].name = array[1]
                                            location[line_id].lat  = array[2]
                                            location[line_id].lng  = array[3]
                                            location[line_id].utc  = array[4]
                                        end
                                    end
                                end
                            end
                        end
                    end
                end
        file:close()
        return true, line_id
    else
        return false
    end
end

function call_data()
    --data_file = "A/CHDK/DATA/geo_data.txt"
    cls()
    print("File browser will open.")
    print("Choose a file.")
    console_redraw()
    sleep(2000)
    cls()
    data_file = file_browser("A/CHDK/DATA")
    if data_file ~= nil then
        data, count = load_data(data_file)
    else
        data = false
    end
    if data == false then
        print("Could not load external data!")
    else
        print(count, "records are read.")
    end
    console_redraw()
    sleep(2000)
end

function is_leap_year(year)
    return year % 4 == 0 and (year % 100 ~= 0 or year % 400 == 0)
end

function get_day_of_year(year, month, day)
    local day_of_year = 0
    local feb = 28
    if is_leap_year(year) then feb = 29 end
    local days_in_month = {31, feb, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    for i = 1, month-1 do
        day_of_year=day_of_year + days_in_month[i]
    end
    return day_of_year + day
end

function sun_times(doy, h, lat, lng, utc)
    --based on http://lexikon.astronomie.info/zeitgleichung/
    --declination = 0.4095*sin(0.016906*(T-80.086))
    local D = imath.muldiv(imath.sinr(imath.muldiv(16906, doy*1000-80086,1000000)), 4095, 10000)
    --time equation: WOZ - MOZ = -0.171*sin(0.0337 * T + 0.465) - 0.1299*sin(0.01787 * T - 0.168)
    local WOZ = imath.mul(imath.sinr(((337 * doy) + (465*10))/10), -171)
    local MOZ = imath.mul(imath.sinr(((1787 * doy) - (168*100))/100), 130)
    local time_equation = WOZ - MOZ
    --timediff = 12*arccos((sin(h) - sin(B)*sin(declination)) / (cos(B)*cos(declination)))/Pi
    local time_diff = 12 * imath.scale * imath.acosr(imath.div((imath.sind(h) - imath.mul(imath.sind(lat), imath.sinr(D))), imath.mul(imath.cosd(lat), imath.cosr(D)))) / imath.pi
    --suntop = 12 + timezone - longitude /15 - time equation
    local top = (12 + utc) * imath.scale - imath.div(lng * 100, 15 * imath.scale) - time_equation
    local rising  = top - time_diff
    local setting = top + time_diff
    return rising, setting, top
end

function restore()
    cls()
    set_console_layout(0,0,25,5)
    set_console_autoredraw(1)
end

--MAIN-----------------------

--date
year  = 2012 + y
if a ==1 then year  = os.date("%Y") end
month = m + 1
if a ==1 then month = os.date("%m") end
day   = d
if month == 2 and day > 28 then
    if is_leap_year(year) then
        day = 29
    else
        day = 28
    end
end
if a ==1 then day   = os.date("%d") end

--data
h1=-833  --sunset/sunrise h=-50'
h2=-6000 --civil twilight h= -6°

location = {}
location[1] = {}
location[1].name = "Berlin" -- location
location[1].lat  = 525      -- latitude 52.5°
location[1].lng  = 135      -- longitude 13.5°
location[1].utc  = 1        -- time zone +1 h

--user interface
cls()
set_console_layout(5,3,40,14)
set_console_autoredraw(0)

line = "-----------------------------------" 
location_id = 1
DoY=get_day_of_year(year, month, day)

while true do
    location_id_max = table.getn(location)
    Utc = location[location_id].utc + s
    Utc_str = "UTC +"
    if Utc == 0 then Utc_str = "UTC +/-" end
    if Utc < 0 then Utc_str = "UTC " end
    Lat = location[location_id].lat
    Lat_str = string.format("%d.%d°", Lat/10, math.abs(Lat%10))
    Lat_deg = Lat*100
    Lng = location[location_id].lng
    Lng_str = string.format("%d.%d°", Lng/10, math.abs(Lng%10))
    sunrise, sunset, suntop = sun_times(DoY, h1, Lat_deg, Lng, Utc)
    dawn, dusk = sun_times(DoY, h2, Lat_deg, Lng, Utc)
    
    cls()
    print(string.format(" [\18] %s %s%d", location[location_id].name, Utc_str, location[location_id].utc))
    print(string.format("     %s %s %02d.%02d.%4d", Lat_str, Lng_str, day, month, year))
    print(line)
    print(string.format("      civil dawn: %02d:%02d clock",dawn/1000, dawn%1000*600/100/100))
    print(string.format("         sunrise: %02d:%02d clock",sunrise/1000, sunrise%1000*600/100/100))
    print(string.format("         sun top: %02d:%02d clock",suntop/1000, suntop%1000*600/100/100))
    print(string.format("          sunset: %02d:%02d clock",sunset/1000, sunset%1000*600/100/100))
    print(string.format("      civil dusk: %02d:%02d clock",dusk/1000, dusk%1000*600/100/100))
    print(line)
    print(" [SET] load geo data   [MENU] end")
    console_redraw()
    wait_click(0)
    if     is_pressed("down") then
        location_id = location_id + 1
        if location_id > location_id_max then location_id = 1 end
    elseif is_pressed("up") then
        location_id = location_id - 1
        if location_id < 1 then location_id = location_id_max end
    elseif is_pressed("set") then call_data()
    elseif is_pressed("menu") then break
    end
end

restore()
