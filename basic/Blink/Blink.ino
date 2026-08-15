/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.
  Alternates between the onboard LED (pin 13 / LED_BUILTIN) and an
  external LED wired to pin 12.

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  https://docs.arduino.cc/built-in-examples/basics/Blink/
*/

int num = 0;

void setup() {
  // initialize digital pin LED_BUILTIN and pin 12 as outputs
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(12, OUTPUT);
  num = 0;
}

void loop() {
  if (num == 0) {
    digitalWrite(12, HIGH);   // turn external LED on
    delay(600);
    digitalWrite(12, LOW);    // turn external LED off
    delay(600);
  } else {
    digitalWrite(LED_BUILTIN, HIGH);  // turn onboard LED on
    delay(600);
    digitalWrite(LED_BUILTIN, LOW);   // turn onboard LED off
    delay(600);
  }

  num = num ^ 1;  // flip between 0 and 1 each pass through loop()
}
