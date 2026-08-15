/*
  Button -> Buzzer (step through a melody one note per press)

  Each button press plays the next note in the melody array, then
  advances to the next one. After the last note, it wraps back to the
  start. Holding the button does nothing extra - only the moment of
  pressing (the HIGH -> LOW transition) triggers a note.

  Wiring:
    - Button: one leg -> pin 2, other leg -> GND (INPUT_PULLUP)
    - Buzzer: positive leg -> pin 8, negative leg -> GND
*/

const int buttonPin = 2;
const int buzzerPin = 8;

const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_G4 = 392;
const int NOTE_A4 = 440;

int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4
};

int noteDurations[] = {
  400, 400, 400, 400, 400, 400, 800,
  400, 400, 400, 400, 400, 400, 800
};

const int numNotes = 14;
int noteIndex = 0;

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
    // Only act when the debounced state actually changes - this is
    // what makes it "one note per press" instead of replaying constantly
    // while the button is held down.
    if (reading != lastStableState) {
      lastStableState = reading;

      if (lastStableState == LOW) {  // the moment the button was pressed
        tone(buzzerPin, melody[noteIndex], noteDurations[noteIndex]);
        noteIndex = (noteIndex + 1) % numNotes;  // advance, wrap at the end
      }
    }
  }

  lastReading = reading;
}
