#include "buzzer.h"
#include <Arduino.h>

void buzzer_init() {
    pinMode(BUZZER_PIN, OUTPUT);
    ledcSetup(BUZZER_PWM_CHANNEL, 1000, BUZZER_PWM_RESOLUTION);
    ledcAttachPin(BUZZER_PIN, BUZZER_PWM_CHANNEL);
}

void buzzer_tone(double freq, uint32_t durationMs) {
    ledcWrite(BUZZER_PWM_CHANNEL, 255);
    ledcWriteTone(BUZZER_PWM_CHANNEL, freq);
    delay(durationMs);
    ledcWrite(BUZZER_PWM_CHANNEL, 0);
}