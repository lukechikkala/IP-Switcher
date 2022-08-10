:: --------------------------------------------------------
:: Author: Luke Chikkala
::
:: This program should be run with administrative
:: rights. Hence it is adviced to create a
:: shorcut for this script and enable "Run as administrator"
:: in "Properties" > "Advanced ..."
:: 
:: Make sure to set the right Interface name before
:: running this script.
::
:: Would be nice to add a good icon.
:: --------------------------------------------------------

@echo off
echo Choose:
echo [a] Static IP
echo [b] DHCP
echo.

:choice
SET /P C=a or b? 
for %%? in (a) do if /I "%C%"=="%%?" goto a
for %%? in (b) do if /I "%C%"=="%%?" goto b
goto choice

:a
@echo off
echo Setting Static IP Addresses ...
netsh int ipv4 set address name="Ethernet 5" static 192.168.1.77 255.255.255.0
netsh int ipv4 add address "Ethernet 5" 2.168.1.77 255.0.0.0
netsh int ipv4 add address "Ethernet 5" 10.168.100.77 255.255.255.0
netsh int ipv4 add address "Ethernet 5" 192.168.0.77 255.255.255.0
netsh int ipv4 add address "Ethernet 5" 192.168.3.77 255.255.255.0
netsh int ipv4 add address "Ethernet 5" 192.168.100.77 255.255.255.0
cls
timeout 5
ipconfig
pause
goto end

:b
@echo off
echo Switching to DHCP ...
netsh int ipv4 set address "Ethernet 5" dhcp
cls
timeout 5
ipconfig
pause
goto end

:end