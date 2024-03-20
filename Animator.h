#ifndef Animator_h
#define Animator_h
#include "Arduino.h"
class Animator {
	public:
		Animator(int bpm);
    void addAnimation();
    void playAnimation();
	private:
    int bpm;
    long currentTime;
}

#endif