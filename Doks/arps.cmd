for /L %a in (1,1,254) do @start /b ping 192.168.1.%a -n 2 > nul
