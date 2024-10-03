#include <Servo.h>

Servo objServo;
int servo = 4;
int led = 2;

int trig = 12;
int echo = 13;

int posicao = 0;
long duracao;
int distancia;

void setup()
{
  objServo.attach(servo);
  pinMode(led,OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  Serial.begin(9600);  
  
}
void loop()
{
  
  objServo.write(posicao);
  
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Ler o tempo de resposta 
  duracao = pulseIn(echo, HIGH);
  distancia = duracao * 0.034 / 2;
  digitalWrite(led,LOW);
  if(posicao != 90){
      if (distancia <= 20) {
          digitalWrite(led,HIGH);
          delay(1000);   
          posicao = 90;  
          objServo.write(posicao); 
          delay(2000);              
      }
  }else if (distancia <= 20) {
      digitalWrite(led,HIGH);
      delay(1000);   
      posicao = 0;  
      objServo.write(posicao); 
      delay(2000);
  }
  
}
