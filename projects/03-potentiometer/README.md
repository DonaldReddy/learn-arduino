# 03 · Potentiometer → PWM LED Brightness

**Date:** 2026-08-16
**Concepts:** `analogRead` (ADC), `analogWrite` (PWM), `map()`, voltage dividers

Reads a 10kΩ potentiometer's position and uses it to control an external
LED's brightness via PWM, printing the raw ADC value/voltage/brightness to
Serial.

## Wiring
- Pot left leg → GND
- Pot right leg → 5V
- Pot wiper (middle leg) → A0
- External LED anode → 220Ω resistor → pin 9 (must be a `~` PWM pin)
- External LED cathode → GND

## What I learned
- **ADC resolution**: the Uno's ADC is 10-bit, so `analogRead()` returns
  0–1023 across the 0–5V range (~4.9mV per step).
- **PWM ≠ real analog output**: the Uno has no DAC. `analogWrite()` rapidly
  switches the pin HIGH/LOW (~490Hz); the *duty cycle* (0–255) controls how
  much of each cycle is HIGH, which the eye perceives as brightness.
- **Not every pin supports PWM** — only pins marked `~` on the board
  (3, 5, 6, 9, 10, 11 on the Uno). `LED_BUILTIN` (pin 13) does not.
- **Two LEDs in parallel off one resistor is bad practice** — slight
  manufacturing differences mean one LED will hog current and outshine
  (and outlast) the other. Each LED needs its own resistor.
- **Two LEDs in series need combined forward voltage under the supply
  voltage.** Two white LEDs (~3.2V each) need ~6.4V — more than the Uno's
  5V rail — so they simply won't light in series here. Red/yellow/green
  (~2V each) would work in series, just dim on a 220Ω resistor.

## Code
[Potentiometer.ino](Potentiometer.ino)
