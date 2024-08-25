#include <WiFi.h>
#include <ESP32CAM.h>
#include <PubSubClient.h>

#define MOTION_SENSOR_PIN 2

const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* mqtt_server = "your_MQTT_BROKER_IP";

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  pinMode(MOTION_SENSOR_PIN, INPUT);
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
}

void setup_wifi() {
  delay(10);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println(" connected");
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  int motionDetected = digitalRead(MOTION_SENSOR_PIN);
  if (motionDetected == HIGH) {
    // Capture image
    captureImage();
    // Publish alert
    client.publish("security/alert", "Motion detected!");
    delay(10000); // Delay to avoid multiple alerts
  }
}

void captureImage() {
  // Capture image code using ESP32CAM library
  // Save image to cloud storage or send to a server
}

void reconnect() {
  while (!client.connected()) {
    if (client.connect("ESP32Client")) {
      client.subscribe("security/alert");
    } else {
      delay(5000);
    }
  }
}
