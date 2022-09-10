#include<CAN.h>
#include <FastLED.h>

#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3
#define gear_pin 21       //gear
#define LED_PIN     7     //LED
#define NUM_LEDS    19
//#define SPEED_PIN   3     //speed
//#define wheelRadius  0.117
//#define spokeangle  46
unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
//unsigned long sRPM=0;         //
int gear;                     //gear
long dur;
CRGB leds[NUM_LEDS];          //LED
int light=0,red;
long unsigned int ledDur=0, ledOldDur=0;         
//float value=0,srev=0;                //Speed
//int srpm,oldtime=0,tim,wheelSpeed;
//long unsigned int newStime,Stime,oldStime;
//
//float AngularSpeed=0;                 //speed3
//float speedkmh=0;
//float speedms=0;
//float WheelRadius= 0.234 ;
//float Circum = 16.6;
//unsigned long duration;
int brakepin = A8;
int brakevalue ;
float a ;

void setup(){
  pinMode(53,OUTPUT);
  digitalWrite(53,HIGH);
    millis();
    Serial.begin(9600);                       //Debugging
    Serial3.begin(9600);                      //HMI
    canSetup(cs,in,canFreq,clockFreq);        //CAN
    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  //LED
    pinMode(brakepin,INPUT);
//    pinMode(SPEED_PIN,INPUT_PULLUP);                      //Speeed
//    attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,RISING);
    
    
}
    
void loop(){
   
   dur= pulseIn(21,HIGH);         //gear
    hmiGear();
   
   getCAN(&RPM,&TEMP,&VOLT);      //CAN
//    sRPM=RPM*1.25;               //
    hmiCAN();   
    
    
    showLightDis();               //LED
    hmiTempRed();                 //HMI

//    duration = pulseIn(SPEED_PIN,HIGH);//speed3
//    getSpeed3();                  //Speed
//    hmiSpeed3();
//Brake pressure 
    brakevalue = analogRead(brakepin);
    float brakevol = brakevalue* (5.0/1023.0);
    if (brakevol >= 4.5){
      brakevol = 4.5;
      }
    a = brakevol*100/4-12.45;

    Serial.print(a);
    Serial.print(",");
    Serial.println(brakevol);

    Serial3.print("t");
    Serial3.print("6");
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print((int)a);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);

    Serial3.print("t");
    Serial3.print("7");
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print("brake");
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}
