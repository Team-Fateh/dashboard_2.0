#include<CAN.h>                      /*Libraries*/
#include <FastLED.h>
//#include <SPI.h>
//#include <SD.h>
                                     /*Defines*/
                                     /*first_second_third_num*/   
//#define crank_pin 28
//#define kill_pin 26
//#define undefined_pin 24
#define cs 10             //CAN         
#define in 2
#define clockFreq 8E6
#define canFreq   500E3
#define cs_sd    53         //sd
#define gear_pin 21       //gear
#define LED_PIN     7     //LED
#define NUM_LEDS    19
#define brake_pin   A8
//#define SPEED_PIN   3     //speed
//#define wheelRadius  0.117
//#define spokeangle  46
                                     /*Variables*/
                                     /*firstSecondThirdNum*/
unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
//unsigned long sRPM=0;         //
//File sdcard_file;             //sd
int gear;                     //gear
long dur;
CRGB leds[NUM_LEDS];          //LED
int light=0,red;
long unsigned int ledDur=0, ledOldDur=0;            
//int brakeValue ;              //Brakes
//float brakePress ;   
//float brakeVolt;
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
unsigned long crankdur;


void setup(){
    
    pinMode(53,OUTPUT);
    digitalWrite(53,HIGH);
    //engineSetup();                            //engine
    millis();
    Serial.begin(9600);                       //Debugging
    Serial3.begin(9600);                      //HMI
    canSetup(cs,in,canFreq,clockFreq);        //CAN
//    sdInit();                                 //sd
//    loraInit();                               //lora
//    pinMode(gear_pin,INPUT);                  //gear
    FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);  //LED
//    pinMode(brake_pin,INPUT);                  //Brakes
//    pinMode(SPEED_PIN,INPUT_PULLUP);                      //Speeed
//    attachInterrupt(digitalPinToInterrupt(SPEED_PIN),speedISR2,RISING);

    
}
    
void loop(){
//   delay(5000);
//   crank();
//   delay(5000);
//   kill();
    dur= pulseIn(21,HIGH);         //gear
    hmiGear();
   
   getCAN(&RPM,&TEMP,&VOLT);      //CAN
//    sRPM=RPM*1.25;               //
    hmiCAN();   

//    sdData();                     //sd
//    loraDataSend();               //lora
    showLightDis();               //LED
    hmiTempRed();                 //HMI

//    duration = pulseIn(SPEED_PIN,HIGH);//speed3
//    getSpeed3();                  //Speed
//    hmiSpeed3();

//    getBrake();                         //Brake pressure 
//    hmiBrake();

   

}
