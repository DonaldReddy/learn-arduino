/*
  Potentiometer -> PWM LED brightness

  Reads a 10k potentiometer and uses analogWrite() (PWM) to fade an
  external LED's brightness in proportion to the pot's position.

  Wiring:
    - Pot left leg  -> GND
    - Pot right leg -> 5V
    - Pot wiper (middle leg) -> A0
    - LED long leg (anode) -> 220ohm resistor -> pin 9
    - LED short leg (cathode) -> GND

  IMPORTANT: pin 9 was chosen because it's PWM-capable (marked with a
  ~ on the board silkscreen: pins 3, 5, 6, 9, 10, 11 on the Uno).
  LED_BUILTIN (pin 13) does NOT support PWM, so it can't be used here.

  Concept: analogWrite() doesn't produce a true analog voltage - the
  Uno has no DAC. Instead it rapidly switches the pin HIGH/LOW (PWM -
  Pulse Width Modulation) at ~490Hz. The "duty cycle" (% of time spent
  HIGH per cycle) controls perceived brightness: 0 = always off,
  255 = always on, values in between blink faster than the eye can
  see, so it looks like a dimmer light rather than a flicker.
*/

const int potPin = A0;
const int ledPin = 9;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int rawValue = analogRead(potPin);              // 0-1023
  float voltage = rawValue * (5.0 / 1023.0);       // convert to 0-5V
  int brightness = map(rawValue, 0, 1023, 0, 255); // ADC range -> PWM range

  Serial.print("Raw: ");
  Serial.print(rawValue);
  Serial.print("\tVoltage: ");
  Serial.print(voltage);
  Serial.print("V\tBrightness: ");
  Serial.println(brightness);

  analogWrite(ledPin, brightness);
}
