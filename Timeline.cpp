#include "Arduino.h"
#include "Timeline.h"

Timeline::Timeline(int bpm) {
  _bpm = bpm;
  int currentTime = mills();
  

}
void Timeline::animationDuration(int startBeat, int endBeat){
  int duration = (startBeat - endBeat) * _bpm;
  return duration;
}
void Timeline::addAnimation(int startBeat, int endBeat, enum animation){
  
}

void Timeline::playAnimation(){
  while (currentTime % (currentTime + animationDuration) < animationDuration) {
	int count = currentTime % (currentTime + animationDuration)
	int value = map(count, 0, animationDuration, animationValue1, animationValue2)
	colorFade(count);
}
