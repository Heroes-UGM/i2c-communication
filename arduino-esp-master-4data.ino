//I2C MASTER 4 DATA

#include <Wire.h>

//int myData;     // Mengirim 1 data
unsigned long previousMillis = 0;
const long interval = 100; // interval waktu dalam milidetik

struct DataPacket {     // Mengirim >1 data
  byte data1;           
  byte data2;
  byte data3;
  byte data4;
};

DataPacket dataToSend;

void setup() {
  Wire.begin(0x55);        // Inisialisasi I2C
  Serial.begin(115200);  // Inisialisasi Serial Monitor

  // Inisialisasi nilai data dalam variabel dataToSend
  dataToSend.data1 = 10;
  dataToSend.data2 = 20;
  dataToSend.data3 = 30;
  dataToSend.data4 = 40;
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    //  if (Serial.available()) {
    //    myData = Serial.readString().toInt();   // Baca data dari input
    // }
    // //myData = abs(sin(currentMillis) * 100); // Bikin sinus
    // Serial.println(myData);
    sendPacketToSlave();    //Memanggil fungsi pengiriman data paket
  }
  Serial.println(dataToSend.data1);
  Serial.println(dataToSend.data2);
  Serial.println(dataToSend.data3);
  Serial.println(dataToSend.data4);
}

void sendPacketToSlave() {
  Wire.beginTransmission(0x55); // Alamat slave (misalnya 0x42)

  // Mengirim data dari variabel dataToSend ke slave
  Wire.write(dataToSend.data1);
  Wire.write(dataToSend.data2);
  Wire.write(dataToSend.data3);
  Wire.write(dataToSend.data4);

  Wire.endTransmission(); // Mengakhiri transmisi
}
