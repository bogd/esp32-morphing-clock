#ifndef COMMON_H
#define COMMON_H

#include "config.h"
#include "rgb_display.h"
#include "light_sensor.h"

#include <WiFi.h>
#include <PubSubClient.h>
#include <ESPNtpClient.h>

#ifdef MQTT_USE_SSL
#include <HTTPClient.h>
extern WiFiClientSecure wifiClient;
#else
extern WiFiClient wifiClient;
#endif

extern int status;

// Initialize MQTT client
extern PubSubClient client;

//Time of last status update
extern unsigned long lastStatusSend;

//Time of last client.loop()
extern unsigned long lastSensorRead;
extern unsigned long lastLedBlink;

//Log message persistence
//Is a log message currently displayed?
extern bool logMessageActive;
//When was the message shown?
extern unsigned long messageDisplayMillis;

// NTP
extern bool wifiFirstConnected;

extern bool syncEventTriggered; // True if a time event has been triggered

//RGB display
extern MatrixPanel_I2S_DMA *dma_display;

//Current time and date
extern struct tm timeinfo;

//Flags to trigger display section updates
extern bool clockStartingUp;
extern bool newSensorData;
extern bool sensorDead;

//The actual sensor data
extern float sensorTemp;
extern int sensorHumi;

//Just a heartbeat for the watchdog...
extern bool heartBeat;

//Light sensor
extern Adafruit_TSL2591 tsl;

#endif
