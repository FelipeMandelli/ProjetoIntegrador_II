//----------------------------------------------------------//
//----------------------------------------------------------//
//  Codigo utilizado para testar o funcionamento do modulo  //
//  GPS modelo NEO-6M V2 por meio do monitor serial do      //
//  Arduino IDE. Este codigo generico foi encontrado na     //
//  internet e nao foi produzido pelo grupo. Encontrado no  //
//  site Last Minute Engineers, em:                         //
//  lastminuteengineers.com/neo6m-gps-arduino-tutorial/     //
//----------------------------------------------------------//
//----------------------------------------------------------//


#include <SoftwareSerial.h>

//  Choose two Arduino pins to use for software serial
int RXPin = 2;
int TXPin = 3;

//  Default baud of NEO-6M is 9600
int GPSBaud = 9600;

//  Create a software serial port called "gpsSerial"
SoftwareSerial gpsSerial(RXPin, TXPin);

void setup()
{
  // Start the Arduino hardware serial port at 9600 baud
  Serial.begin(9600);

  // Start the software serial port at the GPS's default baud
  gpsSerial.begin(GPSBaud);
}

void loop()
{
  // Displays information when new sentence is available.
  while (gpsSerial.available() > 0)
    Serial.write(gpsSerial.read());
}
