//I2C SLAVE 4 DATA JETSON

#include <Wire.h>

//int dataTerima ;
unsigned long previousMillis = 0;
const long interval = 100; // interval waktu tunggu dalam milisecond

struct DataPacket {
  byte data1;
  byte data2;
  byte data3;
  byte data4;
};

DataPacket receivedData;

void setup() {
  Serial.begin(115200);
  Wire.begin(0x55);
  Wire.onReceive(terima);
}

void terima(int howMany) {
  byte i = 0;
  while (Wire.available()) {
    byte receivedByte = Wire.read(); // Membaca data yang dikirimkan oleh master
    // Menyimpan data yang diterima ke variabel receivedData sesuai dengan indeks
    if (i == 2) {
      receivedData.data1 = receivedByte;
    } else if (i == 3) {
      receivedData.data2 = receivedByte;
    } else if (i == 4) {
      receivedData.data3 = receivedByte;
    } else if (i == 5) {
      receivedData.data4 = receivedByte;
    }
    i++;
  }
}

void loop() {
  unsigned long currentMillis = millis(); // waktu saat ini
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis; // update waktu sebelumnya
    // Menggunakan dan menampilkan data yang diterima
  Serial.print("Received Data: ");
  Serial.print(receivedData.data1);
  Serial.print(", ");
  Serial.print(receivedData.data2);
  Serial.print(", ");
  Serial.print(receivedData.data3);
  Serial.print(", ");
  Serial.println(receivedData.data4);
 
  }
}
