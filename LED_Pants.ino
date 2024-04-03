#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    5

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 240

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  strip.begin();
  strip.show();
  strip.setBrightness(100);
}

void loop() {
  //Section 1 pants

  fill(strip.Color(0,150,200), beat2millis(4,120)); //light blue
  lightFade2(strip.Color(0,150,200), strip.Color(150,0,255),  beat2millis(1,120)); //fade to purple
  fill(strip.Color(150,0,255), beat2millis(4,120)); //purple
  lightFade2(strip.Color(150,0,200), strip.Color(0,150,255),  beat2millis(1,120)); //fade to blue
  fill(strip.Color(0,150,255), beat2millis(4,120));
  twinkle(strip.Color(0,150,200),strip.Color(150,0,255), 5000);

  //Section 2 pants
  fill(strip.Color(255,0,0), beat2millis(2,100)); //color 1 red
  fill(strip.Color(150,50,0), beat2millis(2,100)); //color 2 orange
  fill(strip.Color(150,100,0), beat2millis(2,100)); //color 3 yellow
  fill(strip.Color(150,50,0), beat2millis(2,100)); //color 2
  breathe(strip.Color(255,0,0), beat2millis(16,100));
  breathe(strip.Color(150,50,0), beat2millis(32,100));
  twinkle(strip.Color(150,50,0),strip.Color(255,0,0), beat2millis(32,100));


  //TESTING ///////////////////////
  // twinkle(strip.Color(0,150,200),strip.Color(150,0,255), 5000);
  // lightFade2(strip.Color(150,0,200), strip.Color(0,150,255),  beat2millis(1,120)); //fade to blue
  // lightFade2(strip.Color(0,150,200), strip.Color(150,0,255),  beat2millis(1,120)); //fade to purple
  // twinkle(strip.Color(150,50,0),strip.Color(255,0,0), beat2millis(32,100));


}

float beat2millis(float beats, float bpm){
  float duration = 0;
  bpm = 60/bpm; //seconds per beat
  duration = (beats*bpm) * 1000; //duration in milliseconds
  return duration;
}

void lightFade2(uint32_t color, uint32_t color2, long duration) {
  long startTime = millis();
  long currentTime = millis() % startTime;

  uint8_t r1 = color >> 16;
  uint8_t r2 = color2 >> 16;

  uint8_t g1 = color >> 8;
  uint8_t g2 = color2 >> 8;

  uint8_t b1 = color;
  uint8_t b2 = color2;

  while(currentTime < duration){ 
    int currentTime = millis() - startTime;

    int r = map(currentTime, 0, duration, r1, r2);
    int g = map(currentTime, 0, duration, g1, g2);
    int b = map(currentTime, 0, duration, b1, b2);

    strip.fill(strip.Color(r,g,b));
    strip.show();
    if(currentTime > duration){
      break;
    }
    yield();
  }
};
  
void blink(uint32_t color, uint32_t color2, long duration){
  long startTime = millis();
  long currentTime = 0;

  while(currentTime < duration){
    int currentTime = millis() - startTime;
    
    if(currentTime % 200 > 100){
      strip.fill(color);
    } else {
      strip.fill(color2);
    }
    strip.show();
    if(currentTime > duration){
      break;
    }
    yield();
  };
};

void fill(uint32_t color, long duration){
  long startTime = millis();
  long currentTime = 0;

  while(currentTime < duration){
    int currentTime = millis() - startTime;
    strip.fill(color);
    strip.show();
    if(currentTime > duration){
      break;
    }
    yield();
  }
  
}

void breathe(uint32_t color, long duration){
  long startTime = millis();
  long currentTime = 0;
  int j = 254;
  int m = 1;

  uint8_t r1 = color >> 16;
  uint8_t g1 = color >> 8;
  uint8_t b1 = color;

  while(currentTime < duration){
    int currentTime = millis() - startTime;

    int r = map(j, 0, 255, 0, r1);
    int g = map(j, 0, 255, 0, g1);
    int b = map(j, 0, 255, 0, b1);

    strip.fill(strip.Color(r,g,b));


    if(j == 0) {
      m = 1;
    } if(j == 255){
      m = -1;
    }

    if(currentTime % 3 == 0){
      j+=m;
    }
    strip.show();
    if(currentTime > duration){
      break;
    }
    yield();
  }
}

void chase(uint32_t color, uint32_t color2, long duration){
  long startTime = millis();
  long currentTime = 0;
  strip.fill(color2);

  while(currentTime < duration){
    int currentTime = millis() - startTime;
    int max = strip.numPixels()/4;

    int i = map(currentTime, 0, duration, 0, max);
    strip.setPixelColor(i, color);
    // strip.fill(c2, i+1, i+length);

    strip.setPixelColor(max*2 - i, color);
    // strip.fill(c2, i+1+ max, i+length+ max);

    strip.setPixelColor(i + max*2,color);
    // strip.fill(c2, i+1+ max*2, i+length+ max*2);

    strip.setPixelColor(max*4 - i, color);
    // strip.fill(c2, i+1+ max*3, i+length+ max*3);
    strip.show();
    if(currentTime > duration){
      break;
    }
    yield();
  }
}

void twinkle(uint32_t color, uint32_t color2, long duration){
  long startTime = millis();
  long currentTime = 0;
  int twinkle[strip.numPixels()];
  uint32_t twinkleColor[strip.numPixels()];

  for(int i = 0; i < strip.numPixels(); i++ ){
    twinkle[i] = random(255); //make setting into wave instead of random
    long c = random(2);
    if( c < 1){
      twinkleColor[i] = color;
    } else{
      twinkleColor[i] = color2;
    }
  }

  while(currentTime < duration){
  int currentTime = millis() - startTime;
    for(int i = 0; i < strip.numPixels(); i++ ){
      uint8_t r1 = twinkleColor[i] >> 16;
      uint8_t g1 = twinkleColor[i] >> 8;
      uint8_t b1 = twinkleColor[i];

      int r = map(twinkle[i], 0, 255, 0, r1);
      int g = map(twinkle[i], 0, 255, 0, g1);
      int b = map(twinkle[i], 0, 255, 0, b1);

      strip.setPixelColor(i, strip.Color(r,g,b));

      if(currentTime % 2 == 0){
        twinkle[i]--;
      }

      if(twinkle[i] < 1){
        twinkle[i] = 255;
        long c = random(2);
        if( c < 1){
          twinkleColor[i] = color;
        } else{
          twinkleColor[i] = color2;
        }
      }

    }
  strip.show();
    if(currentTime > duration){
      break;
    }
    yield();
  }
}

//Template
// void fill(uint32_t color, long duration){
//   long startTime = millis();
//   long currentTime = 0;

//   while(currentTime < duration){
//   int currentTime = millis() - startTime;
//   strip.show();
//     if(currentTime > duration){
//       break;
//     }
//    yield();
//   }
// }

