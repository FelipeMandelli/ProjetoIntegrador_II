# Microcontrolador Arduino - Projeto Integrador II

Diretorio destinado a documentacao do desenvolvimento do codigo do Microcontrolador do Projeto da boia-estacao de monitoramento da qualidade da agua.

A parte fisica do projeto consiste de uma placa Arduino Uno, como microcontrolador. Alem de:
- Modulo GPS neo6mv2; 
- Modulo Wi-Fi ESP 8266 01;
- Sensor de Turbidez;
- Sensor de pH 
- Sensor de Temperatura a prova dagua;

* Foram conduzidos inicialmente testes individuais nas pecas, para atestar funcionamento e a fim de estudar a implementacao e uso destas. 


* Aliado tambem ao Microcontrolador, o projeto da boia foi desenvolvido inicialmente pelo Grupo, com auxilio do Software de modelagem SolidWorks, esta modelagem inicial se encontra na pasta Boia, arquivo Esboco Inicial. O intuito deste esboco era criar uma imagem do projeto, bem como um norte para definir a modelagem final da boia juntamente com os tecnicos do Senac para impressao 3D.
  - Ao longo do desenvolvimento e de conversas com os tecnico, foi decidido utilizar uma boia do tipo espaguete para a boia e a base dos componentes foi desenvolvida a partir do desenho que esta no arquivo "Esboco Base Componentes" dentro da pasta Boia e feito em impressora 3D.


* Em conjunto, durante um encontro do grupo, foi testado o funcionamento individual de todos os Sensores com todos eles conectados ao mesmo tempo no arduino, os codigos utilizados foram os mesmos dos testes individuais previos. Na pasta Testes_Codigo serao adicionadas imagens para a vizualizacao da montagem feita nestes testes.
  - No arquivo "Montagem Fisica do Teste - Anotacao" se encontra uma listagem das conexoes realizadas nestes testes em pdf
  - No arquivo "Montagem Fisica do Teste - Esquematico" se encontra um esquema em pdf das conexoes realizadas nos testes, feito no simulador Tinkercad

* Em seguida, foi iniciado o processo de unificar todos os codigos de sensores, para que todos os valores sejam obtidos pelo mesmo codigo e mostrados no monitor serial.
  - Na pasta Testes_Codigo, o arquivo "Teste_Codigo.ino" contem o desenvolvimento deste codigo unificado de todos os sensores, seguindo a mesma montagem do processo anterior
