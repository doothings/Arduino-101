/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int BULB =8;
boolean flag=false;


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(BULB,OUTPUT);

}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch(results.value)
    {
      case 131086089:
      if(flag)
       ledOn();
       else
       ledOff();
      break;
      case 3757616022:
       if(flag)
       flag=false;
       else
       flag=true;
       break;
     }
     delay(500);
    irrecv.resume(); // Receive the next value
  }
}

void ledOn()
{
  digitalWrite(BULB,HIGH);
  
}
void ledOff()
{
  digitalWrite(BULB,LOW);
}

