void spokein(){
  spoke++;
}

float wheelSpeed(){
detachInterrupt(digitalPinToInterrupt(wheel));
tim=millis()-oldtime;
rpm=(spoke/tim)*60000;
oldtime=millis();
spoke=0;
attachInterrupt(digitalPinToInterrupt(wheel), spokein, RISING);
}
