// Indicator light strips for 60-lb battlebot
// 5s and 12s power rails

#include <FastLED.h>

const byte data_pin1 = 0;
const byte data_pin2 = 1;
const byte weapon = 3;
const byte drive = 4;
const byte num_leds = 1;
boolean weapon_on = false;
boolean drive_on = false;

CRGB strip1[num_leds];
CRGB strip2[num_leds];

void setup() {
  pinMode(data_pin1, OUTPUT);
  pinMode(data_pin2, OUTPUT);
  pinMode(weapon, INPUT);
  pinMode(drive, INPUT);
  FastLED.addLeds<WS2812, data_pin1, RGB>(strip1, num_leds);
  FastLED.addLeds<WS2812, data_pin2, RGB>(strip2, num_leds);
  FastLED.setBrightness(65);
}

void loop() {
  weapon_on = digitalRead(weapon);
  drive_on = digitalRead(drive);
  for(int i = 0; i < num_leds; i++) {
    if(weapon_on) {
      strip1[i].setRGB(0, 255, 0);
    } else {
      strip1[i].setRGB(255, 0, 0);
    }
    if(drive_on) {
      strip2[i].setRGB(0, 255, 0);
    } else {
      strip2[i].setRGB(255, 0, 0);
    }
    FastLED.show();
    delay(5);
  }
}
