/*
This Code Reads Analog Data From AS5600 Magnetic Encoder and Converts it to tick count for Robot. 
Syed Razwanul Haque(Nabil), https://www.github.com/Nabilphysics, https://www.nabilbd.com

----------------------------------------------------
 ************* Magnetic Encoder & Arduino Pin(Analog Read Mode) *************
 ---------------------------------------------------
       Magnetic Encoder No        | Arduino Pin
 ---------------------------------------------------
        Forward Right Mot Encoder |   A0
        Forward Left Mot Encoder  |   A1
        Aft Right Mot Encoder     |   A2  (Not Used Right Now)
        Aft Left Motor Encoder    |   A3  (Not Used Right Now)          
 ---------------------------------------------------

 ---------- Algorithm -----------
1- Read All Encoder Analog Data
2- Convert it to tick count

 Arduino: Arduino Uno
 Encoder : AS5600 Magnetic Encoder with Analog Output
 Special Note: Connect AS5600 Encoder DIR Pin to GND (White module available in market not connected)
*/

#include "Encoder_count.h"

//********* Encoder Object - Start**** (Analog, 'Direction', Encoder_lowest, Encoder_Highet, Analog_Highest_Value)******
EncoderCount encoderForwardRight(A0, '+', -32768, 32767, 1023); // Give - or + if you want to change the counting direction
EncoderCount encoderForwardLeft(A1, '-',-32768, 32767, 1023); 
EncoderCount encoderAftRight(A2, '+',-32768, 32767, 1023); 
EncoderCount encoderAftLeft(A3, '-',-32768, 32767, 1023); 
//********* Encoder Object - End**********


void setup() {
  Serial.begin(115200);

}

void loop() {
  
  Serial.print(encoderForwardRight.getValue()); Serial.print("  ");
  Serial.print(encoderForwardLeft.getValue()); Serial.print("  ");
  Serial.print(encoderAftRight.getValue()); Serial.print("  ");
  Serial.println(encoderAftLeft.getValue());
  delay(10);
}
 