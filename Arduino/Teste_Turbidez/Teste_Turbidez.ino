//----------------------------------------------------------//
//----------------------------------------------------------//
//  Codigo utilizado para testar o funcionamento do modulo  //
//  de Turbidez  modelo TS-300 B Por meio do monitor serial //
//  do Arduino IDE. Este codigo foi produzido pelo grupo    //
//  com a finalidade de Observar os valores analogicos e    //
//  de Voltagem do Sensor                                   //
//----------------------------------------------------------//
//----------------------------------------------------------//


void setup() {
  Serial.begin(9600);
}

void loop() {
  int valorSensor = analogRead(A1);
  float voltagem = valorSensor * (5.0/1024.0);

  Serial.print("Leitura: ");
  Serial.println(valorSensor);
  Serial.println();
  delay(1000);
}