




/*
 * LoRa E32-TTL-100
 * Start device or reset to send a message
 * https://www.mischianti.org
 *
 * E32-TTL-100----- Arduino UNO
 * M0         ----- GND
 * M1         ----- GND
 * RX         ----- PIN 2 (PullUP &amp; Voltage divider)
 * TX         ----- PIN 3 (PullUP)
 * AUX        ----- Not connected
 * VCC        ----- 3.3v/5v
 * GND        ----- GND
 *
 */
#include "Arduino.h"

#include <SoftwareSerial.h>
char comm;
SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()>0) {
//    comm = Serial.read();
//    mySerial.write(comm);
      mySerial.write(Serial.read());
  }
}
//  if(comm == 'd'){
//    mySerial.write(comm);
//  }
//  if(comm == 'k'){
//    delay(100);
//    mySerial.write(comm);
//    delay(100);
//    comm='d';
//    delay(100);
//  }
//  if(comm == 'c'){
//    delay(100);
//    mySerial.write(comm);
//    delay(100);
//    comm='d';
//    delay(100);
//  }
//}
