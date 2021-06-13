/*  This code work with IR sensor and relay module for turn on/off light
 *  By walking passed the sensor the light will turn on immediately then waiting for 5 sec for the next process
 *  For second passed ,the light will turn off after 5 sec.
 */

int ledPin = LED_BUILTIN;    // choose the pin for the LED_BUILTIN ; please manage as per your board
int irPin  = 7;              // choose the input pin (for IR sensor)
int outPin = 12;             // Pinout to Relay Module ; you can change as you want
int state  = LOW;            // Status of IR Pin
int val    = 0;              // variable for reading the pin status

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);    // declare LED as output
  pinMode(irPin, INPUT);      // declare sensor as input
  pinMode(outPin, OUTPUT);    // declare output to relay module
}

void loop()
{
  if (state == LOW)
  {
    val = digitalRead(irPin);
    if (val == LOW)
    {
      digitalWrite(ledPin,HIGH);
      state = digitalRead(ledPin);
      Serial.print("Power ON!  Status: ");
      Serial.println(state);
      digitalWrite(outPin,state);
      delay (5000);  // wait 5 sec before next process
    }
  }
  else
  {
    val = digitalRead(irPin);
    if (val == LOW)
    {
      delay (5000);  // waiting 5 sec after walking passed sensor then switch off the light
      digitalWrite(ledPin,LOW);
      state = digitalRead(ledPin);
      Serial.print("Power OFF! Status: ");
      Serial.println(state);
      digitalWrite(outPin,state);
      delay (5000);  // wait 5 sec before next process
    }
  }
}
