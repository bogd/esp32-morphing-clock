
#include <Arduino.h>
//#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#include "common.h"
#include "mqtt.h"
#include "creds_mqtt.h"
#include "ota_update.h"

char mqtt_buffer[MQTT_BUFMAX];

void mqtt_callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived
  /*
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (unsigned int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
  */

  if ( strcmp(topic, MQTT_TEMPERATURE_SENSOR_TOPIC) == 0) {
    payload[length]=0;
    sensorTemp = atof((char *)payload);
    lastSensorRead = millis();
    sensorDead = false;
    newSensorData = true;
  }

  if ( strcmp(topic, MQTT_HUMIDITY_SENSOR_TOPIC) == 0) {
    payload[length] = 0;
    sensorHumi = atoi((char *)payload);
    lastSensorRead = millis();
    sensorDead = false;
    newSensorData = true;
  }

  if ( strcmp(topic, MQTT_UPDATE_CMD_TOPIC)==0 ) {
    Serial.println("Starting update process...");
    // Start update if a 1 was received as first character
    if ((char)payload[0] == '1') {
      perform_update();
    } 
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    status = WiFi.status();
    if ( status != WL_CONNECTED) {
      WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("Connected to AP");
    }
    Serial.print("Connecting to MQTT node...");
    // Attempt to connect (clientId, username, password)
    if ( client.connect(MQTT_CLIENT_ID, MQTT_USERNAME, MQTT_PASSWORD) ) {
      Serial.println( "[DONE]" );
      Serial.println("Subscribing to topics");
      Serial.println(MQTT_UPDATE_CMD_TOPIC);
      client.subscribe(MQTT_UPDATE_CMD_TOPIC);
      client.subscribe(MQTT_TEMPERATURE_SENSOR_TOPIC);
      client.subscribe(MQTT_HUMIDITY_SENSOR_TOPIC);
    } else {
      logStatusMessage("MQTT Fail, retrying...");
      Serial.print( "[FAILED] [ rc = " );
      Serial.print( client.state() );
      Serial.println( " : retrying in 5 seconds]" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}