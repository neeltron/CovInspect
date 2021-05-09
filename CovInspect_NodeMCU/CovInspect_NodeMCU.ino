#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <SoftwareSerial.h>

SoftwareSerial s(D6, D5);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  s.begin(9600);
  mlx.begin();
}

void loop() {
  Serial.println(mlx.readObjectTempF() + 7);
  Serial.println(s.read());
  delay(1000);
}
