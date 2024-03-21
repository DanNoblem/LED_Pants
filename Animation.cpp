#include "Arduino.h"
#include "Animation.h"
#include <Adafruit_NeoPixel.h>

Animation::Animation(int startBeat, int endBeat, enum effect){
  int currentTime = mills();
  int startTime;
  int endTime;
  int duration;
}

void Animation::setTime(){
  duration = (startBeat - endBeat) * bpm;
  startTime = mills();
  endTime = startTime + duration;
}

//Custom color mapping for animations to use

void Animation::animationDuration(int startBeat, int endBeat){
  int duration = (startBeat - endBeat) * bpm;
  return duration;
}

void blink(uint64_t color){
  setTime();
  strip.fill(strip.ColorHSV(color,255,255));
  if(currentTime%2 == 0){
    strip.setBrightness(0);
  } else {
    strip.setBrightness(255);
  }
}

void fade(uint64_t color1, uint64_t color2){
  setTime();
  while((currentTime + duration) % startTime < duration){
    int point = currentTime % startTime + t
    long m = map(point, 0, endTime, color1, color2);
    strip.fill(strip.ColorHSV(m, 255,255));
  }
}