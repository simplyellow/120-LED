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

//
// separate IR led grounds from arduino ground
//

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
  for(int j  = 0; j < NUM_LEDS; j++) {
    if(!value1) {
      leds1[j].setRGB(255, 0, 0); //red
    } else {
      leds1[j].setRGB(0, 0, 0);
    }
    if(!value2) {
      leds2[j].setRGB(0, 0, 255); //blue
    } else {
      leds2[j].setRGB(0, 0, 0);
    }
    FastLED.show();
    delay(5);
  }
}
