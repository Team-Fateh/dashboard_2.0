#include <CAN.h>

int MSB=0,LSB=0;
int tMSB=0,tLSB=0;
int vMSB=0,vLSB=0;
unsigned long RPM;
float temp;
float volts;
void setup() {
  Serial.begin(115200);
  while (!Serial);

  Serial.println("CAN Receiver");

  // start the CAN bus at 500 kbps
  if (!CAN.begin(1000E3)) {
    Serial.println("Starting CAN failed!");
    while (1);
  }
}

void loop() {

//
  int packetSize = CAN.parsePacket();
  if (packetSize) {
    long packId = CAN.packetId();
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
      RPM=((MSB*256)+LSB);
    }
    if(packId==218101064){    //0CFFF548 for battery volt air temp coolant temp
    
      // only print packet data for non-RTR packets
      int e=0;
      while (CAN.available()) {
        
        if (e==0){                            //0th and 1st Byte are voltage data
                e++;
                vLSB=(int)CAN.read();
            }
        if (e==1){
                e++;
                vMSB=(int)CAN.read();
            }
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

      temp=((tMSB*256)+tLSB)*0.1;
      volts=((vMSB*256)+vLSB)*0.01;
      Serial.println(temp);
      Serial.println(volts);
    }
  }
//
 Serial2.print("t");
    Serial2.print(placeholder);
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print(value);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);

 Serial2.print("t");
    Serial2.print(placeholder);
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print(value);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);
    
 Serial2.print("t");
    Serial2.print(placeholder);
    Serial2.print(".");
    Serial2.print("txt=");
    Serial2.print("\"");
    Serial2.print(value);
    Serial2.print("\"");
    Serial2.write(0xff);
    Serial2.write(0xff);
    Serial2.write(0xff);


  
}
