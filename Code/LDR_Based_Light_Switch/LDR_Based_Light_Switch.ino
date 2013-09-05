 int LDR =A0; //Analog Pin 0
 int LED=8; //digital pin8
 void setup()
 {
   Serial.begin(9600); //Starting Serial Port for Output
   pinMode(LED,OUTPUT);// Set function of Digital pin 8 as Output
 }
 
 void loop()
 {
   int LDR_Reading = analogRead(LDR);
   
   Serial.println(LDR_Reading);
   if(LDR_Reading > 450) // Checks intesity of Light
   {
     digitalWrite(LED,LOW);
   }
   else
   {
     digitalWrite(LED,HIGH);
   }
   delay(500);
 }
