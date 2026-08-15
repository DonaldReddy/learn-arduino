# ButtonLED

**Date:** 2026-08-16
**Concepts:** combining digital input + digital output, debouncing, current-driven LED behavior

Press the pushbutton, the external LED lights up while held. Straightforward
combination of the [Button](../Button/) and [Blink](../Blink/) projects —
first project that ties input and output together in one sketch.

## Wiring
- Button: one leg → pin 2, other leg → GND (`INPUT_PULLUP`, no resistor needed)
- LED: anode → 220Ω resistor → pin 8, cathode → GND

## What I learned
- This is the same debounce pattern from the Button project, just driving
  an external LED instead of logging to Serial or lighting `LED_BUILTIN`.
- Reinforced *why* the LED needs the resistor: the LED only glows once
  current flows through the junction (recombination → photons), and the
  resistor is what limits that current to a safe level once the button
  closes the circuit — voltage alone doesn't make it glow, current does.

## Code
[ButtonLED.ino](ButtonLED.ino)
