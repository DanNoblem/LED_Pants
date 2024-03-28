#include "Arduino.h"
#include "ZAnimation.h"
#include <Adafruit_NeoPixel.h>

Animation::AnimationAdafruit_NeoPixel light, int startBeat, int endBeat) {
    startTime = millis();
    endTime = 0;
    duration = (startBeat - endBeat) * 120;
}

// Create start and end values in milliseconds
void Animation::setTime() {
    startTime = millis();
    endTime = startTime + duration;
}

// Custom color mapping for animations to use
void Animation::animationDuration(int startBeat, int endBeat, int bpm) {
    duration = (startBeat - endBeat) * bpm;
}

void Animation::blink(uint64_t color) {
    setTime();
    strip.fill(strip.ColorHSV(color, 255, 255));
    if (millis() % 2 == 0) {
        strip.setBrightness(0);
    } else {
        strip.setBrightness(255);
    }
}

void Animation::lightFade(uint32_t color, long duration) { //duration in miliiseconds
  long startTime = millis();
  long currentTime = millis() % startTime;
  while(currentTime < duration){ 
    int currentTime = millis() - startTime;
    strip.fill(color);
    int l = map(currentTime, 0, duration, 0, 255);
    strip.setBrightness(l);
    strip.show();
  };
