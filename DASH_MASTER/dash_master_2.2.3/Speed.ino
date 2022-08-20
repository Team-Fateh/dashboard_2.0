void isr(){
  srev++;
}

void getSpeed(){
detachInterrupt(0);           //detaches the interrupt while calculating
time=millis()-oldtime;        //finds the time 
srpm=(srev/time)*60000;         //calculates rpm
oldtime=millis();             //saves the current time
srev=0;
attachInterrupt(0,isr,RISING);
wheelSpeed=(srpm/6)*
}
