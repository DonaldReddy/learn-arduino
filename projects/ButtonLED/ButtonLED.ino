/*
  Button -> LED

  Press the button, the external LED lights up. Release, it turns off.
  Combines digital input (Button project) with digital output (Blink
  project), plus the debouncing technique from the Button project.

  Wiring:
    - Button: one leg -> pin 2, other leg -> GND (uses internal pull-up)
    - LED: anode -> 220ohm resistor -> pin 8, cathode -> GND
*/

const int buttonPin = 2;
const int ledPin = 8;

int lastStableState = HIGH;   // HIGH = not pressed (pull-up idle state)
int lastReading = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 25;  // ms

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    lastStableState = reading;
  }

  // pressed = LOW (pull-up), so light the LED when LOW
  digitalWrite(ledPin, lastStableState == LOW ? HIGH : LOW);

  lastReading = reading;
}
