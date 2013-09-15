#include <IRremote.h>


int RECV_PIN = 15;
int RED =11;
int GREEN=12;
int BLUE =13;
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
      case 16:
      digitalWrite(GREEN,HIGH);
      break;
      case 2064:
      digitalWrite(RED, HIGH);
      break;
      case 1040:
      digitalWrite(BLUE, HIGH);

     }
     delay(500);
    irrecv.resume(); // Receive the next value
  }
}


