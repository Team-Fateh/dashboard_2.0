#include<FastLED.h>

#define led_num  21
#define led_pin  5

CRGB leds[led_num];
long unsigned int timeblink;
void setup() {
  FastLED.addLeds<WS2812B, led_pin, GRB>(leds, led_num);
   FastLED.clear();
   FastLED.show();
timeblink=millis();
}

void loop() {

if(millis()-timeblink<=250)
{
 leds[0] = CRGB(0,0,255);
 leds[1] = CRGB(0,0,255);
 leds[2] = CRGB(0,0,255);
 leds[3] = CRGB(0,0,255);
 leds[4] = CRGB(0,0,255);
 leds[5] = CRGB(0,0,255);
 leds[6] = CRGB(0,0,255);
 leds[7] = CRGB(0,0,255);
 leds[8] = CRGB(0,0,255);
 leds[9] = CRGB(0,0,255);
 leds[10] = CRGB(0,0,255);
 leds[11] = CRGB(255,0,0);
 leds[13] = CRGB(255,0,0);
 leds[14] = CRGB(255,0,0);
 leds[15] = CRGB(255,0,0);
 leds[16] = CRGB(255,0,0);
 leds[17] = CRGB(255,0,0);
 leds[18] = CRGB(255,0,0);
 leds[19] = CRGB(255,0,0);
 leds[20] = CRGB(255,0,0);
 leds[21] = CRGB(255,0,0);
 leds[12] = CRGB(255,0,0);
 FastLED.show();
}
 
if((millis()-timeblink)>=250&&(millis()-timeblink)<=500){
 leds[0] = CRGB(255,0,0);
 leds[1] = CRGB(255,0,0);
 leds[2] = CRGB(255,0,0);
 leds[3] = CRGB(255,0,0);
 leds[4] = CRGB(255,0,0);
 leds[5] = CRGB(255,0,0);
 leds[6] = CRGB(255,0,0);
 leds[7] = CRGB(255,0,0);
 leds[8] = CRGB(255,0,0);
 leds[9] = CRGB(255,0,0);
 leds[10] = CRGB(255,0,0);
 leds[11] = CRGB(0,0,255);
 leds[13] = CRGB(0,0,255);
 leds[14] = CRGB(0,0,255);
 leds[15] = CRGB(0,0,255);
 leds[16] = CRGB(0,0,255);
 leds[17] = CRGB(0,0,255);
 leds[18] = CRGB(0,0,255);
 leds[19] = CRGB(0,0,255);
 leds[20] = CRGB(0,0,255);
 leds[21] = CRGB(0,0,255);
 leds[12] = CRGB(0,0,255);
 
 FastLED.show();
} 
if (millis()-timeblink>500){

 timeblink=millis();
}
}
// #include <FastLED.h>

// #define LED_PIN     7
// #define NUM_LEDS    19

// CRGB ledans[NUM_LEDS];

// void setup() {

//  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
//  pinMode(A5,INPUT);
//  Serial.begin(9600);  
// }
// void loop() {
//  int x = analogRead(A5);
 
//  x=map(x, 0,1023, 0,19);
//  Serial.println(x);
//  FastLED.clear();
//  FastLED.fill_solid(leds[0],19,CRGB(0.70*x,255-(0.70*x),0));
//  FastLED.show();
// }
// }
// #include <FastLED.h>

// #define LED_PIN     13
// #define NUM_LEDS    19

// CRGB leds[NUM_LEDS];

// void setup() {

//   FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
//   pinMode(A5,INPUT);
//   Serial.begin(9600);
  
// }
// long ms=0;
// int x = 0;
// int y=0;
// void loop() {

//   if(millis()-ms>=8){
//   x=x+50;
//   ms=millis();
//   }
//   if(x>=1023)
//   x=0;
//   y=map(x, 0,1023, 0,19);
//   FastLED.clear();
// for (int i=0; i<=y; i++){
  
//   leds[i]=CRGB(13.42*y,255-(13.42*y),0);

// }FastLED.show();
// Serial.println(x);
// }
