#ifndef RGB_DISPLAY_H
#define RGB_DISPLAY_H

#include "config.h"

/* Custom board
#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27
#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13
#define A_PIN 23
#define B_PIN 19
#define C_PIN 5
#define D_PIN 17
#define E_PIN 32 
#define LAT_PIN 4
#define OE_PIN 15
#define CLK_PIN 16
*/

#define R1_PIN 25
#define G1_PIN 26
#define B1_PIN 27
//GND
#define R2_PIN 14
#define G2_PIN 12
#define B2_PIN 13
#define E_PIN 18 
#define A_PIN 23
#define B_PIN 19
#define C_PIN 5
#define D_PIN 17
#define CLK_PIN 16
#define LAT_PIN 4
#define OE_PIN 15
//E' or GND

/*
4 5 
12 13 14 15 16 17 18 19
23 25 26 27

free:
2
21 22 --> I2C
32 33 

TODO: 
JTAG: 15 14 13 12
*/

#define MATRIX_WIDTH PANEL_WIDTH
#define MATRIX_HEIGHT PANEL_HEIGHT
#define NUM_LEDS PANEL_WIDTH*PANEL_HEIGHT

#include <ESP32-HUB75-MatrixPanel-I2S-DMA.h>

uint16_t colorWheel(uint8_t pos); 
//void drawText(int colorWheelOffset);
void display_init();
//void display_drawText();
void logStatusMessage(const char *message);
void logStatusMessage(String message);
void clearStatusMessage();
void displaySensorData();
void displayLightData(float luxValue);
void displayTest(int delayMs);

#endif
