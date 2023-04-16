volatile unsigned int totalCounts;
int speedPin=22;
int lastTime=0;
int slits=28;   //Front wheel
float Speed;

void setup()
{
  pinMode(speedPin,INPUT);
  Serial.begin(115200);
  attachInterrupt(digitalPinToInterrupt(speedPin),speedISR,FALLING);
}

void loop()
{
  startCount(50);
}

void startCount(int period)
{
  if(millis()-lastTime<period)
  return;
  Speed=((totalCounts*5032.832)/period)/slits;   
  Serial.println(Speed);
  //Serial.println(digitalRead(totalCounts));
  lastTime=millis();
  totalCounts=0;
}

void speedISR()
{
  totalCounts++;
}
