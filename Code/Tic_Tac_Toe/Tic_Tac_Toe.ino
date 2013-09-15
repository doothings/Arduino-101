#include <IRremote.h>  
 int RECV_PIN = 15;  
 IRrecv irrecv(RECV_PIN);  
 decode_results results;  
 int i = 0;  
 int blinkarray[11];
 int user=0;
 void setup()  
 {  
   for(i=2;i<11;i++)
   {
     pinMode(i,OUTPUT);
   }
   irrecv.enableIRIn(); // Start the Remote receiver  
  Serial.begin(9600);  
 }  
 void loop()  
 {  
  blinkOrNot();
  if (irrecv.decode(&results)) {  
   Serial.println(results.value);  
   switch(results.value)  // if the '+' button is pressed  
   {  
   case 2320:   
    i=0;   
    break;// 2320 is the value for '0'  
   case 16:   
    i=1;
    setArray();
    break;// 16 is the value for '1'  
   case 2064:   
    i=2;   
    setArray();
    break;// 2064 is the value for '2'  
   case 1040:   
    i=3;   
    setArray();
    break;// 1040 is the value for '3'  
   case 3088:   
    i=4;   
    setArray();
    break;// 3088 is the value for '4'  
   case 528:   
    i=5;   
    setArray();
    break;// 528 is the value for '5'  
   case 2576:   
    i=6;   
    setArray();
    break;// 2576 is the value for '6'  
   case 1552:   
    i=7;   
    setArray();
    break;// 1552 is the value for '7'  
     case 3600:   
    i=8;   
    setArray();
    break;// 1552 is the value for '7'  
     case 272:   
    i=9;   
    setArray();
    break;// 1552 is the value for '7'  
   }  
//   while(digitalRead(7)==0);  // wait till button is released to avoid incrementing the counter again  
   delay(300);         // small delay to avoid debounce  
   irrecv.resume(); // Receive the next value  
  }  
 }  
 
 void blinkOrNot(){
  for(int j=2;j<11;j++) {
    if(blinkarray[j]==1)
    {
      digitalWrite(j,HIGH);
    }
  }
  for(int j=2;j<11;j++){
      if(blinkarray[j]==2)
      {
        digitalWrite(j,HIGH);
      }
  }
    for(int j=2;j<11;j++){
      if(blinkarray[j]==2)
      {
        delay(50);
      }
  }
    for(int j=2;j<11;j++){
      if(blinkarray[j]==2)
      {
        digitalWrite(j,LOW);
      }
  }
    for(int j=2;j<11;j++){
      if(blinkarray[j]==2)
      {
        delay(50);
      }
  }
 }
 void setArray(){
   if(user==0){
    blinkarray[i+1]=1;
    user=1;
   }
   else{
    blinkarray[i+1]=2;
    user=0;
   }
 }
