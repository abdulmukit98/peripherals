### pin 
builtin led D4    GPIO2

![](https://github.com/abdulmukit98/peripherals/blob/main/images/NodeMCUv3.0-pinout.jpg)

### firebase
[visualize] (https://www.youtube.com/watch?v=EsCkSNrWyq8&t=522s)

* Esp8266 Board  2.7.4 version
* FirebaseArduino library (https://github.com/abdulmukit98/peripherals/blob/main/esp8266/firebase-arduino-master.zip)
* Change with latest fingerprint
    * weblink (https://www.grc.com/fingerprints.htm)
    * type "test.firebaseio.com"
    * Documents --> Arduino --> libraries --> firebase-arduino-master --> src --> FirebaseHttpClient.h
    * replace with updated fingerprint
* Install AdruinoJson library by Benoit Blanchon version 5.13.1


|library          |         version |
|-----------      |---------------- |
|Esp8266 board    | 2.7.4           |
| FirebaseArduino | [old version](https://github.com/abdulmukit98/peripherals/blob/main/esp8266/firebase-arduino-master.zip)     |
| ArduinoJson     | 5.13.1          |

<br><br>


* Code
    - Firebase_Host: the website that appear on realtime database.
    - Firebase_Auth: Project settings --> Service accounts --> Database secrets

```
#define FIREBASE_HOST "techshopju-default-rtdb.firebaseio.com"          
#define FIREBASE_AUTH "uxzCFIynuAb3bsSY3tlnWf31u184BtmpazrnyJa0"        
#define WIFI_SSID "Smart"
#define WIFI_PASSWORD "password"
```
