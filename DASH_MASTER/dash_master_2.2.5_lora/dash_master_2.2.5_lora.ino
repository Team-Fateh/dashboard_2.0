#include<CAN.h>
#include <FastLED.h>

#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3
#define gear_pin 21       //gear
#define LED_PIN     7     //LED
#define NUM_LEDS    19
#define SPEED_PIN   3     //speed
#define wheelRadius  0.117
#define spokeangle  46
unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
int gear;                     //gear
long dur;
CRGB leds[NUM_LEDS];          //LED
int light=0,red;
long unsigned int ledDur=0, ledOldDur=0;         

void setup(){
    millis();
    Serial.begin(9600);                       //Debugging
    Serial3.begin(9600);                      //HMI
    canSetup(cs,in,canFreq,clockFreq);        //CAN
    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  //LED
    
}
    
void loop(){
   
   dur= pulseIn(21,HIGH);         //gear
    hmiGear();
   
   getCAN(&RPM,&TEMP,&VOLT);      //CAN
    hmiCAN();   
    
    
    showLightDis();               //LED
    hmiTempRed();                 //HMI

}
