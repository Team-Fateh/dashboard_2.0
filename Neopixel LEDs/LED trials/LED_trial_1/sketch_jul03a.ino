//#include<FastLED.h>
//
//#define led_num  19
//#define led_pin  31
//
//CRGB leds[led_num];
//
//void setup() {
//   FastLED.addLeds<WS2812, led_pin, GRB>(leds, led_num);
//    FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
//    FastLED.clear();
//    FastLED.show();
//}
//
//void loop() {
//  leds[0] = CRGB(255,0,0);
//  leds[1] = CRGB(0,255,0);
//  leds[2] = CRGB(0,0,255);
//
//  FastLED.show();
//}
//#include <FastLED.h>
//
//#define LED_PIN     7
//#define NUM_LEDS    19
//
//CRGB leds[NUM_LEDS];
//
//void setup() {
//
//  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
//  pinMode(A5,INPUT);
//  Serial.begin(9600);  
//}
//void loop() {
//  int x = analogRead(A5);
//  
//  x=map(x, 0,1023, 0,19);
//  Serial.println(x);
//  FastLED.clear();
//  FastLED.fill_solid(leds[0],19,CRGB(0.70*x,255-(0.70*x),0));
//  FastLED.show();
//}
//}
#include <FastLED.h>

#define LED_PIN     31
#define NUM_LEDS    19

CRGB leds[NUM_LEDS];

void setup() {

  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  pinMode(A5,INPUT);
  Serial.begin(9600);
  
}
long ms=0;
int x = 0;
int y=0;
void loop() {

  if(millis()-ms>=8){
  x=x+50;
  ms=millis();
  }
  if(x>=1023)
  x=0;
  y=map(x, 0,1023, 0,19);
  FastLED.clear();
for (int i=0; i<=y; i++){
  
  leds[i]=CRGB(13.42*y,255-(13.42*y),0);

}FastLED.show();
Serial.println(x);
}
