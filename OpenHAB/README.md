### Mosquitto sub terminal

````
# Test if MQTT broker is running

mosquitto_sub -h localhost -t "device/led" -v
````


### Mosquitto pub
````
# From OpenHAB to NodeMCU
mosquitto_pub -h 192.168.1.100 -p 1884 -t "device/led" -m "1"
mosquitto_pub -h localhost -t "device/led" -m "1"
mosquitto_pub -h test.mosquitto.org -t "device/led" -m "1"


# From NodeMCU to OpenHAB (if publishing status)
mosquitto_pub -h 192.168.1.100 -t "device/led/state" -m "ON"

````

### port 1884
````
sudo ss -tlnp | grep 1883
sudo kill -9 19797
sudo systemctl restart mosquitto
sudo systemctl status mosquitto
````

### ffmpeg

````
mjpg_streamer -i "input_uvc.so -d /dev/video0 -r 640x480 -f 30" -o "output_http.so -p 8081 -w ./www"
````

view at
````
http://192.168.0.7:8081/?action=stream
````

### Rule 
Add Trigger
````
0/1 * 0-23 * * ?
0/5 * 8-9 * * ?
````
Breakdown:
Field	Meaning

* 0/5	Every 5 seconds
* \*	Every minute
* 8-9	Hours 08 and 09
* \* \* ?	Any day, any month, any weekday

### venv
````
# Create a virtual environment (any directory you like)
python3 -m venv ~/openhab-ml-env


# Activate it
source ~/openhab-ml-env/bin/activate

run script
~/openhab-ml-env/bin/python /home/openhab/ml_mqtt_control.py

# Deactivate venv
deactivate
````
