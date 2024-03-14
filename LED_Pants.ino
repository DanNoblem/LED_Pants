#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1:
#define LED_PIN    5

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 262

// Declare our NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Declare bpm of song
int bpm = 120;

//Declare function arguments
struct FunctionArgs {
  uint32_t color;
  int duration;
};

//Manage what is happening on each beat
struct BeatAction {
  int startBeat;
  int endBeat;
  void (*action)(FunctionArgs args, bool &isRunning);
  FunctionArgs args;
};

BeatAction actions[] = {
  {4, 8, colorWipe, {strip.Color(255, 0, 0), 50}}  // Example: Red colorWipe on beats 4-8
};
int numActions = sizeof(actions)/sizeof(actions[0]);

void setup() {
  // put your setup code here, to run once:

  strip.begin();
  strip.show();
  strip.setBrightness(255);
}

void loop() {
  // put your main code here, to run repeatedly:
  //colorWipe(strip.Color(255,   0,   0), 50);
  // colorFade(100);
  // pulse(strip.Color(255,0,0), 50);
  // lightFade(strip.Color(255,255,0), 10);
  // chase(strip.Color(75, 255, 255), strip.Color(255, 120, 150), 10);

  static unsigned long lastBeatTime = 0;
  int beatInterval = 60000 / bpm;
  unsigned long currentTime = millis();
  static bool isRunning[numActions] = {false};

  int currentBeat = ((currentTime - lastBeatTime) / beatInterval) + 1;

  for(int i = 0; i < numActions; i++) {
    if (currentBeat >= actions[i].startBeat && currentBeat <= actions[i].endBeat) {
      actions[i].action(actions[i].args, isRunning[i]);
    } else if (currentBeat > actions[i].endBeat && isRunning[i]) {
      isRunning[i] = false;
    }
  }

  if (currentBeat > actions[numActions - 1].endBeat) {
    lastBeatTime = currentTime;
  }

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

void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void colorFade(int time){
  for(int i = 0; i < 65535; i+=500){
    strip.fill(strip.ColorHSV(i,255,255));
    strip.show();
    delay(time);
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


int getCellNumber(int row, int col) {
  return row % 2 == 0 ? 8 * row + col : 8 * row + (7-col);
}
