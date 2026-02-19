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

## Download log
````
grep "SmartLight" /var/log/openhab/events.log > switch_log.txt

convert log file to csv format
awk '/Generic_MQTT_Thing_Light/{print $1" "$2","$NF}' switch_log.txt > switch_data.csv
````

### Start Arduino
````
cd Downloads/
./arduino-ide_2.3.6_Linux_64bit.AppImage --no-sandbox
````

## Openhab setup
```
1. Add on store => MQTT binding

2. Setting => Thing => + => MQTT binding => MQTT Broker
Broker Hostname = 127.0.0.1
port = 1883

3. Install mosquitto on windows. 
Add mosquitto directory to system environment variable

4. check port 1883 is working
netstat -an | Select-String 1883

5. mosquitto command line
mosquitto_sub -h localhost -t device/led
mosquitto_pub -h localhost -t test/topic -m "hello"

6. Create generic mqtt thing 
Link the Broker
add channel topic device/led
set value 0 1
create item linking the channel


7. Mosquitto only listen to localhost fix
goto
C:\Program Files\mosquitto\mosquitto.conf

Add this line
    listener 1883
    allow_anonymous true

8. Add Generic MQTT thing UID to client in NodeMCU code

if (client.connect("mqtt:topic:616a0f5e1e:Thing2")) {
      Serial.println("connected");
      
      // Subscribe to the topic
      client.subscribe(mqtt_topic);
      Serial.print("Subscribed to: ");
      Serial.println(mqtt_topic);   
  }
```
