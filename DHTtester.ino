#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht (DHTPIN,DHTTYPE);

#define BLYNK_TEMPLATE_ID           "TMPLKKgXqt2f"
#define BLYNK_DEVICE_NAME           "IoT"
#define BLYNK_AUTH_TOKEN            "iiyeYEpaiNy1OEGtQgzSmNaev0eBG5ke"

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Wifi.id";
char pass[] = "adaapa123";
const char* host = "blynk.en-26.com";
unsigned int port = 9600;

BlynkTimer timer;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass, host, port);
}

void loop() {
  float s = dht.readTemperature();
  float h = dht.readHumidity();
 
  Serial.print("suhu :");
  Serial.print(s);
  Serial.print(",");
  Serial.print("Kelembaban :");
  Serial.print(h);
  Serial.print("\n");

  Blynk.virtualWrite(V0, s);
  Blynk.virtualWrite(V1, h);
  delay(5000);
  Blynk.run();
}
 
