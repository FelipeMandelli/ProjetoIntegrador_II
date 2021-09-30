//----------------------------------------------------------//
//----------------------------------------------------------//
//  Codigo utilizado para testar o funcionamento do modulo  //
//  ESP8266 01 Por meio do monitor serial do Arduino IDE    //
//  e comandos AT. Este codigo generico foi encontrado na   //
//  internet e nao foi produzido pelo grupo. Encontrado no  //
//  site Robocore, por  Giovanni de Castro em:              //
//  robocore.net/tutoriais/conectando-esp8266-no-arduino    //
//----------------------------------------------------------//
//----------------------------------------------------------//


#include "SoftwareSerial.h"

SoftwareSerial ESP_Serial(10, 11); // RX, TX

void setup(){
  Serial.begin(9600);
  ESP_Serial.begin(9600);
}

void loop(){
  if (ESP_Serial.available()){
    Serial.write(ESP_Serial.read());
  }
  if (Serial.available()){
    ESP_Serial.write(Serial.read());
  }
}
