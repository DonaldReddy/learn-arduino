# BuzzerHold

**Date:** 2026-08-16
**Concepts:** `tone()` without a duration, start/stop edge triggering

Buzzer sounds continuously while the button is held, stops the instant
it's released. Contrast with [ButtonBuzzer](../ButtonBuzzer/), which plays
one timed note per press.

## Wiring
- Button: one leg → pin 2, other leg → GND (`INPUT_PULLUP`)
- Buzzer: positive leg → pin 8, negative leg → GND

## What I learned
- **`tone(pin, frequency)` without a duration argument plays indefinitely**
  until `noTone()` is explicitly called — different from `ButtonBuzzer`,
  where `tone(pin, freq, duration)` auto-stops itself after `duration` ms.
- Still edge-triggered, not level-checked every loop: `tone()` is called
  **once** on the press edge (LOW transition) and `noTone()` **once** on
  the release edge (HIGH transition) — not repeatedly while held. Calling
  `tone()` every single loop iteration while the button stays down would
  work but is wasteful and can cause audible glitching as it keeps
  restarting the waveform.

## Code
[BuzzerHold.ino](BuzzerHold.ino)
