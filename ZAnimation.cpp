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

void lightFade(uint32_t color, long duration) {
  long startTime = millis();
  long currentTime = millis() % startTime;
  while(currentTime < duration){ 
    int currentTime = millis() - startTime;
    strip.fill(color);
    int l = map(currentTime, 0, duration, 0, 255);
    strip.setBrightness(l);
    strip.show();
  };
}

void Animation::lightFade2(uint32_t color, uint32_t color2, long duration) {
  long startTime = millis();
  long currentTime = millis() % startTime;

  uint8_t r1 = color >> 16;
  uint8_t r2 = color2 >> 16;

  uint8_t g1 = color >> 8;
  uint8_t g2 = color2 >> 8;

  uint8_t b1 = color;
  uint8_t b2 = color2;

  while(currentTime < duration){ 
    int currentTime = millis() - startTime;

    int r = map(currentTime, 0, duration, r1, r2);
    int g = map(currentTime, 0, duration, g1, g2);
    int b = map(currentTime, 0, duration, b1, b2);

    strip.fill(strip.Color(r,g,b));
    strip.show();
  };
};
