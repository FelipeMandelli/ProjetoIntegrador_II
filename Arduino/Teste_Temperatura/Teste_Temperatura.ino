/* ========================================================================================================
 
   Curso de Arduino e AVR 120
   
   WR Kits Channel


   Termômetro à Prova d'água

    
   Autor: Eng. Wagner Rambo  Data: Maio de 2017
   
   www.wrkits.com.br | facebook.com/wrkits | youtube.com/user/canalwrkits | dailymotion.com/wrkits



   HARDWARE:

   Fio vermelho do sensor -> 5V do Arduino
   Fio preto do sensor    -> GND do Arduino
   Fio amarelo do sensor  -> digital 3 do Arduino (ligar um resistor de 4,7k entre esta entrada e os 5V)
   
   
======================================================================================================== */


// ========================================================================================================
// --- Bibliotecas Auxiliares ---
#include <OneWire.h>
#include <DallasTemperature.h>


// ========================================================================================================
// --- Mapeamento de Hardware ---
#define    ONE_WIRE_BUS     4          //sinal do sensor DS18B20


// ========================================================================================================
// --- Declaração de Objetos ---
OneWire oneWire(ONE_WIRE_BUS);        //objeto one_wire
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;


// ========================================================================================================
// --- Protótipo das Funções ---
void mostra_endereco_sensor(DeviceAddress deviceAddress);  //Função para mostrar endereço do sensor


// ========================================================================================================
// --- Variáveis Globais ---
float tempMin = 999;   //armazena temperatura mínima
float tempMax = 0;     //armazena temperatura máxima

 


// ========================================================================================================
// --- Configurações Iniciais ---
void setup() 
{
  Serial.begin(9600);
  
  sensors.begin();
  
  // Localiza e mostra enderecos dos sensores
  Serial.println("Localizando sensores DS18B20...");
  Serial.print("Foram encontrados ");
  Serial.print(sensors.getDeviceCount(), DEC);
  Serial.println(" sensores.");
  
  if (!sensors.getAddress(sensor1, 0)) 
     Serial.println("Sensores nao encontrados !"); 
     
  // Mostra o endereco do sensor encontrado no barramento
  Serial.print("Endereco sensor: ");
  mostra_endereco_sensor(sensor1);
  Serial.println();
  Serial.println();
  

} //end setup


// ========================================================================================================
// --- Loop Infinito ---
void loop() 
{
  // Le a informacao do sensor
  sensors.requestTemperatures();
  float tempC = sensors.getTempC(sensor1);
  
  // Atualiza temperaturas minima e maxima
  if (tempC < tempMin)
  {
    tempMin = tempC;
  }
  if (tempC > tempMax)
  {
    tempMax = tempC;
  }
  
  // Mostra dados no serial monitor
  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print(" Min : ");
  Serial.print(tempMin);
  Serial.print(" Max : ");
  Serial.println(tempMax);
   
 
  delay(1350);
  
 
} //end loop


// ========================================================================================================
// --- Desenvolvimento das Funções ---


// ========================================================================================================
// --- Função para mostrar endereço do sensor ---
void mostra_endereco_sensor(DeviceAddress deviceAddress)
{
  for (uint8_t i = 0; i < 8; i++)
  {
    // Adiciona zeros se necessário
    if (deviceAddress[i] < 16) Serial.print("0");
    Serial.print(deviceAddress[i], HEX);
  }
}


 
  
