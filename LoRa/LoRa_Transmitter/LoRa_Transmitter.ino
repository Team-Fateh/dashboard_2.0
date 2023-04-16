




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

//#include <SoftwareSerial.h>
int count=0;

//SoftwareSerial mySerial(2, 3); // RX, TX

void setup() {
  Serial.begin(230400);

  Serial.println("Hi, I'm going to send message!");

  Serial2.begin(230400);
  Serial2.println("Hello, World?");

 
}

void loop() {
  if (Serial2.available()) {
    Serial.write(Serial2.read());
  }
  if (Serial.available()) {
    Serial2.write(Serial.read());
  }

      //  Serial2.print(count);
      //  Serial2.write("  ");
      //  Serial.print(count);
      //  Serial.println();
      //  delay(200);
      //  count++; 
}
