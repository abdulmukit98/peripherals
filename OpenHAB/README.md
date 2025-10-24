### Mosquitto sub terminal

````
# Test if MQTT broker is running

mosquitto_sub -h localhost -t "device/led" -v
````


### Mosquitto pub
````
# From OpenHAB to NodeMCU
mosquitto_pub -h 192.168.1.100 -t "device/led" -m "1"
mosquitto_pub -h localhost -t "device/led" -m "1"
mosquitto_pub -h test.mosquitto.org -t "device/led" -m "1"


# From NodeMCU to OpenHAB (if publishing status)
mosquitto_pub -h 192.168.1.100 -t "device/led/state" -m "ON"

````
