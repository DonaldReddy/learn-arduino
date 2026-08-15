# 1-Year Roadmap: Full-Stack SDE → IoT Engineer

Background: 2 yrs full-stack, some AI, CSE fundamentals. Skipping the
software/cloud side that most IoT learners struggle with — the gap to
close is embedded/hardware.

## Months 1-2: Embedded Foundations
- Get ESP32 + starter kit, basic Arduino IDE work (GPIO, PWM, ADC, digital/analog I/O)
- Learn I2C, SPI, UART — the three protocols basically all sensors/modules use
- Projects: LED patterns, button debouncing, read a DHT22/DHT11 (temp/humidity), control a servo
- Pick up C/C++ at the embedded level (pointers, memory constraints — different mindset from full-stack)

## Months 3-4: Connectivity + Real Sensors
- ESP32 WiFi/Bluetooth — send sensor data to a server you build (full-stack skills are the unfair advantage here)
- Learn MQTT (the standard IoT messaging protocol) — set up a broker (Mosquitto), publish/subscribe
- Projects: sensor → MQTT → dashboard (build the dashboard fast; focus learning time on the device side)
- Explore a Raspberry Pi as a "gateway" device — different role than microcontroller, worth understanding both

## Months 5-6: Cloud IoT + Data Pipeline
- Pick one: AWS IoT Core, Azure IoT Hub, or Google Cloud IoT — device provisioning, telemetry ingestion, device shadows/digital twins
- Time-series data storage (InfluxDB is the common one for IoT)
- Project: full pipeline — device → cloud ingestion → storage → visualization (Grafana)

## Months 7-8: PCB Basics + Power/Real-World Constraints
- Learn KiCad basics (even if you never fabricate) — understand schematics, not just breadboards
- Power management: battery life, sleep modes, low-power design — where a lot of real IoT engineering time goes
- Security basics for IoT: device auth, TLS on constrained devices, OTA updates

## Months 9-10: Bring in Your AI Edge
- TinyML / Edge AI — running lightweight ML models on-device (TensorFlow Lite Micro, Edge Impulse)
- Genuinely differentiating skill combo (full-stack + embedded + AI) — few people have all three
- Project: on-device anomaly detection or simple classification (e.g., predictive maintenance from vibration/sound data)

## Months 11-12: Portfolio + Job Targeting
- Build 1-2 polished end-to-end projects (device → cloud → dashboard → some AI angle) and document them well (GitHub + write-up)
- Target roles specifically: "IoT Engineer," "Embedded Software Engineer," "IoT Solutions Engineer" — read 10-15 real job postings early to see which skills they actually weight
- Contribute to an open-source IoT project if possible — signals real capability

