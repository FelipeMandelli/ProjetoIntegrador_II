//----------------------------------------------------------//
//----------------------------------------------------------//


//Inclui Bibliotecas
#include <OneWire.h>
#include <DallasTemperature.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

//Define Pinagem

//Define o Pino 4 como Sensor de Temperatura
#define ONE_WIRE_BUS 4 

//

//Define o Pino A0 como Sensor de pH
const int pino_PH = A0;

//Define os Pinos RX e TX do GPS
const int RXgps = 2;
const int TXgps = 3;

//Define Pino A1 como Sensor de Turbidez
const int pino_Turb = A1;


//Declarando Objetos 

//Objetos Sensor Temperatura
neWire oneWire(ONE_WIRE_BUS);        
DallasTemperature sensors(&oneWire);
DeviceAddress sensor1;

//Objetos GPS
TinyGPSPlus gps;
SoftwareSerial gpsSerial(RXgps, TXgps);


//Define Baud Rate do GPS
int gpsBaud = 9600;


//Funcoes

  //Funcao para mostrar o Endereco do sensor de Temperatura
  void mostra_endereco_sensor(DeviceAddress deviceAddress){
    for (uint8_t i = 0; i < 8; i++){
      //Adiciona zeros se necessário
      if (deviceAddress[i] < 16) Serial.print("0");
      Serial.print(deviceAddress[i], HEX);
    }
  }

  //Funcao para Inicializar, Obter e Mostrar o Endereco da Temperatura
  void inicializa_sensor_temperatura() {                                                       
    //Localiza e mostra endereco do sensor de Temperatura
    Serial.println("Localizando sensores DS18B20...");
    Serial.print("Foram encontrados ");
    Serial.print(sensors.getDeviceCount(), DEC);
    Serial.println(" sensores.");
  
    if (!sensors.getAddress(sensor1, 0)){
      Serial.println("Sensores nao encontrados !");  
    }
      
    //Mostra o endereco do sensor encontrado
    Serial.print("Endereco sensor: ");
  
    mostra_endereco_sensor(sensor1);
 
    Serial.println();
    Serial.println();
  
  }

  //Obter o Ph por Referencia (Ponteiros)
  void LerValorPH(int *pPH, bool *pStaPh){
    //Declara Variaveis
    float vet_precisao[10],media_prec_ph = 0, aux, conver_aux;
    float ph_valor, calibragem = 21.34 - 0.3;

    //Obtem 10 valores para media, aumentando precisao
    for(int i = 0; i < 10; i++){
      vet_precisao[i] = analogRead(pino_PH);
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
      media_prec_ph += vet_precisao[i];
    }

    //Converte para Leitura de Voltagem o valor medio
    conver_aux = media_prec_ph / 6 * (5.0/1024.0);

    //Converte para valor final do pH
    ph_valor = -5.70 * conver_aux + calibragem;

    //Devolve Valores de Saida
    *pPH = ph_valor;
    //Impede Resultado Absurdo
    if (ph_valor >= 0 ) and (ph_valor <= 14){
      *pStaPh = true
    }
  }
  
  // Obter a Temperatura por Referencia (Ponteiros)
  void LerValorTemperatura(float *pTemp, bool *pStaTemp){
     
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
     *pStaTemp = true;
         
  }
  
  //Obter Turbiez por Referencia (Ponteiros)
  void LerValorTurbidez(int *pTurb, bool *pStaTurb){
   int vet_precisao[10], aux, media_prec_turb = 0;

    //Obtem 10 valores para media, aumentando precisao
    for(int i = 0; i < 10; i++){
      vet_precisao[i] = analogRead(pino_Turb);
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
      media_prec_turb += vet_precisao[i];
    }

    //Devolve os Valores de Saida
    *pTurb = media_prec_turb/6
    //Impede Resultado Absurdo
    if ((media_prec_turb/6) >= 0 ) and ((media_prec_turb/6) <= 1024){
      *pStaPh = true
    }
  }
  
  //Obter GPS por Referencia (Ponteiros)
  int LerValorGPS(int ValorGPS, bool statusGPS){
   
  }


void setup() {
  //Inicia Monitor Serial
  Serial.begin(9600);

  //Inicializa o sensor de Temperatura
  sensors.begin();

  //Chamada funcao de inicializacao da Temperatura e do Endereco do sensor
  inicializa_sensor_temperatura();

  //Inicia a Porta Serial do GPS
  gpsSerial.begin(gpsBaud);
  
}




void loop() {

  //Controladores 
  bool statusPh = false;
  bool statusTemperatura = false;
  bool statusTurbidez = false;  
  bool statusGPS = false;

  
  //Informacoes
  float valorSensorPh;
  float valorSensorTemperatura;
  int valorSensorTurbidez;
  int informacoesGps;
   

  //Obter o Valor da Temperatura 
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
  }

  
  //Obter o Valor do pH
  if(statusPh != true){
    
    //Chama a funcao LerValorPH                    
    LerValorPH(&valorSensorPh,&statusPh);
    
    //Escreve, se houver, o Valor no monitor serial
    Serial.print("Valor do sensor de pH: ");
    if (statusPh == true){
      Serial.println(valorSensorPh);
    }

    else {
      Serial.println("Valor nao Obtido");
    }

    Serial.println();
 }
  

  //Obter o Valor de Turbidez
  if(statusTurbidez != true){
    //Chama a funcao LerValorTurbidez                  
    LerValorTurbidez(&valorSensorTurbidez, &statusTurbidez);

    //Escreve, se houver, o Valor no monitor serial
    Serial.print("Valor do sensor de Turbidez: ");
    if (statusTurbidez == true){
      Serial.println(valorSensorTurbidez);
    }

    else {
      Serial,println("Valor nao Obtido");
    }

    Serial.println();
  }

//
//  if(statusGPS != true){
//    //Chama a funcao LerValorGPS                   
//    LerValorTurbidez(valorSensorTurbidez, informacoesGps);
//  }

  delay(1000);

}