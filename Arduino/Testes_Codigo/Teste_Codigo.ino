#include <OneWire.h>
#include <DallasTemperature.h>

#define    ONE_WIRE_BUS     4 

OneWire oneWire(ONE_WIRE_BUS);        
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;


//Funcoes

  //Funcao para Obter o Endereco do sensor de Temperatura
  void mostra_endereco_sensor(DeviceAddress deviceAddress){
    for (uint8_t i = 0; i < 8; i++){
      //Adiciona zeros se necessário
      if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
    }
  }

  //Funcao para Inicializar, Obter e Mostrar o Endereco Temperatura
  void inicializa_sensor_temperatura() {                                                       
    //Localiza e mostra endereco do sensor de Temperatura
    Serial.println("Localizando sensores DS18B20...");
    Serial.print("Foram encontrados ");
    Serial.print(sensors.getDeviceCount(), DEC);
    Serial.println(" sensores.");
  
    if (!sensors.getAddress(sensor1, 0)){
      Serial.println("Sensores nao encontrados !"); 
     Serial.println("Sensores nao encontrados !"); 
      Serial.println("Sensores nao encontrados !"); 
    }
      
    //Mostra o endereco do sensor encontrado
    Serial.print("Endereco sensor: ");
  
    mostra_endereco_sensor(sensor1);
 
    Serial.println();
    Serial.println();
  
  }

  //Obter o Ph
  int LerValorPH(int ValorPH, boolean statusPh){
  
  }
  
  // Obter a Temperatura
  int LerValorTemperatura(float *pTemp, boolean *pStemp){
     
     //Declaracao e Inicializa sensor
     float vet_precisao[10], aux, media_prec_Temp = 0;
     sensors.begin();
     sensors.requestTemperatures();
     
     //Obtem 10 valores para media, aumentando precisao
     for(int i = 0; i < 10; i++){
       vet_precisao[i] = sensors.getTempC(sensor1);
       delay(50);
     }
     
     //Organiza o vetor em ordem crescente
     for (int i = 0; i < 9; i++){
       
       for (int j = i+1; j < 10; j++){
       
         if (vet_precisao[i] > vet_precisao[j]){
           aux = vet_precisao[i];
           vet_precisao[i] = vet_precisao[j];
           vet_precisao[j] = aux;
         }
       }
     }

    //Exclui 2 maiores e 2 menores valores
     for (int i = 2; i < 8; i++){
       media_prec_Temp += vet_precisao[i];
     }

    //Devolve os Valores de Saida
     *pTemp = media_prec_Temp/6;
     *pStemp = true;
         
  }
  
  //Obter Turbiez
  int LerValorTurbidez(int Valorurbidez, boolean statusTurbidez){
   
  }
  
  //Obter GPS
  int LerValorGPS(int ValorGPS, boolean statusGPS){
   
  }


void setup() {
  
  Serial.begin(9600);

  sensors.begin();

  inicializa_sensor_temperatura();
  
}




void loop() {

  //Controladores 
  boolean statusPh = false;
  boolean statusTemperatura = false;
  boolean statusTurbidez = false;  
  boolean statusGPS = false;

  
  //Informacoes
  int valorSensorPh;
  float valorSensorTemperatura;
  int valorSensorTurbidez;
  int informacoesGps;
   
  //Obter os Valores da Temperatura 
  if(statusTemperatura != true){
    
    //Chama a funcao LerValorTemperatura             
    LerValorTemperatura(&valorSensorTemperatura, &statusTemperatura);
   
    //Escreve, se houver, o Valor no monitor serial
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