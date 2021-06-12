#ifndef BUZZER_H
#define BUZZER_H

#include "config.h"
#include <Arduino.h>

void buzzer_init();
void buzzer_tone(double freq, uint32_t durationMs);


#endif