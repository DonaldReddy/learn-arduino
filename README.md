# Learn Arduino → IoT Engineer

Personal learning log for the path from full-stack dev to IoT/embedded
engineer. Full plan: [docs/ROADMAP.md](docs/ROADMAP.md).

## Progress

**Currently in:** Stage 1 - Beginner, Week 5 (PWM & Analog) — see
[docs/ROADMAP.md](docs/ROADMAP.md) for the full 30-week breakdown.

| Stage | Weeks | Status |
|---|---|---|
| 1 — Beginner (electronics + C + first peripherals) | 1-8 | 🟡 in progress |
| 2 — Intermediate (register-level, interrupts, RTOS, I2C/SPI) | 9-18 | ⚪ not started |
| 3 — Advanced (bootloaders, CAN/USB/BLE, embedded Linux, security) | 19-30 | ⚪ not started |

## Projects

| # | Project | Concepts | Status |
|---|---|---|---|
| 01 | [Blink](projects/Blink/) | `digitalWrite`, timing, XOR toggle bug | ✅ done |
| 02 | [Button](projects/Button/) | `INPUT_PULLUP`, debouncing, `millis()` | ✅ done |
| 03 | [Potentiometer → PWM LED](projects/Potentiometer/) | `analogRead`, PWM, voltage dividers | ✅ done |
| 04 | [ButtonLED](projects/ButtonLED/) | combining digital input + output, debouncing | ✅ done |
| 05 | [Buzzer](projects/Buzzer/) | `tone()`, frequency/pitch, note sequencing | ✅ done |
| 06 | DHT11 sensor | temperature/humidity, one-wire-ish protocol | ⚪ next up |
| 07 | Servo motor | output-compare PWM | ⚪ planned |

Each project folder has its own `README.md` with wiring notes and what was
learned — not just the code.

## Hardware on hand
Arduino Uno R3, breadboard, MyDAQ, jumper wires, resistors (220Ω/1kΩ/10kΩ),
assorted LEDs, pushbuttons, 10kΩ potentiometer, piezo buzzer, DHT11.

## Repo structure
```
docs/ROADMAP.md    full 1-year roadmap + research notes
projects/Name/      one folder per sketch, each with its own README
```

Folder names match the `.ino` filename exactly (e.g. `projects/Blink/Blink.ino`) —
required by the Arduino IDE, which won't open a sketch unless its folder is
named after it. Chronological order is tracked in the table above, not in
the folder name.
