#include <Wire.h>
#include <Adafruit_MLX90614.h>
#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

const char* ssid = "Trikuldham";
const char* password = "jaihanuman1981";

SoftwareSerial s(D6, D5);
Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void setup() {
  Serial.begin(9600);
  s.begin(9600);
  mlx.begin();
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print("Connecting..");
  }
}

void loop() {
  Serial.println(mlx.readObjectTempF() + 7);
  String hr = String(s.read()/2);
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin("http://covinspect.herokuapp.com/input?ir="+String(mlx.readObjectTempF())+"&hr="+hr);
    int httpCode = http.GET();
    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println(payload);
    }
    http.end();
  }
  delay(1000);
}
