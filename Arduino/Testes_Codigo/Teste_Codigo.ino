//----------------------------------------------------------//
//----------------------------------------------------------//


//Inclui Bibliotecas
  #include <OneWire.h>
  #include <DallasTemperature.h>
  #include <TinyGPS++.h>
  #include <SoftwareSerial.h>

//Define Ajuste do fuso horario ( -3 para Brasilia)
  int fuso = -3;

//Define Pinagem

  //Define o Pino 4 como Sensor de Temperatura
    #define ONE_WIRE_BUS 4 


  //Define o Pino A0 como Sensor de pH
    const int pino_PH = A0;

  //Define os Pinos RX e TX do GPS
    const int RXgps = 2;
    const int TXgps = 3;

  //Define Pino A1 como Sensor de Turbidez
    const int pino_Turb = A1;


//Declarando Objetos 

  //Objetos Sensor Temperatura
  OneWire oneWire(ONE_WIRE_BUS);        
  DallasTemperature sensors(&oneWire);
  DeviceAddress sensor1;

  //Objetos GPS
  TinyGPSPlus gps;
  SoftwareSerial gpsSerial(RXgps, TXgps);


//Define Baud Rate do GPS
  int gpsBaud = 9600;


//Funcoes

  //Obter o Ph por Referencia (Ponteiros)
  void LerValorPH(float *pPH, bool *pStaPh){

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
      if (ph_valor >= 0 && ph_valor <= 14){

        *pStaPh = true;
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
    *pTurb = media_prec_turb/6;
    
    //Impede Resultado Absurdo
    if ((media_prec_turb/6) >= 0 && (media_prec_turb/6) <= 1024){

      *pStaTurb = true;
    }
  }
  
  //Obter Posicao do GPS por Referencia (Ponteiros)
  void LerPosicaoGPS(float *pLat, float *pLongi, float *pAlt, bool *pStaPosGPS){

    if (gps.location.isValid()){

      *pLat = gps.location.lat();
      *pLongi = gps.location.lng();
      *pAlt = gps.altitude.meters();
      *pStaPosGPS = true;
    }
    else {

      *pStaPosGPS = false;
    }
  }

  //Obter Data do GPS por Referencia (Ponteiros)
  void LerDataGPS (int *pA, int *pM, int *pD, bool *pStaDataGPS){

    if (gps.date.isValid()){

      *pA = gps.date.year();
      *pM = gps.date.month();
      *pD = gps.date.day();
      *pStaDataGPS = true;
    }
    else {

      *pStaDataGPS = false;
    }
  }

  //Obter Hora do GPS por Referencia (Ponteiros)
  void LerHoraGPS (int *pHr, int *pMin, int *pSeg, bool *pStaHoraGPS){

    if (gps.time.isValid()){

      *pHr = gps.time.hour() + fuso; //Para fuso Horario indicado 
      *pMin = gps.time.minute();
      *pSeg = gps.time.second();
      *pStaHoraGPS = true;
    }
    else {

      *pStaHoraGPS = false;
    }
    
  }


void setup() {

  //Inicia Monitor Serial
  Serial.begin(9600);

  //Inicializa o sensor de Temperatura
  sensors.begin();

  //Inicializacao do Endereco do sensor de temperatura
  sensors.getAddress(sensor1, 0);

  //Inicia a Porta Serial do GPS
  gpsSerial.begin(gpsBaud);
  
}




void loop() {

  //Variaveis Controladoras 
  bool statusPh = false;
  bool statusTemperatura = false;
  bool statusTurbidez = false;  
  bool statusGPS = false;

  
  //Variaveis de informacoes
  float valorSensorPh;
  float valorSensorTemperatura;
  int valorSensorTurbidez;
  
  //Variaveis de infos do GPS
  float Latitude, Longitude, Altitude;
  int Ano, Mes, Dia;
  int Hora, Minuto, Segundo;
  bool statusPosGPS = false;
  bool statusDataGPS = false;
  bool statusHoraGPS = false;


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
      Serial.println("Valor nao Obtido");
    }

    Serial.println();
  }


  if(statusGPS != true){
    
    //Variavel para Limitar a Espera pelos dados do GPS
    unsigned long inicioGPS = millis();
    
    Serial.println("Dados do GPS: ");
    
    //Loop para Buscar as informacoes do GPS
    while (statusGPS != true){
      if (gpsSerial.available() > 0){

        if (gps.encode(gpsSerial.read())){

          //Chama a funcao LerPosicaoGPS                   
          LerPosicaoGPS(&Latitude, &Longitude, &Altitude, &statusPosGPS);

          //Chama a funcao LerDataGPS
          LerDataGPS(&Ano, &Mes, &Dia, &statusDataGPS);

          //Chama a funcao LerHoraGPS
          LerHoraGPS(&Hora, &Minuto, &Segundo, &statusHoraGPS);

          //Confere se, devido ao fuso horario necessita alteracoes na hora e dia
          if (Hora < abs(fuso)){

              Hora += 24;
              Dia -= 1;
            }
  
          //Escreve, se houver, o Valor no monitor serial
          if (statusPosGPS == true){

            Serial.print("\t\tLatitude: ");
            Serial.println(Latitude, 6);
            Serial.print("\t\tLongitude: ");
            Serial.println(Longitude, 6);
            Serial.print("\t\tAltitude: ");
            Serial.println(Altitude);
            statusGPS = true;
          }
  
          if (statusDataGPS == true){

            Serial.print("\t\tData: ");
            Serial.print(Dia);
            Serial.print("/");
            Serial.print(Mes);
            Serial.print("/");
            Serial.println(Ano);
            statusGPS = true;
          }

          if (statusHoraGPS == true){

            Serial.print("\t\tHora: ");
            Serial.print(Hora);
            Serial.print(":");
            Serial.print(Minuto);
            Serial.print(":");
            Serial.println(Segundo);
            statusGPS = true;
          }
        }
      }

      //Se espera exceder 1 segundo, sai do loop
      if ((millis() - inicioGPS) > 1000){

        Serial.println("Tempo Expirado");
        goto controleTempo;
      }
    }

    //Rotulo para limite do tempo
    controleTempo:
    Serial.println();
  }

  delay(1000);
}