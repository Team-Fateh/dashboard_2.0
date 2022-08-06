#include <SD.h>
#include <SPI.h>
#include <Wire.h>
#include <CAN.h> // the OBD2 library depends on the CAN library
#include <OBD2.h>
#include <LiquidCrystal_I2C.h>
File sdcard_file;
LiquidCrystal_I2C lcd(0x27,16,2);


int CS_pin = 9; // sd card ss pin
int pinR=4;   //speed sensor
unsigned long duration; // 
float AngularSpeed=0;
float speedkmh=0;
float speedms=0;
float WheelRadius= 0.26 ;
float Circum = 16.6;
float Dist=0;
float brake=0;
float voltage=0;
long unsigned int counter=0; 


const int PIDS[] = {

    ENGINE_RPM,    
    
    ENGINE_COOLANT_TEMPERATURE,
};

const int NUM_PIDS = sizeof(PIDS) / sizeof(PIDS[0]);

float RPM;
float TEMP;
int temp_led=6;

void sd(){
  digitalWrite(9,LOW);
  digitalWrite(10,HIGH);
  }
void can(){
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  CAN.setClockFrequency(8E6);
  CAN.setPins(10, 2); //ss and int pin can bus
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  pinMode(temp_led, OUTPUT);
  pinMode(pinR,INPUT);
  
 pinMode(CS_pin, OUTPUT);
 pinMode(A0,INPUT);
  
  while (!Serial);

  Serial.println(F("OBD2 Key Stats"));

  while (true) {
    can();
    Serial.print(F("Attempting to connect to OBD2 CAN bus ... "));
    if (!OBD2.begin()) {
      Serial.println(F("failed!"));
        lcd.init();
        lcd.clear(); 
        lcd.setCursor(3,0);   //Set cursor to character 2 on line 0
        lcd.print("TEAM FATEH");
        lcd.setCursor(6,1);
        lcd.print("TIET");
        delay(2000);
        lcd.init();
        lcd.clear();  
        lcd.setCursor(0,0);
        lcd.print("CAN BUS FAILURE");
        delay(1000);
        
        
      
    } else {
      Serial.println(F("success"));
        lcd.clear();
        lcd.setCursor(3,0);   //Set cursor to character 2 on line 0
        
        lcd.print("TEAM FATEH");
        lcd.setCursor(6,1);
        lcd.print("TIET");
        break;
    }
  }

  sd();
   if (SD.begin(CS_pin))
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
  }
 sd();
  sdcard_file = SD.open("data.txt", FILE_WRITE);

  if (sdcard_file) { 
    sdcard_file.print(",Time in (ms),RPM,TEMP,Speed,Distance,Brake");   
    sdcard_file.println();
    sdcard_file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  can();
  lcd.init();
  lcd.clear();         
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("RPM:");
  int pid = PIDS[0];
  float pidValue = OBD2.pidRead(pid);
  RPM = pidValue; 
    if (isnan(pidValue)) {
      
        lcd.clear();  
        lcd.setCursor(0,0);
        lcd.print("CAN BUS FAILURE");
        delay(1000);
        Serial.print("error");
  } 
   else {  
    lcd.setCursor(5,0);
    lcd.print(pidValue);
  }

  pid = PIDS[1];
  lcd.setCursor(0,1); 
  lcd.print("TEM:");
  pidValue = OBD2.pidRead(pid);
  TEMP=pidValue;
  if (isnan(pidValue)) {
    Serial.print("error");
     
        lcd.clear();  
        lcd.setCursor(0,0);
        lcd.print("CAN BUS FAILURE");
        delay(1000);
  } 
  else {
    lcd.setCursor(5,1);
    lcd.print(pidValue);
    if (pidValue>86){
      digitalWrite(temp_led,HIGH);
    }
    else{
      digitalWrite(temp_led,LOW);
    }
  }
  lcd.setCursor(8,1); 
  lcd.print("C");

  voltage = analogRead(A0);
  voltage = voltage*(5.0 / 1023.0);
  float brake = (voltage-0.5)*25;
  duration = pulseIn(pinR,HIGH);
  Serial.println(duration);
  if (duration>500){
  AngularSpeed= (0.8377*1000000)/duration;
  speedms=(AngularSpeed*WheelRadius);
  speedkmh=(speedms*3.6);
  counter=counter+1;
  
  Dist = counter*Circum;

  Serial.print(",");
  Serial.print(millis());
  Serial.print(",");
  Serial.print(RPM);
  Serial.print(",");
  Serial.print(TEMP);
  Serial.print(",");
  Serial.print(speedkmh);
  Serial.print(",");
  Serial.print(Dist);  
  Serial.print(",");
  Serial.print(brake);
  Serial.println();

     sd();
     sdcard_file = SD.open("data.txt", FILE_WRITE);
   if (sdcard_file) { 
    sdcard_file.print(",");  
    sdcard_file.print(millis());
    sdcard_file.print(",");   
    sdcard_file.print(RPM);
    sdcard_file.print(",");
    sdcard_file.print(TEMP);
    sdcard_file.print(",");
    sdcard_file.print(speedkmh);
    sdcard_file.print(",");
    sdcard_file.print(Dist);
    sdcard_file.print(",");
    sdcard_file.println(brake);  
    sdcard_file.close(); // close the file
  }
  // if the file didn't open, print an error:
  else {
    Serial.println("error opening test.txt");
  }

  }
  
  else{
 
  Serial.print(",");
  Serial.print(millis());
  Serial.print(",");
  Serial.print(RPM);
  Serial.print(",");
  Serial.print(TEMP);
  Serial.print(",");
  Serial.print(0);
  Serial.print(",");
  Serial.print(Dist); 
  Serial.print(",");
  Serial.print(brake);
  Serial.println();
  sd();
  sdcard_file = SD.open("data.txt", FILE_WRITE);
   if (sdcard_file) {    
    sdcard_file.print(","); 
    sdcard_file.print(millis());
    sdcard_file.print(",");
    sdcard_file.print(RPM);
    sdcard_file.print(",");
    sdcard_file.print(TEMP);
    sdcard_file.print(",");
    sdcard_file.print("0");
    sdcard_file.print(",");
    sdcard_file.print(Dist);
    sdcard_file.print(",");
    sdcard_file.println(brake);
    sdcard_file.close(); // close the file
  }
  else {
    Serial.println("error opening test.txt");
  }
  
}
can();
}
