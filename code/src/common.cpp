#include "config.h"
#include "common.h"
#include "mqtt.h"
#include "rgb_display.h"

#ifdef MQTT_USE_SSL
WiFiClientSecure wifiClient;
#else
WiFiClient wifiClient;
#endif
int status = WL_IDLE_STATUS;

// Initialize MQTT client
PubSubClient client(wifiClient);

//Time of last status update
unsigned long lastStatusSend = 0;

//Time of last client.loop()
unsigned long lastLoop = 0;
//Time of last weather sensor data receive
unsigned long lastSensorRead = 0;
//Time of last light sensor read
unsigned long lastLightRead = 0;


// NTP
const int8_t timeZone = 2;
const int8_t minutesTimeZone = 0;
bool wifiFirstConnected = false;
//Current time
struct tm timeinfo;

// Display
MatrixPanel_I2S_DMA *dma_display = nullptr;

// Flags to trigger display updates
bool clockStartingUp = true;
bool newSensorData = false;
bool sensorDead = true;

//Heartbeat marker
bool heartBeat = true;

//Log message persistence
//Is a log message currently displayed?
bool logMessageActive = false;
//When was the message shown?
unsigned long messageDisplayMillis = 0;

// Sensor data
float sensorTemp;
int sensorHumi;
