void engineSetup(){
  pinMode(crank_pin,OUTPUT);
  pinMode(kill_pin,OUTPUT);
  digitalWrite(crank_pin,HIGH);
  digitalWrite(kill_pin,HIGH);
}
void crank(){
    Serial2.print("cranking");
  digitalWrite(crank_pin,LOW);
  delay(2500);
    digitalWrite(crank_pin,HIGH);
}
void kill(){
    Serial2.print("killing");
    digitalWrite(kill_pin,LOW);
  delay(5000);
  digitalWrite(kill_pin,HIGH);
}
