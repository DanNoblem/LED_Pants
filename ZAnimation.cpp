#include "Arduino.h"
#include "ZAnimation.h"
#include <Adafruit_NeoPixel.h>

Animation::Animation(int startBeat, int endBeat) {
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
    if (currentTime % 2 == 0) {
        strip.setBrightness(0);
    } else {
        strip.setBrightness(255);
    }
}

// void Animation::fade(uint64_t color1, uint64_t color2, Adafruit_NeoPixel &strip, int &currentTime) {
//     setTime();
//     while ((currentTime + duration) % startTime < duration) {
//         int point = currentTime % startTime;
//         int m = map(point, 0, endTime, color1, color2);
//         strip.fill(strip.ColorHSV(m, 255, 255));
//     }
// }
