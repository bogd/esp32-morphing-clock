#include "common.h"
#include "digit.h"
#include "rgb_display.h"
#include "clock.h"

/*
Digit digit0(0, 80 - 1 - 11*1, CLOCK_Y, CLOCK_DIGIT_COLOR);
Digit digit1(0, 80 - 1 - 11*2, CLOCK_Y, CLOCK_DIGIT_COLOR);
Digit digit2(0, 80 - 4 - 11*3, CLOCK_Y, CLOCK_DIGIT_COLOR);
Digit digit3(0, 80 - 4 - 11*4, CLOCK_Y, CLOCK_DIGIT_COLOR);
Digit digit4(0, 80 - 7 - 11*5, CLOCK_Y, CLOCK_DIGIT_COLOR);
Digit digit5(0, 80 - 7 - 11*6, CLOCK_Y, CLOCK_DIGIT_COLOR);
*/

// The Y axis starts at the bottom for the MorphingClock library... :(
Digit digit5(0, CLOCK_X,                                                 PANEL_HEIGHT-CLOCK_Y-2*(CLOCK_SEGMENT_HEIGHT)-3, CLOCK_DIGIT_COLOR);
Digit digit4(0, CLOCK_X + (CLOCK_SEGMENT_WIDTH+CLOCK_SEGMENT_SPACING),   PANEL_HEIGHT-CLOCK_Y-2*(CLOCK_SEGMENT_HEIGHT)-3, CLOCK_DIGIT_COLOR);
Digit digit3(0, CLOCK_X+2*(CLOCK_SEGMENT_WIDTH+CLOCK_SEGMENT_SPACING)+3, PANEL_HEIGHT-CLOCK_Y-2*(CLOCK_SEGMENT_HEIGHT)-3, CLOCK_DIGIT_COLOR);
Digit digit2(0, CLOCK_X+3*(CLOCK_SEGMENT_WIDTH+CLOCK_SEGMENT_SPACING)+3, PANEL_HEIGHT-CLOCK_Y-2*(CLOCK_SEGMENT_HEIGHT)-3, CLOCK_DIGIT_COLOR);
Digit digit1(0, CLOCK_X+4*(CLOCK_SEGMENT_WIDTH+CLOCK_SEGMENT_SPACING)+6, PANEL_HEIGHT-CLOCK_Y-2*(CLOCK_SEGMENT_HEIGHT)-3, CLOCK_DIGIT_COLOR);
Digit digit0(0, CLOCK_X+5*(CLOCK_SEGMENT_WIDTH+CLOCK_SEGMENT_SPACING)+6, PANEL_HEIGHT-CLOCK_Y-2*(CLOCK_SEGMENT_HEIGHT)-3, CLOCK_DIGIT_COLOR);

int prevss = 0;
int prevmm = 0;
int prevhh = 0;

void displayClock() {
    int hh = timeinfo.tm_hour;
    int mm = timeinfo.tm_min;
    int ss = timeinfo.tm_sec;
    delay(500);

    if (clockStartingUp) { // If we didn't have a previous time. Just draw it without morphing.
      digit0.Draw(ss % 10);
      digit1.Draw(ss / 10);
      digit2.Draw(mm % 10);
      digit3.Draw(mm / 10);
      digit4.Draw(hh % 10);
      digit5.Draw(hh / 10);
      digit1.DrawColon(CLOCK_DIGIT_COLOR);
      digit3.DrawColon(CLOCK_DIGIT_COLOR);
      displayDate();
      clockStartingUp = false;
    }
    else {
      // epoch changes every miliseconds, we only want to draw when digits actually change.
      if (ss!=prevss) { 
        int s0 = ss % 10;
        int s1 = ss / 10;
        if (s0!=digit0.Value()) digit0.Morph(s0);
        if (s1!=digit1.Value()) digit1.Morph(s1);
        prevss = ss;
      }

      if (mm!=prevmm) {
        int m0 = mm % 10;
        int m1 = mm / 10;
        if (m0!=digit2.Value()) digit2.Morph(m0);
        if (m1!=digit3.Value()) digit3.Morph(m1);
        displayDate();
        prevmm = mm;
      }
      
      if (hh!=prevhh) {
        int h0 = hh % 10;
        int h1 = hh / 10;
        if (h0!=digit4.Value()) digit4.Morph(h0);
        if (h1!=digit5.Value()) digit5.Morph(h1);
        prevhh = hh;
      }
    }
}

void displayDate() {
    dma_display->fillRect(DOW_X, DOW_Y, DATE_WIDTH, DATE_HEIGHT, 0);

    dma_display->setTextSize(1);     // size 1 == 8 pixels high
    dma_display->setTextWrap(false); // Don't wrap at end of line - will do ourselves
    dma_display->setTextColor(DATE_COLOR);

    dma_display->setCursor(DOW_X, DOW_Y);
    dma_display->print(&timeinfo, "%a");

    dma_display->setCursor(DATE_X, DATE_Y);
    dma_display->print(&timeinfo, "%d.%m");
}
