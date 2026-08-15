/*
  Button -> Buzzer (buzz while held)

  Buzzer sounds continuously for as long as the button is held down,
  and stops the instant it's released.

  Wiring:
    - Button: one leg -> pin 2, other leg -> GND (INPUT_PULLUP)
    - Buzzer: positive leg -> pin 8, negative leg -> GND
*/

const int buttonPin = 2;
const int buzzerPin = 8;
const int toneFrequency = 440;  // A4

int lastStableState = HIGH;   // HIGH = not pressed (pull-up idle state)
int lastReading = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 25;  // ms

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Only act on the moment the state changes, not every loop - this
    // way tone()/noTone() are each called exactly once per press or
    // release, instead of tone() restarting itself every loop iteration
    // while held.
    if (reading != lastStableState) {
      lastStableState = reading;

      if (lastStableState == LOW) {
        // No duration argument here - tone() plays indefinitely until
        // noTone() is called, unlike ButtonBuzzer's timed notes.
        tone(buzzerPin, toneFrequency);
      } else {
        noTone(buzzerPin);
      }
    }
  }

  lastReading = reading;
}
