#include <SoftwareSerial.h>
#include "KZGSerial.h"

KZGSerial ser;
SoftwareSerial swSer(14, 12, false, 256);

void setup()
{
  Serial.begin(115200);
 
  delay(1000);
  Serial.println();
  Serial.println("KZGSerial_SoftwareSerialEcho start");
   swSer.begin(115200);
  ser.begin(&swSer);
  //<16;x;hello;world>076  -- full msg
  ser.printRS('x',"hello","world");


}

char b[150]; 

void loop()
{
  if(Serial.available()>0)
  {
    char c=Serial.read();
   // Serial.print(">");Serial.println(c);
    swSer.write(c);
  }
  
  ser.loop();
  if(ser.isMsgWaiting())
  {
    sprintf(b,"SoftSerial receive: type = %d / %c, topic= %s, msg= %s", ser.getMsgType(),ser.getMsgType(),ser.getMsgTopic(),ser.getMsgValue());
    Serial.println(b);
    
    ser.resetData();
  }
  
}
