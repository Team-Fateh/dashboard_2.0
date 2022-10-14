#include<CAN.h>
#include <FastLED.h>
#include <SD.h>
#include <SPI.h>

#define crank_pin 28
#define kill_pin 26
#define undefined_pin 24
#define cs_sd    53         //sd
#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3
#define gear_pin 21       //gear
#define LED_PIN     7    //LED
#define NUM_LEDS    19

#define SPEED_PIN   3     //speed
#define wheelRadius  0.117
#define spokeangle  60

File sdcard_file;             //sd
unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
unsigned long can_check_time = 2000, last_can_check_time = 0;
int can_available = 0;// toggled in can green and can red
int gear;                     //gear
long dur;
CRGB leds[NUM_LEDS];          //LED
int light=0;
int ledDur,ledOldDur,red;//
 char comm;


  float value=0,srev=0;                //Speed
long unsigned int srpm,oldtime=0,tim,wheelSpeed;
long unsigned int newStime,Stime,oldStime;


void setup(){
  
    Serial.begin(9600);
    Serial3.begin(9600);
    Serial2.begin(9600);          //Lora

    engineSetup();                //Engine
    sdInit();                     //sd
    canSetup(cs,in,canFreq,clockFreq);        //CAN
    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);//LED

    attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,RISING);
}
    
void loop(){
    
   loraCheck();               //lora

   
   dur= pulseIn(21,HIGH);     //gear
    hmiGear();
   
   sdData();
   getCAN(&RPM,&TEMP,&VOLT);    //CAN
    hmiCAN();   
    
   showLightDis();               //  //LED
//getSpeed2();
hmiSpeed();
// Serial.print(wheelSpeed);

Serial.println(millis());
canCheck();
}
