#include "light_sensor.h"

Adafruit_TSL2591 tsl = Adafruit_TSL2591(2591);

void tslConfigureSensor(){
  // You can change the gain on the fly, to adapt to brighter/dimmer light situations
  //tsl.setGain(TSL2591_GAIN_LOW);    // 1x gain (bright light)
  tsl.setGain(TSL2591_GAIN_MED);      // 25x gain
  //tsl.setGain(TSL2591_GAIN_HIGH);   // 428x gain
  
  // Changing the integration time gives you a longer time over which to sense light
  // longer timelines are slower, but are good in very low light situations!
  //tsl.setTiming(TSL2591_INTEGRATIONTIME_100MS);  // shortest integration time (bright light)
  //tsl.setTiming(TSL2591_INTEGRATIONTIME_200MS);
  //tsl.setTiming(TSL2591_INTEGRATIONTIME_300MS);
  //tsl.setTiming(TSL2591_INTEGRATIONTIME_400MS);
  tsl.setTiming(TSL2591_INTEGRATIONTIME_500MS);
  //tsl.setTiming(TSL2591_INTEGRATIONTIME_600MS);  // longest integration time (dim light)
}

float tslGetLux() {
    /* Get a new sensor event */ 
    sensors_event_t event;
    tsl.getEvent(&event);
    
    if ((event.light == 0) |
        (event.light > 4294966000.0) | 
        (event.light <-4294966000.0))
    {
        return -1;
    }
    else
    {
        return event.light;
    }
}