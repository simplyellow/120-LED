#include <FastLED.h>
#define NUM_LEDS 5
#define DATA_PIN1 10
#define DATA_PIN2 11
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];

// one for weapon, one for drive
#define sw1 12
#define sw2 9

int value1 = 0;
int value2 = 0;




// measure voltage between both grounds




void setup() { 
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS);
  FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds2, NUM_LEDS);
  FastLED.setBrightness(65);
}

void loop() { 
  value1 = digitalRead(sw1);
  value2 = digitalRead(sw2);

  //removes any floating LEDs if any switches turn off
  for(int i  = 0; i < NUM_LEDS; i++) {
    leds1[i] = CRGB::Black;
    leds2[i] = CRGB::Black;
    FastLED.show();
  }
  for(int j  = 0; j < NUM_LEDS; j++) {
    if(value1) {
      leds1[j].setRGB(0, 255, 255);
    }
    if(value2) {
      leds2[j].setRGB(0, 128, 255);
    }
    fadeall();
    FastLED.show();
    delay(10);
  }
  for(int k  = (NUM_LEDS)-1; k >= 0; k--) {
    if(value1) {
      leds1[k].setRGB(0, 255, 255);
    }
    if(value2) {
      leds2[k].setRGB(0, 128, 255);
    }
    FastLED.show();
    fadeall();
    delay(10);
  }
}
