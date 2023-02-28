#include <Arduino.h>
#include <SPI.h>
#include <CAN.h>
#include <CAN_fun.h>

#define canFreq   1000E3   //CAN
#define cs_sd    53         //sd
#define cs 10             //CAN
#define in 2
#define clockFreq 8E6
#define canFreq   1000E3
#define gear_pin 18       //gear

unsigned long RPM = 0;        //CAN
float TEMP = 0 , VOLT = 0 ;
int gear;
long dur;

unsigned long can_check_time = 2000, last_can_check_time = 0;
int can_available = 0;// toggled in can green and can red



void hmiCANRed(){
   Serial2.print("r1.pco=");       //63488 Red colour
    Serial2.print("63488");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.print("r1.bco=");       //63488 Red colour
    Serial2.print("63488");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    Serial2.print("t1");       //63488 Red colour
    Serial2.print(".");
    Serial2.print("pco");
    Serial2.print("=");
    Serial2.print("63488");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    can_available=0;  
}

void hmiCANGreen(){
  Serial2.print("r1.pco=");       //34800 green colour
    Serial2.print("1024");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.print("r1.bco=");       //34800 green colour
    Serial2.print("1024");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    Serial2.print("t1");       //1024 Green colour
    Serial2.print(".");
    Serial2.print("pco");
    Serial2.print("=");
    Serial2.print("1024");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    can_available=1;
}

//CAN HMI

void hmiCAN(){
    Serial2.print("t");
    Serial2.print("4");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print(RPM);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    Serial2.print("t");
    Serial2.print("5");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print((int)TEMP);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

    Serial2.print("t");
    Serial2.print("10");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print(VOLT);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
}

void hmiGear(){
    if(dur>=750&&dur<=870)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.print("1");
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=880&&dur<=1200)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("N");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=1220&&dur<=1500)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("2");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=1520&&dur<=2000)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("3");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }


    if(dur>=2020&&dur<=2500)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("4");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }

    if(dur>=2520&&dur<=3000)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("5");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }
    
    if(dur>=3020&&dur<=3500)
    {
    Serial2.print("t");
    Serial2.print("1");
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print("6");
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    }
}


//CANSetup

void canSetup(long can_freq) {
  if (!CAN.begin(can_freq)) {
    Serial.println("Starting CAN failed!"); //can failed
     hmiCANRed();
  }
}

//CAN


void setup() {
 Serial2.begin(9600);                       //HMI screen
 canSetup(canFreq);        //CAN
  Serial.begin(9600);
}

void loop() {
  getCAN(&RPM,&TEMP,&VOLT);    //CAN
  dur= pulseIn(18,HIGH);     //gear
  hmiGear();
  Serial.print(RPM);
  Serial.print("    ");
  Serial.print(TEMP);
  Serial.print("    ");
  Serial.println(VOLT);
  hmiCAN();

}