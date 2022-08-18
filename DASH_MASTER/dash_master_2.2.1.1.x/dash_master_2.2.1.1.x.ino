#include<CAN.h>
#include<SD.h>
#include<SPI.h>

#define cs 10           //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   500E3

#define wheel 2           //wheel

String hmi_rpm = "t4";

unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;

int spoke=0;              //wheel
int oldtime=0;        
int tim;
float rpm;



void setup(){
    Serial.begin(9600);
    Serial3.begin(9600);
    canSetup(cs,in,clockFreq,canFreq); 

   // pinMode(wheel,INPUT_PULLUP);
   // attachInterrupt(digitalPinToInterrupt(wheel), spokein, RISING);


    
}
    
void loop(){
   getCAN(&RPM,&TEMP,&VOLT);
Serial.println(RPM);

    Serial3.print("t");
    Serial3.print(4);
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print(RPM);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);

}
