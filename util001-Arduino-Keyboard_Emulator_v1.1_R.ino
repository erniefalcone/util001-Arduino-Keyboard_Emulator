//******************************************************************************
// Program : util001-Arduino-Keyboard_Emulator
// Function: XVR keyboard emulator 
// Descript: This program generates keyboard keystrokes from buttons as follows:
//           Button 1 - Press = 1 Release = q
//           Button 2 - Press = 2 Release = w  
// Target  : Adrunio Pro Micro Precessor: ATmega32u4(5V, 16MHz)
// Wiring  : Button 1 - Pin 2 to GND
//           Button 2 - Pin 3 to GND             
// Revision: Release: v1.0   Date: 01/24/2018 Approved: BC        
//             Notes: Button 1: Press = 1 Button 2: Press = 2
//           Release: v1.1_R Date: 02/21/2018 Approved: EF
//             Notes: Changed Button Action 
//                    Button 1 - Press = 1 Release = q
//                    Button 2 - Press = 2 Release = w  
//******************************************************************************

#include <Keyboard.h>
int buttonPin1 = 2;  
int prevButtonState1 = HIGH;
int buttonState1 = HIGH;
int buttonPin2 = 3;  
int prevButtonState2 = HIGH;
int buttonState2 = HIGH;

void setup()
{
  pinMode(buttonPin1, INPUT);  // Set the button as an input
  digitalWrite(buttonPin1, HIGH);  // Pull the button high
  pinMode(buttonPin2, INPUT);  // Set the button as an input
  digitalWrite(buttonPin2, HIGH);  // Pull the button high
}

void loop()
{
  buttonState1 = digitalRead(buttonPin1);
  if (buttonState1 == LOW && prevButtonState1 == HIGH)  // if the button goes low
  {
    Keyboard.write('1');  
  } else if (buttonState1 == HIGH && prevButtonState1 == LOW)  // if the button goes high
  {
    Keyboard.write('q');  
  }
  prevButtonState1 = buttonState1;

  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == LOW && prevButtonState2 == HIGH)  // if the button goes low
  {
    Keyboard.write('2');  
  } else if (buttonState2 == HIGH && prevButtonState2 == LOW)  // if the button goes high
  {
    Keyboard.write('w');  
  }
  prevButtonState2 = buttonState2;
  
  delay(100);
}
