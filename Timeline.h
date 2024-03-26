#ifndef Timeline_h
#define Timeline_h

#include "Arduino.h"
#include <string>
#include <map>

class Timeline {
public:
  Timeline();
  void addLEDAccessory(std::string name, uint8_t pin, uint8_t numLEDs);
  // void addRoutine(int bpm, Animation[] animations);
  void addAnimation(int startBeat, int endBeat, Adafruit_NeoPixel light);  //animation type needed
  void playAnimation();

private:
  // map from string to Adafruit_NeoPixel strip
  std::map<std::string, Adafruit_NeoPixel> strips{};
  int bpm;
  long currentTime;
};

#endif