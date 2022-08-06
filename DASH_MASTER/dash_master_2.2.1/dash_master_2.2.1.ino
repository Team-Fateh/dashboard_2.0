#include<CAN.h>
#include<SD.h>
#include<SPI.h>

#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3

unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;


void setup(){
  
    Serial.begin(9600);
    canSetup(cs,in,clockFreq,canFreq);



    
}
    
void loop(){
   getCAN(&RPM,&TEMP,&VOLT);
      
    




}
