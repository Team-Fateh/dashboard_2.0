#include<CAN.h>
#include <FastLED.h>

#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3
#define gear_pin 21       //gear
#define LED_PIN     7     //LED
#define NUM_LEDS    19
#define brake_pin      A8    //brakes

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

long voltBrake;               //Brake
long brake;
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

void setup(){
    millis();
    Serial.begin(9600);                       //Debugging
    Serial3.begin(9600);                      //HMI
    canSetup(cs,in,canFreq,clockFreq);        //CAN
    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  //LED
    pinMode(brake_pin,INPUT);                 //brake

//    pinMode(SPEED_PIN,INPUT_PULLUP);                      //Speeed
//    attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,RISING);
    
    
}
    
void loop(){
   voltBrake=analogRead(brake_pin);
   Serial.println(voltBrake);
   if(voltBrake>=921.6){
   voltBrake=921.6;}
   voltBrake=voltBrake*5/1023;
   brake= voltBrake*100/4;
   Serial.println(brake);
   
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

//Serial3.print("t");
//    Serial3.print("1");
//    Serial3.print(".");
//    Serial3.print("txt=");
//    Serial3.print("\"");
//    Serial3.print("1");
//    Serial3.print("\"");
//    Serial3.write(0xff);
//    Serial3.write(0xff);
//    Serial3.write(0xff);


}
