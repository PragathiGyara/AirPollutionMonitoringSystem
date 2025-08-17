import paho.mqtt.client as mqtt

# MQTT broker settings
mqtt_broker = "test.mosquitto.org"
mqtt_port = 1883
mqtt_topic = "sensor/data"

# Callback function for when a connection is established
def on_connect(client, userdata, flags, rc):
    print("Connected to MQTT broker")
    # Subscribe to the MQTT topic
    client.subscribe(mqtt_topic)

# Callback function for when a message is received
def on_message(client, userdata, msg):
    print(f"Received message: {msg.payload.decode()}")

# Create a MQTT client instance
client = mqtt.Client()

# Set the callback functions
client.on_connect = on_connect
client.on_message = on_message

# Connect to the MQTT broker
client.connect(mqtt_broker, mqtt_port, 60)

# Loop to maintain the connection and process incoming messages
client.loop_forever()
