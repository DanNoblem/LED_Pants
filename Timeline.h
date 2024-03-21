#ifndef Timeline_h
#define Timeline_h
#include "Arduino.h"
class Timeline {
	public:
		Timeline(int bpm);
    void addAnimation();
    void playAnimation();
    enum animations{
      BLINK, FADE, CHASE
    }
	private:
    int bpm;
    long currentTime;
}

#endif