/*
Auto-on/off system
David Solomon 02/07/2014
Design That Matters

Hardware Setup:
This is Designed for use with a photoresistor that is 
connected to a 10k ohm resistor.
One side of the photoresistor connects to ground and the 
other side connects to a 10kohm resistor and Analog pin 0 (A0).
The other side of the 10k ohm resistor is connected to power which
is 5v. 
It is design for three led connected to digital pins 10,11,12.

*/

const int analogInPin = A0; // Analog input pin that is connected to A0
int LEDOut[] = {10,11,12};  // Digital output pin for leds
int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  //setup for the leds
  for(int c=0; c<(sizeof(LEDOut)/sizeof(int)); c++) 
  {
    pinMode(LEDOut[c], OUTPUT);  
  }  
}

void loop() { 
  sensorValue= analogRead(analogInPin);
  
  // print the results to the serial monitor:
    Serial.print("sensor = " );                       
    Serial.println(sensorValue);
  if(sensorValue>=250&&sensorValue<=280)       // turns on the first led
  {
    digitalWrite(LEDOut[0], HIGH);  //on
    digitalWrite(LEDOut[1], LOW);   //off
    digitalWrite(LEDOut[2], LOW);
  }
  else if(sensorValue>=325&&sensorValue<=425)  // turns on the first two leds
  {
    digitalWrite(LEDOut[0], HIGH);
    digitalWrite(LEDOut[1], HIGH);
    digitalWrite(LEDOut[2], LOW); 
  }
  else if(sensorValue>=450)                    // turns on all the leds
  {
    digitalWrite(LEDOut[0], HIGH);
    digitalWrite(LEDOut[1], HIGH);
    digitalWrite(LEDOut[2], HIGH);
  }
  else if(sensorValue<250)                                        // if it is lower then the provided thresholds turn it off
  {
    digitalWrite(LEDOut[0], LOW); 
    digitalWrite(LEDOut[1], LOW); 
    digitalWrite(LEDOut[2], LOW); 
  }
  
  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  // Changed it to about 155 millisec. So the Leds 
  //do not blink as often or as quickly as before
  delay(200);                     
}
