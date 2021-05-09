#include <SoftwareSerial.h>
SoftwareSerial s(5, 6);
#define USE_ARDUINO_INTERRUPTS true
#include <PulseSensorPlayground.h>

const int PulseWire = 0;
const int LED13 = 13;
int Threshold = 550;
int myBPM1;

PulseSensorPlayground pulseSensor;

void setup() {
  s.begin(9600);
  Serial.begin(9600);
  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
    s.println("Ready!");
  }
}
void loop() {

  int myBPM = pulseSensor.getBeatsPerMinute();
  if (s.available() > 0)
  {
    s.write(myBPM);
  }
  Serial.println(myBPM);
}
