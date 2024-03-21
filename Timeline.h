#ifndef Timeline_h
#define Timeline_h
#include "Arduino.h"
class Timeline {
	public:
		Timeline(int bpm);
    void addAnimation();
    void playAnimation();

	private:
    int bpm;
    long currentTime;
}

#endif