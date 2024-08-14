#include <SPI.h>
#include <WiFi.h>

const int pirPin = 2; 
int pirState = LOW;  

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  
  WiFi.begin("móveismorante2ghz", "morante@12345");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao WiFi...");
  }
  Serial.println("Conectado ao WiFi.");
}

void loop() {
  int val = digitalRead(pirPin);
  if (val == HIGH) {
    if (pirState == LOW) {
      Serial.println("Movimento detectado!");
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH) {
      Serial.println("Movimento parado!");
      pirState = LOW;
    }
  }
  delay(500);
}