## Non-negotiable fundamentals (learn as you go, not later)
- **Voltage, current, resistance (Ohm's Law)** — calculating resistor values, whether a sensor will damage a GPIO pin
- **Pull-up/pull-down resistors** — prevents floating digital pins, used everywhere
- **Power supply basics** — 3.3V vs 5V logic levels, whether a battery/supply can source enough current
- **Digital vs analog signals** — when to use a digital pin vs an ADC pin, and why a sensor outputs one or the other

---

## Hardware inventory
Already have: breadboard, MyDAQ, Arduino Uno R3, USB cable, jumper wires
(M-M/M-F/F-F), assorted resistors (220Ω/1kΩ/10kΩ), assorted LEDs,
pushbuttons, 10kΩ potentiometer, piezo buzzer, DHT11 temp/humidity sensor.

Not yet bought (buy when a project needs it): ultrasonic sensors, motor
drivers, relays, ESP32/Bluetooth/WiFi modules (needed starting Month 2+),
16x2 LCD, servo motor.

---

## Progress log (Month 1-2: Embedded Foundations)
- [x] Arduino IDE installed and working
- [x] Blink — onboard LED + external LED alternating (`projects/Blink`)
- [x] Pushbutton with debounce, `INPUT_PULLUP`, `millis()`-based timing (`projects/Button`)
- [x] Analog input — potentiometer via `analogRead`, printed to Serial (`projects/Potentiometer`)
- [x] PWM output — fade an LED with `analogWrite` (`projects/Potentiometer`, pot controls brightness)
- [x] ButtonLED — combined digital input + output, button press lights an external LED (`projects/ButtonLED`)
- [x] Piezo buzzer — tones / simple melody, `tone()`/`noTone()` (`projects/Buzzer`)
- [x] ButtonBuzzer — edge detection, step through melody array one note per press (`projects/ButtonBuzzer`)
- [ ] DHT11 — read temperature/humidity
- [ ] Servo motor control
- [ ] I2C / SPI / UART concepts
- [ ] C/C++ embedded-level refresher (pointers, memory constraints)

---

## Extra topics gathered from research (2026-08-16)

Reviewed two additional sources and pulled out what's missing from the plan
above. Full detail kept here rather than merged line-by-line, so nothing
gets lost.

### Source 1: YouTube — "COMPLETE EMBEDDED SYSTEMS Roadmap - What Arduino
Won't Teach You" (hoff._world)

New concepts not yet in the roadmap above:
- Bare Metal vs RTOS, Interrupts vs Polling
- Hardware Abstraction Layer (HAL)
- Watchdog timers (WDG)
- Inertial Measurement Unit (IMU) — accelerometer/gyro sensors
- CANBUS and differential signalling
- Zigbee (alongside MQTT/BLE)
- Memory-Mapped I/O vs Port-Mapped I/O
- Direct Memory Access (DMA)
- Memory types: SRAM, EEPROM, Flash — the distinctions
- Resistor dividers (as an ADC-reading technique)
- Transistors and ICs as electronics fundamentals
- Signals and filtering
- Reading schematics and datasheets

### Source 2: Instagram — "Embedded Systems Engineer From Scratch" roadmap
(@mb.utronics)

A full 210-day (30-week), 3-stage day-by-day plan. Much more granular than
our month-based plan above. Useful as a project-by-project checklist to
pull from as we go. Full structure:

**Stage 1 — Beginner (Weeks 1-8, Days 1-56)**
Goal: electronics fundamentals, C programming, get a microcontroller
blinking/reading sensors/talking over UART.
- Week 1: C programming basics (variables, control flow, functions, arrays/strings, pointers pt.1)
- Week 2: C deep dive (pointers pt.2, structs/unions, bitwise ops, bit manipulation, stack vs heap, number systems)
- Week 3: Digital logic & basic electronics (logic gates, combinational logic, Ohm's Law, multimeter practice, diodes/LEDs, transistors as switches)
- Week 4: Meet the microcontroller (MCU architecture, toolchain setup, GPIO output/input, debouncing, datasheet reading) → capstone: traffic-light state machine
- Week 5: PWM & Analog (duty cycle/frequency/resolution, PWM on LED and motor, ADC theory + practice, analog sensor interfacing) → capstone: light-following servo/LED brightness project
- Week 6: Serial comms (UART theory, TX/RX, printf-style debugging, intro to I2C/SPI conceptually, Git basics) → capstone: serial-controlled LED dashboard
- Week 7: Integration practice (combine GPIO+ADC, PWM+UART, state machines, intentional-bug debugging practice, full datasheet register mapping)
- Week 8: Capstone — "Weather Station" (sensor + LED + UART report), full build+test+document+GitHub push
- Concepts checklist: number systems/boolean logic, Ohm's/Kirchhoff's laws, resistors/capacitors/diodes/transistors, pull-up/down resistors, MCU vs MPU vs CPU, memory map basics, reading datasheets
- Common beginner mistakes flagged: skipping pointers/memory concepts, wiring before learning electronics, no current-limiting resistor, copy-pasting without understanding registers, not using a multimeter to verify wiring, ignoring compiler warnings, no version control

**Stage 2 — Intermediate (Weeks 9-18, Days 57-126)**
Goal: move from Arduino-style to register-level/HAL firmware, interrupts, comms protocols, RTOS basics.
- Week 9: Register-level programming (memory-mapped I/O, clock tree/PLL, linker scripts, startup files, vector table, HAL vs raw register benchmarking)
- Week 10: Interrupts (NVIC, safe ISRs, `volatile` & race conditions, interrupt priorities/nesting, timer interrupts, interrupt-based debounce)
- Week 11: Timers & advanced PWM (input capture, output compare, complementary PWM w/ dead-time, servo control, frequency measurement, logic analyzer practice)
- Week 12: I2C protocol (addressing/ACK-NACK, master read/write, logic analyzer decode, error handling, I2C OLED display driver) → capstone: I2C sensor dashboard on OLED
- Week 13: SPI & DMA (clock polarity/phase modes, SPI master transfer, DMA theory, DMA+UART, DMA+ADC, CPU-usage comparison)
- Week 14: RTOS fundamentals — FreeRTOS (tasks/scheduler/context switching, porting FreeRTOS, task priorities/preemption, queues, semaphores, mutexes)
- Week 15: RTOS application (stack sizing via high-water-mark, software timers, priority inversion + fix via priority inheritance, sleep power modes, watchdog integration) → multi-peripheral RTOS app (I2C sensor + SPI display + UART logging), 24hr stress test
- Week 16: Debugging & version control (JTAG/SWD debugging, fault analysis via HardFault registers, static analysis/cppcheck, Git branching, code review practice, Makefile/CMake build systems)
- Week 17: Intro to PCB design (KiCad basics, schematic capture, footprints/libraries, PCB layout/routing, design rules, Gerber export)
- Week 18: Capstone — "Data Logger" (RTOS + I2C sensor + SPI storage + UART), with sleep/watchdog, long-duration power-cycle data-integrity testing
- Concepts checklist: register-level programming, interrupts, core peripherals (timers, advanced PWM, I2C, SPI, DMA), FreeRTOS fundamentals, JTAG/SWD debugging + logic analyzer, power modes/watchdog/basic PCB in KiCad/EEPROM-Flash wear leveling
- Toolkit: STM32 (or similar Cortex-M) dev board, ST-Link/J-Link debugger, logic analyzer, I2C/SPI sensor modules (IMU, OLED), FreeRTOS, KiCad, oscilloscope
- Common intermediate mistakes flagged: long blocking code inside an ISR, forgetting `volatile` on shared variables, underestimating RTOS task stack size, ignoring the watchdog timer, not debouncing in hardware, polling instead of interrupts/DMA, skipping RTOS priority design

**Stage 3 — Advanced (Weeks 19-30, Days 127-210)**
Goal: production-grade firmware — bootloaders, comms stacks, embedded Linux, security, functional safety.
- Week 19: Bootloader design (flash partition planning, minimal bootloader, vector table relocation, CRC validation, UART firmware update, dual-bank A/B scheme, simulated corrupted-update rollback test)
- Week 20: CAN bus (protocol theory/arbitration, transceiver setup, TX/RX, analyzer decode, CAN-FD basics, custom higher-layer protocol) → 2-node CAN sensor network demo
- Week 21: USB & BLE (USB descriptors/enumeration, USB CDC virtual COM port, USB HID, BLE GATT/services/characteristics, BLE peripheral + phone app connection, BLE data exchange)
- Week 22: Networking basics (TCP/IP fundamentals, lwIP stack on Ethernet, TCP server serving sensor data, MQTT publish, Modbus RTU slave, protocol selection tradeoffs) → networked sensor node reporting to a broker
- Week 23: Embedded Linux foundations (boot process: U-Boot → kernel → rootfs, cross-compilation toolchain, Buildroot custom image, device tree, flashing to SD/eMMC, systemd custom service)
- Week 24: Linux drivers (kernel module basics, character device driver, GPIO from userspace via sysfs/libgpiod, I2C driver binding, IRQ handler in kernel module, dmesg/printk debugging)
- Week 25: Security (threat modeling/attack surfaces, secure boot chain-of-trust theory, firmware signing/verification, flash readout protection + debug port lockout, AES encryption basics, secure element/TrustZone key storage)
- Week 26: Real-time & safety (WCET — worst-case execution time analysis, MISRA C essentials + static checker, ISO 26262/IEC 61508 functional safety overview, redundant sensor checks/graceful degradation, "safe state" fallback design)
- Weeks 27-30 (not shown in captured slides — likely covers advanced hardware topics + final capstone, based on the "Concepts You Must Master" list below)
- Concepts checklist: bootloaders/OTA/rollback, CAN-FD/USB/BLE/Ethernet-TCP-IP/Modbus, Yocto or Buildroot/device tree/kernel modules/systemd, secure boot/flash encryption/attack surfaces/secure element, WCET/MISRA C/ISO 26262/IEC 61508/fault-tolerant design, EMI/EMC-aware PCB layout, LDO vs switching regulator power design, multi-layer PCB stack-up, DSP fundamentals (filters, FFT on MCU)
- Toolkit: Cortex-A/embedded Linux SoC board (Raspberry Pi CM / i.MX), CAN transceiver + analyzer, BLE dev board, Yocto/Buildroot environment, oscilloscope with protocol decode, static analysis tool, secure element or MCU with TrustZone
- Common advanced mistakes flagged: no rollback plan for OTA updates (bricking risk), skipping MISRA/coding standards in production code, ignoring EMI/EMC in PCB layout, no WCET analysis for hard real-time tasks, treating embedded Linux like a desktop OS, weak/absent secure boot, designing without redundancy/fault handling

### How this reshapes our plan
The Instagram roadmap is a much finer-grained embedded-engineer path than
our Month 1-2 bullet list — worth using as the actual week-by-week
curriculum once we're past basic Arduino sketches (roughly once DHT11 +
servo + I2C/SPI basics are done). It confirms and deepens what the
YouTube video flagged (interrupts, DMA, RTOS, watchdogs, bootloaders,
CAN, security). Suggest treating "Month 1-2: Embedded Foundations" above
as covering Instagram Stage 1 Weeks 1-8, then slotting Instagram Stage 2
(register-level/RTOS/protocols) into "Month 3-4: Connectivity", and
Instagram Stage 3 (bootloaders/Linux/security/safety) into "Month 7-8:
PCB Basics + Power/Real-World Constraints" and beyond.
