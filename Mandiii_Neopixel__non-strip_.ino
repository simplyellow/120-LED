#include <FastLED.h>
#define NUM_LEDS 5
#define DATA_PIN1 10
#define DATA_PIN2 11
CRGB leds1[NUM_LEDS];
CRGB leds2[NUM_LEDS];
int i = 1;

// one for weapon, one for bot as whole
#define sw1 12
#define sw2 9

void setup() { 
       pinMode(sw1, INPUT);
       pinMode(sw2, INPUT);
       FastLED.addLeds<NEOPIXEL, DATA_PIN1>(leds1, NUM_LEDS);
       FastLED.addLeds<NEOPIXEL, DATA_PIN2>(leds2, NUM_LEDS);
       FastLED.setBrightness(65);
}

void loop() { 
  if(digitalRead(sw1) == 0) {
        leds1[i%NUM_LEDS] = CRGB::Green;
  }
  if(digitalRead(sw2) ==0) {
        leds2[i%NUM_LEDS] = CRGB::Purple;
  }
        FastLED.show(); 
  if(digitalRead(sw1) == 0) {
        leds1[(i-1)%NUM_LEDS] = CRGB::Black;
  }
  if(digitalRead(sw2) == 0) {
        leds2[(i-1)%NUM_LEDS] = CRGB::Black;
  }
        i++;
        delay(75); 
}
