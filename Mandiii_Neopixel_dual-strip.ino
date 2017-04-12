/*
 * Mandiii Neopixel Indicator Lights for Robogames 2017
 */
#include <FastLED.h>
#define NUM_LEDS 19   // preferably even
#define DATA_PIN 6
CRGB leds[NUM_LEDS];
/*
 * Digital pins for the two identical power indication circuits
 * One for the bot as a whole
 * One for the weapon
 */
#define sw1 7
#define sw2 8
boolean wep = false;
int i = 1;
boolean bot = false;

void setup() { 
  // pin setup
  pinMode(sw1, INPUT);
  pinMode(sw2, INPUT);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  // setBrightness takes 0-255
  FastLED.setBrightness(50);
  // start-up routine- won't be lit til system is on
  while(!wep && !bot) {
    botStatus();
    drumStatus();
  }
}
/*  To light the LEDs:
 *  Set array elements to certain colors
 *  Call FastLED.show()
 */
void loop() { 
  botStatus();
  drumStatus();
  fight();
  delay(30); 
}

void botStatus() {
  if(!digitalRead(7)) {
    bot = false;
  } else {
    bot = true;
  }
}

void drumStatus() {
  if(!digitalRead(8)) {
    wep = false;
  } else {
    wep = true;
  }
}

//light pattern during fight, cylon
void fight() {  
  // 0 1 2
  if(wep) {
    leds[i%(NUM_LEDS/2)] = CRGB::Green;
  } else {
    leds[i%(NUM_LEDS/2)] = CRGB::Red;
  }
  leds[(i-1)%(NUM_LEDS/2)] = CRGB::Black;

  // 3 4 5
  if(bot) {
    leds[i%(NUM_LEDS/2) + NUM_LEDS/2] = CRGB::Green;
  } else {
    leds[i%(NUM_LEDS/2) + NUM_LEDS/2] = CRGB::Red;
  }
  leds[(i-1)%(NUM_LEDS/2) + NUM_LEDS/2] = CRGB::Black;
  
  i++;
  FastLED.show();
}

