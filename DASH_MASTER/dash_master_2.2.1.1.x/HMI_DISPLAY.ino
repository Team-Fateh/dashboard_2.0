void hmi_page(String page_num){
    Serial3.print("page page");
    Serial3.print(page_num);
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}
void hmi_text_int(String txt_num,int txt ){

    Serial3.print("t");
    Serial3.print(txt_num);
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print(txt);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}

void hmi_text_float(String txt_num,float txt ){

    Serial3.print("t");
    Serial3.print(txt_num);
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print(txt);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}
void hmi_text_ul(String txt_num,unsigned long txt ){

    Serial3.print("t");
    Serial3.print(txt_num);
    Serial3.print(".");
    Serial3.print("txt=");
    Serial3.print("\"");
    Serial3.print(txt);
    Serial3.print("\"");
    Serial3.write(0xff);
    Serial3.write(0xff);
    Serial3.write(0xff);
}
