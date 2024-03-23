#ifndef Timeline_h
#define Timeline_h
#include "Arduino.h"
class Timeline {
	public:
		Timeline(int bpm);
    void addAnimation(int startBeat, int endBeat, Adafruit_NeoPixel light); //animation type needed
    void playAnimation();

	private:
    int bpm;
    long currentTime;
};

#endif