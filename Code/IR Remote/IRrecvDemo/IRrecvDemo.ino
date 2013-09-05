
/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;
int RED =8;
int GREEN=9;
int BLUE =10;
boolean flag=false;


IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(RED,OUTPUT);
  pinMode(BLUE,OUTPUT);
  pinMode(GREEN,OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    switch(results.value)
    {
      case 131086089:
      if(flag)
       ledOn(1);
       else
       ledOff(1);
      break;
      case 2060953561:
      if(flag)
        ledOn(2);
        else
        ledOff(2);
        break;
      case 2010620704:
       if(flag)
       ledOn(3);
       else
       ledOff(3);
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

void ledOn(int led)
{
 if(led==1)
  {
    digitalWrite(RED,HIGH);
  }
  else if(led==2)
  {
    digitalWrite(BLUE,HIGH);
  }
  else if(led==3)
  {
    digitalWrite(GREEN,HIGH);
  }
}
void ledOff(int led)
{
  if(led==1)
  {
    digitalWrite(RED,LOW);
  }
  else if(led==2)
  {
    digitalWrite(BLUE,LOW);
  }
  else if(led==3)
  {
    digitalWrite(GREEN,LOW);
  }
}
/*void led3(int led)
{
  if(led==1)
  {
    digitalWrite(GREEN,HIGH);
  }
  else if(led==2)
  {
    digitalWrite(GREEN,LOW);
  }
}*/
