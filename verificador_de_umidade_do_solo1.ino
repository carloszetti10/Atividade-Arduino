//Biblioteca para o sensor
#include <SoftwareSerial.h>

int sensor = A0;



void setup()
{
  //definir sensor como entrada
  pinMode(sensor, INPUT);
  // utilizar o sensor como serial
  Serial.begin(9600);
  
}

void loop()
{
  //guardar o valor lido pelo sensor
 int umidade = analogRead(sensor);
  //imprimindo o valor
   Serial.println("Umidade do solo:");
   Serial.println(umidade);
   //delay(1000);
  
  if(umidade <= 300){
    //solo seco
    Serial.println("solo seco!");
  } else{
    if(umidade <= 500){
      //solo ideal
       Serial.println("solo ideal!");
    }else{
      //solo umido
       Serial.println("solo umido!");
    }
  }
  delay(1000);
}