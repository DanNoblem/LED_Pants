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

