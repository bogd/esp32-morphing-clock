#ifndef MQTT_H
#define MQTT_H

#include <Arduino.h>

#define MQTT_BUFMAX 200

void mqtt_callback(char* topic, byte* payload, unsigned int length);
void reconnect();

#endif