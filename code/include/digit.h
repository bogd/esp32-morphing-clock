#ifndef DIGIT_H
#define DIGIT_H

#include <Arduino.h>
#include "rgb_display.h"

class Digit {
  
  public:
    Digit(byte value, uint16_t xo, uint16_t yo, uint16_t color);
    void Draw(byte value);
    void Morph(byte newValue);
    byte Value();
    void DrawColon(uint16_t c);
    
  private:
    byte _value;
    uint16_t _color;
    uint16_t xOffset;
    uint16_t yOffset;
    int animSpeed = CLOCK_ANIMATION_DELAY_MSEC;

    void drawPixel(uint16_t x, uint16_t y, uint16_t c);
    void drawFillRect(uint16_t x, uint16_t y, uint16_t w, uint16_t h, uint16_t c);
    void drawLine(uint16_t x, uint16_t y, uint16_t x2, uint16_t y2, uint16_t c);
    void drawSeg(byte seg);
    void Morph2();
    void Morph3();
    void Morph4();
    void Morph5();
    void Morph6();
    void Morph7();
    void Morph8();
    void Morph9();
    void Morph0();
    void Morph1();
};

#endif