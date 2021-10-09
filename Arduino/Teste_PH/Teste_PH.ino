//----------------------------------------------------------//
//----------------------------------------------------------//
//  Codigo utilizado para testar o funcionamento do modulo  //
//  de pH modelo Ph4502c por meio do monitor serial do      //
//  Arduino IDE. Este codigo generico foi encontrado na     //
//  internet e nao foi produzido pelo grupo. Encontrado no  //
//  canal Projeto Basico, em: youtube.com/c/projetobasicos  //
//  e foi modificado a partir do codigo inicial disponivel  //
//  em: forum.arduino.cc/index.php?topic=336012.0           //
//----------------------------------------------------------//
//----------------------------------------------------------//


int ph_pin = A0; //This is the pin number connected to Po

void setup() {
  Serial.begin(9600);
  Serial.println("         Projeto basico");
  Serial.println("www.youtube.com/c/projetobasicos");
  }

void loop() {
  int measure = analogRead(ph_pin);
  Serial.print("Measure: ");
  Serial.print(measure);

  double voltage = 5 / 1024.0 * measure; //classic digital to voltage conversion
  Serial.print("\tVoltage: ");
  Serial.print(voltage, 3);

  // PH_step = (voltage@PH7 - voltage@PH4) / (PH7 - PH4)
  // PH_probe = PH7 - ((voltage@PH7 - voltage@probe) / PH_step)
  float Po = 7 + ((2.5 - voltage) / 0.18);
  Serial.print("\tPH: ");
  Serial.print(Po, 3);

  Serial.println("");
  delay(2000);
}
