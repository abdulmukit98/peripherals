import paho.mqtt.client as mqtt
import time
import random  # replace this with your model’s prediction logic

BROKER = "192.168.0.7"
PORT = 1884
TOPIC = "device/led"

# Connect to MQTT
client = mqtt.Client()
client.connect(BROKER, PORT, 60)

"""
def predict():
    # Example dummy ML prediction — replace with real model
    return random.choice([0, 1])

while True:
    pred = predict()  # 0 or 1 from your ML model
    msg = "ON" if pred == 1 else "OFF"
    client.publish(TOPIC, msg)
    print(f"Published {msg} to {TOPIC}")
    time.sleep(10)
"""

while True:
    client.publish(TOPIC, "0")
    time.sleep(3)
    client.publish(TOPIC, "1")
    time.sleep(3)

