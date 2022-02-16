### peripheral
    [openHAB] Please use the following commands to launch openHAB on a system restart.
                sudo /bin/systemctl daemon-reload
                sudo /bin/systemctl enable openhab2.service

    [openHAB] You can start openhab2 manually by executing the command:
                sudo /bin/systemctl start openhab2.service


### kicad part


| symbol type | name              | footprint name           |
|------------ |------------------ |------------------------- |
| pin header  |  conn_01_03       | Connector_pinheader 2.54 |
|             |                   |  Connector_pinsocket|
| Battery     | battery holder    | 2xAA              |
| barrel jack | BarrelJack Mountingpin | connector_barrelJack Horizontal | 
| Screw terminal | | Terminal block bornier | 
| push button | SW_push           | sw push 12mm        |
| resistor    | R_Axial_xx        | L6.3mm, P 7.62/10.16|
|             | ver              | L6.3mm, P 2.54/5.08 |
| capacitor  |     radial         | D12.5_5mm              |
|led small   |  led               | led tht: led_d5.0mm    |
|LDR         |  10x8 / 5.1x4.3   |  **OptoDevice**: R_LDR_ |
<br>
 
 Track | Width 
 -------|------
 Tack1  | 0.1524 mm
 Tack2  | 0.254 mm
 Tack3  | 0.381 mm
 Tack4  | 0.508 mm
 Tack5  | 0.8128 mm 
<br>

Via     |  Diameter  |  Drill
--------|------------|-----------
Via1    | 0.4826 mm  | 0.3302 mm
Via2    | 0.5 mm     | 0.4 mm
Via3    | 1.905 mm   | 0.254 mm
<br>

Resistor, Horizontal, Vertical
* 3.6mm - 0.125 watt
* 6.3mm - 0.25 watt
* 9mm - 0.5 watt


### ut33b fuse
315mA 250V  5x20 mm<br>

 
