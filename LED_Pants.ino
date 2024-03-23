#include <Adafruit_NeoPixel.h>
#include "ZAnimation.h"
#include "Timeline.h"

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    5

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 262

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

Animation blink(1,10);



void setup() {
  // put your setup code here, to run once:

  strip.begin();
  strip.show();
  strip.setBrightness(255);
}

void loop() {

}

void lightFade(uint32_t color, int time) {
  for(int i = 0; i<255;i++){
    strip.fill(color);
    strip.setBrightness(i);
    strip.show();
    //delay(time);
  }
}

  void pulse(uint32_t color, int count){
    for(int i = 0; i < count; i++){
      if(i%2==0){
        strip.fill(color);
      } else{
        strip.fill(strip.Color(0,0,0));
      }
      strip.show();
      delay(100);
    }
  }


void chase(uint32_t c, uint32_t c2, int length){
  strip.fill(c);
  int max = strip.numPixels()/4;
  for(int i = 0; i < max + length; i++){
    strip.setPixelColor(i, c2);
    // strip.fill(c2, i+1, i+length);

    strip.setPixelColor(max*2 - i, c2);
    // strip.fill(c2, i+1+ max, i+length+ max);

    strip.setPixelColor(i + max*2, c2);
    // strip.fill(c2, i+1+ max*2, i+length+ max*2);

    strip.setPixelColor(max*4 - i, c2);
    // strip.fill(c2, i+1+ max*3, i+length+ max*3);

    strip.show();
    delay(100);
  }
}

