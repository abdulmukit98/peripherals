### driver
```
device manager --> view --> show hidden device
For arduino due
        install Arduino SAM Boards (32-bit ARM Cortex M3) package

For esp8266
File --> Preference -->                 
        https://arduino.esp8266.com/stable/package_esp8266com_index.json 

Tool --> Board --> Boards manager --> esp8266  <br>
version 2.7.4

```


### config
<br>

| board name   |   processor                      | baud rate | port on linux  | 
|--------------|------------------------------    |-----------|----------------|
| arduino nano | atmega328p (**old bootloader**)  | 9600      | dev/ttyUSB0    |
| esp8266      | NodeMCU 1.0 (ESP-12E Module)     |  115200   | dev/ttyUSB0    |
| due          | arduin due (programming port)    | 9600      | **dev/ttyACM0**|
| uno          |                                  | 9600      | dev/ttyACM (Arduino Uno) |     


**dev/ttyAMA0 ** is **linux** default port

### ch340 driver
* [exe](https://github.com/abdulmukit98/peripherals/blob/main/port/CH341SER.EXE)
* [zip](https://github.com/abdulmukit98/peripherals/blob/main/port/CH341SER.ZIP)
