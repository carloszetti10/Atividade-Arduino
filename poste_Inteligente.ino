// C++ code
//
int led = 3;
int sensor = A0;
int luz = 0;
void setup()
{
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
}

void loop()
{
  luz = analogRead(sensor);
  
  if(luz<500){
    digitalWrite(led,HIGH); //ligar
    analogWrite(led, 1023); 
    
    if(luz>500 & luz<900){
      analogWrite (led, 500);
      
    }else{
      analogWrite(led,0);
    }
  }else{
    digitalWrite(led,LOW); //desligar
  }
}