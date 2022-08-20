#include<CAN.h>
#include <FastLED.h>

#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3
#define gear_pin 21       //gear
#define LED_PIN     7    //LED
#define NUM_LEDS    19
#define SPEED_PIN   3
#define wheelRadius  0.26

unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
int gear;                     //gear
long dur;
CRGB leds[NUM_LEDS];          //LED
int light=0;
float value=0;                //Speed
float srev=0;
int srpm;
int oldtime=0;        
int time;
int wheelSpeed;

void setup(){
  
    Serial.begin(9600);
    Serial3.begin(9600);
    
    canSetup(cs,in,canFreq,clockFreq);        //CAN
    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);//LED
    pinMode(SPEED_PIN,INPUT_PULLUP);
    attachInterrupt(digitalPinToInterrupt(SPEED_PIN),isr,RISING);
    
    
}
    
void loop(){
  
   
   dur= pulseIn(21,HIGH);     //gear
    hmiGear();
   
   getCAN(&RPM,&TEMP,&VOLT);    //CAN
    hmiCAN();   
    
   showLightDis();                 //LED



}
