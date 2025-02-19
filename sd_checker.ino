#include "SPI.h"
#include "SD.h"
Sd2Card card;
SdVolume volume;
SdFile root;
const int chipSelect = 4;
void setup(){
  Serial.begin(9600);
  pinMode(SS, OUTPUT);
  while(!card.init(SPI_HALF_SPEED, chipSelect)){
    Serial.println("Ошибка инициализации карты!");
  }
  Serial.println("Тип карты: ");
  switch(card.type()){
    case SD_CARD_TYPE_SD1:
      Serial.print("SD1");
      break;
    case SD_CARD_TYPE_SD2:
      Serial.print("SD2");
      break;
    case SD_CARD_TYPE_SDHC:
      Serial.print("SDHC");
      break;
    default:
      Serial.print("unknown");
  }
  if (!volume.init(card)){
    Serial.println("Не могу найти FAT16/32 систему");
    return;
  }
  Serial.println(volume.fatType(), DEC);
  Serial.println("Файлы на карте: ");
  root.openRoot(volume);
  root.ls(LS_R | LS_DATE | LS_SIZE);
}
void loop(){}