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







ss://Y2hhY2hhMjAtaWV0Zi1wb2x5MTMwNTpSbzhWTU1uczFZbU9pUXBiYkZXaEd3@185.184.122.202:1080#%F0%9F%9A%80%20Marz%20%28VVERX%29%20%5BShadowsocks%20-%20tcp%5D
vless://d49b3634-86a5-4a12-bb28-e5956f68496b@185.184.122.202:443?security=reality&type=tcp&headerType=&path=&host=&sni=yandex.ru&fp=chrome&pbk=zA7TLStV_XIJ62KF6Pbz09mds5xl82sk-2dtEEvHtDA&sid=71362594b31dc78a#%F0%9F%9A%80%20Marz%20%28VVERX%29%20%5BVLESS%20-%20tcp%5D
