#define can_cs  10
#define can_int 3
#define sd_cs  9

#include <CAN.h>
#include <SPI.h>
#include <SD.h>
File sdcard_file;

int MSB=0,LSB=0;
int tMSB=0,tLSB=0;
unsigned long RPM;
float temp;
void can(){
  digitalWrite(can_cs,LOW);
  digitalWrite(sd_cs,HIGH);
}
void sd(){
  digitalWrite(sd_cs,LOW);
  digitalWrite(can_cs,HIGH);
}

void setup() {
  can();
  CAN.setPins(can_cs,can_int);
  CAN.setClockFrequency(8E6);
  Serial.begin(9600);
  while (!Serial);

  Serial.println("CAN Receiver");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(500E3)) {
    Serial.println("Starting CAN failed!");
  }
  
  sd();
  if (SD.begin(sd_cs))
  {
    Serial.println("SD card is ready to use.");
  } else
  {
    Serial.println("SD card initialization failed");
  }
  
}

void loop() {
//  can();
  // try to parse packet
  int packetSize = CAN.parsePacket();

  if (packetSize) {
    // received a packet
    Serial.print("Received ");
    Serial.print("packet with id ");
    long packId = CAN.packetId();
    Serial.println(packId);
    //RPM
    if(packId==218099784){      //0CFFF048 for RPM,TPS,FUEL,Ignition
    
   

      // only print packet data for non-RTR packets
      int d=0;
      while (CAN.available()) {
        
        if (d==0){
          d++;
          LSB=(int)CAN.read();
        }
        if (d==1){
          d++;
          MSB=(int)CAN.read();
        }
          CAN.read(); d++;
      }
      RPM=((MSB*255)+LSB)*0.125;
      Serial.println(RPM);
      Serial.println();
      Serial.print(MSB);
      Serial.print("    ");
      Serial.print(LSB);
    
    }//if packId
    //RPM
    //Coolant Temp
    if(packId==218101064){    //0CFFF548 for battery volt air temp coolant temp
    
      // only print packet data for non-RTR packets
      int e=0;
      while (CAN.available()) {
        
        
        if (e==4){
          e++;
          tLSB=(int)CAN.read();
        }
        if (e==5){
          e++;
          tMSB=(int)CAN.read();
        }
          CAN.read(); e++;
      }

      temp=((tMSB*255)+tLSB)*0.1;
      Serial.print(temp);
      Serial.println();
      Serial.print(tMSB);
      Serial.print("    ");
      Serial.print(tLSB);
    
    }//if packId Coolant temp
    Serial.println();
  }//if packSize
  
}
