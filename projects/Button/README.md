# 02 · Button

**Date:** 2026-08-16
**Concepts:** `digitalRead`, `INPUT_PULLUP`, debouncing, `millis()` non-blocking timing, `Serial`

Reads a pushbutton and lights the onboard LED while it's held, logging
press/release events to the Serial Monitor. Debounced in software.

## Wiring
- One leg of the button → pin 2
- Other leg (same side) → GND
- No external resistor — uses the Uno's internal pull-up (`INPUT_PULLUP`)

## What I learned
- **`INPUT_PULLUP`** ties the pin HIGH internally; pressing the button pulls
  it to GND. So logic is inverted: unpressed = HIGH, pressed = LOW.
- **Debouncing**: mechanical switches bounce (rapid false triggers) when
  pressed/released. The fix is to ignore state changes until the signal has
  been stable for a short window (25ms here), using `millis()` to time it.
- **Non-blocking timing**: `delay()` freezes the whole program, so it can't
  be used in `loop()` here — `millis()`-based timing lets the sketch keep
  checking the button without ever blocking. This pattern comes back
  constantly once sensors/networking are added.

## Code
[Button.ino](Button.ino)
