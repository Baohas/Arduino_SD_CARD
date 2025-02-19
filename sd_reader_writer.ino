#include "SPI.h"
#include "SD.h"

File myFile;

const int chipSelect = 4;
void setup(){
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  while(!SD.begin(SPI_HALF_SPEED, chipSelect)){
    Serial.println("Ошибка инициализации карты!");
  }
  myFile = SD.open("test.txt", FILE_WRITE);
  if (myFile){
    myFile.println("Здесь ваша надпись");
    myFile.close();
  }
  else{Serial.print("Не удалось открыть файл");}
  myFile = SD.open("test.txt");
  if (myFile){
    while (myFile.available()){
      Serial.write(myFile.read());
    }
    myFile.close();
  }
}
void loop(){}