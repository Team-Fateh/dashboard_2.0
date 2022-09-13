void sdSpi(){
  digitalWrite(cs,HIGH);
  digitalWrite(cs_sd,LOW);
}
void canSpi(){
  digitalWrite(cs,LOW);
  digitalWrite(cs_sd,HIGH);
}
