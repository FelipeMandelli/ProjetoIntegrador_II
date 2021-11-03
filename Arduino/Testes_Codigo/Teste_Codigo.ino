#include <OneWire.h>
#include <DallasTemperature.h>

#define    ONE_WIRE_BUS     4 

OneWire oneWire(ONE_WIRE_BUS);        
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;


// Funcoes

  void mostra_endereco_sensor(DeviceAddress deviceAddress){
    for (uint8_t i = 0; i < 8; i++){
      // Adiciona zeros se necessário
      if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
    }
  }

  void inicializa_sensor_temperatura() {
                                                                   
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
  
  }


  int LerValorPH(int ValorPH, boolean statusPh){
  // pega o Ph
  }

  int LerValorTemperatura(float *pTemp, boolean *pStemp){
     // pega a Temperatura
     sensors.begin();
     sensors.requestTemperatures();
     float tempC = sensors.getTempC(sensor1);
     *pTemp = tempC;
     *pStemp = true;
         
  }
  
  int LerValorTurbidez(int Valorurbidez, boolean statusTurbidez){
   // pegar Turbiez
  }
  
  int LerValorGPS(int ValorGPS, boolean statusGPS){
   // pega o  GPS
  }


void setup() {
  
  Serial.begin(9600);

  sensors.begin();

  inicializa_sensor_temperatura();
  
}




void loop() {

  // controladores 
  boolean statusPh = false;
  boolean statusTemperatura = false;
  boolean statusTurbidez = false;  
  boolean statusGPS = false;

  
  // informacoes obtidas
  int valorSensorPh;
  float valorSensorTemperatura;
  int valorSensorTurbidez;
  int informacoesGps;
   
  if(statusTemperatura != true){
    //Chama a funcao LerValorTemperatura             
    LerValorTemperatura(&valorSensorTemperatura, &statusTemperatura);
   
    Serial.print("Valor do sensor de Temperatura: ");
    if (statusTemperatura == true){
      Serial.print(valorSensorTemperatura);
      Serial.println ("C");
    }
    else {
    Serial.println("Valor nao Obtido");
    }

    Serial.println();
    Serial.println();
  }

  
  delay(1000);
  
//  if(statusPh != true){
//    //Chama a funcao LerValorPH                    
//    LerValorPH(valorSensorPh,statusPh);
//    Serial.println("Valor do sensor de pH: ");
//    if (statusPh == true){
//      Serial.println(valorSensorPh);
//    }
//    else 
//    Serial.println("Valor nao Obtido");
//  }
//
//  if(statusTurbidez != true){
//    //Chama a funcao LerValorGPS                   
//    LerValorTurbidez(valorSensorTurbidez, valorSensorTurbidez);
//  }
//
//  if(statusGPS != true){
//    //Chama a funcao LerValorGPS                   
//    LerValorTurbidez(valorSensorTurbidez, informacoesGps);
//  }

}