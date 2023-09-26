# as5600_encoder
This Code Reads Analog Data From AS5600 Magnetic Encoder and Converts it to tick count for Robot.

# How to USE
## Step 1:
include header file 
```
#include "Encoder_count.h"
```

## Step 2:
Create a Object

```
EncoderCount encoderForwardRight(A0, '+', -32768, 32767, 1023); 

```
EncoderCount encoderForwardRight(AnalogPin, 'Direction', LowestTick, HighestTick, HighetAnalogValue); 

## Step 3:
Use getValue() method to read tick count.
```
encoderForwardRight.getValue()
```
# Hardware Connection & Special Note
As we will read analog value we have to connect Vcc to Vcc, GND to GND and Out Pin to Arduino Analog Pin. 

If you buy AS5600 module make sure DIR pin is connected to GND or VDD. Otherwise noise can change the direction.

# Example Code
```c++
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

```
