#ifndef Animation_h
#define Animation_h
#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class Animation: public Timeline{
  public:
      enum animations{
      BLINK, FADE, CHASE
    };
    void blink();
    void fade();
    void chase();

  private:


}
#endif