/*  Induino R3 User Guide - Program 10.0 - Interfacing a Character LCD using the LCD Shield to display LDR value on the LCD */
/* Pin Mappings as per the Simple Labs' LCD shield
 * LCD RS pin to digital pin 8
 * LCD Enable pin to digital pin 9
 * LCD D4 pin to digital pin 10
 * LCD D5 pin to digital pin 11
 * LCD D6 pin to digital pin 12
 * LCD D7 pin to digital pin 13
 * LCD R/W pin to ground
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins from the above pin mappings
LiquidCrystal lcd(8,9,10,11,12,13); // 

void setup() {
  // set up the LCD's number of characters per line and lines: 
  lcd.begin(16, 2);

}

void loop() {
  
  lcd.clear();//Clears the Display - If you don't clear, previous data will remain as it is
  int ldr_val = analogRead(3); // read the LDR value
  lcd.print("LDR Value : "); // print the description text
  lcd.print(ldr_value); // print the actual value
  delay(2000); // wait before refreshing the value
  
}

