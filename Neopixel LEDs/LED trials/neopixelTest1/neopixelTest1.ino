#include <FastLED.h>

int LED_pin = 31;
int LED_num = 19;

CRGB leds[19];

void setup{
    FastLED.addLeds<WS2812, LED_PIN, RGB>(leds, NUM_LEDS);
    FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
    FastLED.clear();
    FastLED.show();
}

void loop{
  leds[0] = CRGB(255,0,0);
  leds[0] = CRGB(0,255,0);
  leds[0] = CRGB(0,0,255);

  FastLED.show();
}
