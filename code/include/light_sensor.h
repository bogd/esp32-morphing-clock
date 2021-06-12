#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include <Adafruit_TSL2591.h>

void tslConfigureSensor();

float tslGetLux();

#endif