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

goto comment
netsh int ipv4 set address name="Ethernet0" static 192.168.1.77 255.255.255.0
:comment
@echo off

echo Choose:
echo [a] Static IP
echo [b] DHCP
echo.

:choice
SET /P C=a or b? 
for %%? in (A) do if /I "%C%"=="%%?" goto A
for %%? in (B) do if /I "%C%"=="%%?" goto B
goto choice

:a
@echo off
echo Setting Static IP Addresses ...
netsh int ipv4 set address name="Ethernet0" static 192.168.1.77 255.255.255.0
netsh int ipv4 add address "Ethernet0" 2.168.1.77 255.0.0.0
netsh int ipv4 add address "Ethernet0" 192.168.3.77 255.255.255.0
netsh int ipv4 add address "Ethernet0" 192.168.100.77 255.255.255.0
cls
timeout 5
ipconfig
pause
goto end

:b
@echo OFF
echo Switching to DHCP ...
netsh int ipv4 set address "Ethernet0" dhcp
cls
timeout 5
ipconfig
pause
goto end

:end