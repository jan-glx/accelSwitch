# accelSwitch & accelSwitcher
[![GitHub license](https://img.shields.io/github/license/jan-glx/accelswitch.svg)](LICENSE)
[![AppVeyor](https://img.shields.io/appveyor/ci/jan-glx/accelswitch.svg)](https://ci.appveyor.com/project/jan-glx/accelswitch)
[![Github All Releases](https://img.shields.io/github/downloads/jan-glx/accelswitch/total.svg)](https://github.com/jan-glx/accelSwitch/releases/latest)

Website: [jan-glx.github.io/accelSwitch](http://jan-glx.github.io/accelSwitch)

Two tiny tools to turn toggling the mouse acceleration settings every time you are stuck with a touchpad into an easy task.
## accelSwitch
A small tool to manually toggle mouse acceleration / enhance pointer precision on Windows.

### Usage:

- turn on  mouse acceleration:  ````accelSwitch.exe on````     
- turn off  mouse acceleration: ````accelSwitch.exe off````   
- toggle   mouse acceleration: ````accelSwitch.exe```` or ````accelSwitch.exe toggle````

## accelSwitcher
A small tool with no user interface that will *automatically* turn off mouse acceleration when a usb mouse is plugged in and turn on mouse acceleration when a usb mouse is removed. 

### Usage:
Put ````accelSwitcher.exe```` into the folder ````shell:startup```` to run it automatically at login or start it manually with a double click once for a session. Ending it is possible via the task manager only.
