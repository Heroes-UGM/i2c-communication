//I2C MASTER 1 DATA

#include <Wire.h>

int myData;
unsigned long previousMillis = 0;
const long interval = 100; // interval waktu dalam milidetik

void setup() {
  Wire.begin(0x55);        // Inisialisasi I2C
  Serial.begin(115200);  // Inisialisasi Serial Monitor
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    //  if (Serial.available()) {
    //    myData = Serial.readString().toInt();   // Baca data dari input
    // }
    myData = abs(sin(currentMillis) * 100); // Bikin sinus
    Serial.println(myData);
    Wire.beginTransmission(0x55);  // Alamat slave
    Wire.setClock(100000);
    Wire.write(myData);
    Wire.endTransmission();     // Selesai mengirim
  }
}
