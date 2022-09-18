#include<CAN.h>
#include <FastLED.h>


#define crank_pin 28
#define kill_pin 26
#define undefined_pin 24
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

unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
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

    engineSetup();
    canSetup(cs,in,canFreq,clockFreq);        //CAN
    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);//LED

//    attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,LOW);
}
    
void loop(){
    
   if(Serial2.available()){
   comm = Serial2.read();
    if(comm=='c'){
      crank();
      comm='a';
    }
    if(comm=='k'){
      kill();
      comm='a';
    }
    if(comm=='d'){
      loraDataSend();
    }
    else{
    comm='a';
    }
   }

   
   dur= pulseIn(21,HIGH);     //gear
    hmiGear();
   
   getCAN(&RPM,&TEMP,&VOLT);    //CAN
    hmiCAN();   
    
   showLightDis();               //  //LED
getSpeed2();
hmiSpeed();
Serial.print(wheelSpeed);

}
