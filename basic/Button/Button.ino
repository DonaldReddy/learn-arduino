/*
  Button (with debounce)

  Reads a pushbutton wired to pin 2 using the Uno's internal pull-up
  resistor (no external resistor needed). Lights the onboard LED while
  the button is held, and prints press/release events to Serial.

  Wiring:
    - One leg of the button -> pin 2
    - Other leg of that same side -> GND
    (the other pair of legs, if it's a 4-pin button, is just the
    mechanical "other half" - wire either leg pair, not both sides)

  Concept: INPUT_PULLUP ties the pin HIGH internally. Pressing the
  button connects the pin to GND, so pressed = LOW, unpressed = HIGH.
  This is the opposite of what beginners usually expect.
*/

const int buttonPin = 2;
const int ledPin = LED_BUILTIN;

int lastStableState = HIGH;   // HIGH = not pressed (pull-up idle state)
int lastReading = HIGH;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 25;  // ms - ignore noise shorter than this

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  // If the raw reading changed, reset the debounce timer.
  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  // Only trust the reading once it's been stable longer than debounceDelay.
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (reading != lastStableState) {
      lastStableState = reading;

      if (lastStableState == LOW) {
        Serial.println("Button pressed");
      } else {
        Serial.println("Button released");
      }
    }
  }

  digitalWrite(ledPin, lastStableState == LOW ? HIGH : LOW);

  lastReading = reading;
}
