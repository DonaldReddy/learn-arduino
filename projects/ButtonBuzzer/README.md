# ButtonBuzzer

**Date:** 2026-08-16
**Concepts:** edge detection (vs. level checking), state machines, combining input + `tone()`

Each button press plays the next note of "Twinkle Twinkle Little Star" —
step through the melody one note per press instead of it playing
automatically. Builds on [ButtonLED](../ButtonLED/) and [Buzzer](../Buzzer/).

## Wiring
- Button: one leg → pin 2, other leg → GND (`INPUT_PULLUP`)
- Buzzer: positive leg → pin 8, negative leg → GND

## What I learned
- **Edge detection vs. level checking**: `ButtonLED` checked the button's
  current *level* every loop (`is it LOW right now?`) to decide whether the
  LED should be on. This project needed something different — react only
  to the *transition* from unpressed → pressed, not the level itself.
  Otherwise a single press would (attempt to) retrigger `tone()` on every
  loop iteration while held, not just once.
- The fix: compare the new debounced state to the *previous* debounced
  state (`if (reading != lastStableState)`), and only act when they differ
  **and** the new state is LOW (the moment of pressing, not releasing).
- **`noteIndex` + modulo (`% numNotes`)** steps through the array and wraps
  back to 0 after the last note — a simple, reusable pattern for cycling
  through any fixed list on repeated triggers.

## Code
[ButtonBuzzer.ino](ButtonBuzzer.ino)
