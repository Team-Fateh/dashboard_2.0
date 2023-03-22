#include <FastLED.h>

int LED_PIN = 5;
int LED_NUM = 21;

CRGB leds[21];

void setup(){
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, LED_NUM);
    FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
    FastLED.clear();
    FastLED.show();
}

void loop(){
  leds[0] = CRGB(255,0,0);
  leds[0] = CRGB(0,255,0);
  leds[0] = CRGB(0,0,255);

  FastLED.show();
}
