//Jacob Enrico 10/31/18
//U.R.II - Project

#include <Servo.h>

//VARIABLES//
const int ledPin = 13;
const int motoPin = 12;
int incomingByte = 0;
Servo servo;
int sPos = 0;

void setup() 
{
  Serial.begin(115200); //Serial connections
  servo.attach(12);
  pinMode(ledPin, OUTPUT);
}

void loop() 
{
  if (Serial.available() > 0)
  {
    incomingByte = Serial.read();

    Serial.println(incomingByte);
    
    if (incomingByte > 0)
    {
      if (incomingByte >= 0 && incomingByte < 256)
      {
        digitalWrite(ledPin, HIGH); //LED on
          
       for (sPos = 0; sPos <= 180; sPos += 1) 
       {
        servo.write(sPos); //Moving servos
        delay(15);
       }
        for (sPos = 180; sPos >= 0; sPos -= 1) 
       {
        servo.write(sPos); //Moving servos
        delay(15);
       }
    }
      
      if (incomingByte == 0)
      {
        digitalWrite(ledPin, LOW); //LED off
      }
    }
    Serial.println(incomingByte);
  }
}
