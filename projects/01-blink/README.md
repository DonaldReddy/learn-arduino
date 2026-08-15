# 01 · Blink

**Date:** 2026-08-13
**Concepts:** `pinMode`, `digitalWrite`, `delay`, `LED_BUILTIN`, basic program flow

Turns the onboard LED and an external LED on/off, alternating between the
two on each pass through `loop()`.

## Wiring
- External LED anode → 220Ω resistor → pin 12
- External LED cathode → GND

## What I learned
- `digitalWrite(pin, HIGH)` followed immediately by `digitalWrite(pin, LOW)`
  with no `delay()` between them is invisible to the eye — the pin needs to
  *stay* HIGH for some duration to actually see the LED lit.
- XOR (`num ^ 1`) flips a bit each time it's applied; XOR with `0` never
  changes the value — a common "why isn't my toggle working" bug.

## Code
[Blink.ino](Blink.ino)
