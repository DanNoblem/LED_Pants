#include <Adafruit_NeoPixel.h>
#include "Arduino.h"
#include "Timeline.h"

Timeline::Timeline() {
  int currentTime = millis();
  std::map<std::string, Adafruit_NeoPixel> strips = {};
}

void addLEDAccessory(std::string name, uint8_t pin = 8, uint8_t numLEDs = 262) {

}

void Timeline::addLEDAccessory(std::string name, uint8_t pin, uint8_t numLEDs) {
  strips[name] = Adafruit_NeoPixel(numLEDs, pin, NEO_GRB + NEO_KHZ800);
}

// void Timeline::addRoutine(int bpm, Animation[] animations) {
// }

void Timeline::addAnimation(int startBeat, int endBeat, Adafruit_NeoPixel light) {

}

void Timeline::playAnimation() {

}