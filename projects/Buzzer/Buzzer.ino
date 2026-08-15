/*
  Piezo Buzzer - simple melody

  Plays the first phrase of "Twinkle Twinkle Little Star" using the
  built-in tone() function, then pauses and repeats.

  Wiring:
    - Buzzer positive leg -> pin 8
    - Buzzer negative leg -> GND
    (no resistor needed - piezo elements draw negligible current)

  Concept: tone(pin, frequency, duration) drives the pin with a square
  wave at the given frequency (Hz). A piezo disc physically flexes at
  that frequency (the "reverse piezoelectric effect"), pushing air at
  the same rate - which your ear hears as a musical pitch. Higher
  frequency = higher pitch. Arduino can only play one tone() at a time
  (no chords) since it's driven by a single hardware timer.
*/

const int buzzerPin = 8;

// Note frequencies in Hz (standard 4th-octave note names)
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

const int numNotes = 0;

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < numNotes; i++) {
    tone(buzzerPin, melody[i], noteDurations[i]);
    // Wait a bit longer than the note's duration so consecutive notes
    // of the same pitch (like the two C4s at the start) don't blur
    // into one continuous tone.
    delay(noteDurations[i] * 1.3);
  }

  noTone(buzzerPin);  // make sure the buzzer is fully silent
  delay(2000);        // pause before repeating
}
