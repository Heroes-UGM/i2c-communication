//I2C SLAVE 1 DATA

#include <Wire.h>

int ledPin = 27;
int dataTerima ;
unsigned long previousMillis = 0;
const long interval = 10; // interval waktu tunggu dalam milisecond

void setup() {
  Serial.begin(115200);
  Wire.begin(0x55);
  Wire.onReceive(terima);
  pinMode(ledPin, OUTPUT);
}

void terima(int howMany) {
  while (Wire.available()) { // Membaca semua data yang tersedia
     int dataTerima = Wire.read(); // Mengambil data yang diterima
     Serial.println(dataTerima);
  }
}

void loop() {
  unsigned long currentMillis = millis(); // waktu saat ini
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // update waktu sebelumnya
    if (dataTerima == 1) {
      digitalWrite(ledPin, HIGH);
      //Serial.println("LED ON");
      // Serial.println(dataTerima);
    } else {
      digitalWrite(ledPin, LOW);
      //Serial.println("LED OFF");
      // Serial.println(dataTerima);
    }
  }
}
