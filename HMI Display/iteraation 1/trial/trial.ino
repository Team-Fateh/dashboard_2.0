
long int b;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(1000);
  hmi_page("1");
  delay(50);
  for (int i=0; i<=120; i++){
    hmi_text("1","1",i);
    delay(8);
  }
    for (int i=120; i>=0; i--){
    hmi_text("1","1",i);
    delay(8);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
    
    hmi_text("1","1",0);
    
delay(50);
  
}
void hmi_page(String page_num){
  Serial.print("page page");
    Serial.print(page_num);
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
}
void hmi_text(String page_num,String txt_num,int txt ){
    Serial.print("page");
    Serial.print(page_num);
    Serial.print(".");
    Serial.print("t");
    Serial.print(txt_num);
    Serial.print(".");
    Serial.print("txt=");
    Serial.print("\"");
    Serial.print(txt);
    Serial.print("\"");
    Serial.write(0xff);
    Serial.write(0xff);
    Serial.write(0xff);
}
