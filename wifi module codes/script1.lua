print("the client is on the way")

wifi.setmode(wifi.STATION)
wifi.sta.config("esi","aydcacaa")
wifi.sta.connect()
tmr.alarm(1,1000,1,function()
    if wifi.sta.getip() == nil then
        print("connecting...")
    else tmr.stop(1)
        print("connected, IP is"..wifi.sta.getip())
    end
end)
conn = net.createConnection(net.TCP,false)
conn:on("receive",function(conn,pl)print(pl)end)
a = conn:connect(7778,"192.168.43.99")
conn:send("salam#gholam")
conn:on("receive", function(sck, payload)
        print(payload)
end)