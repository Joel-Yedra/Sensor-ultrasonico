float tiempo;
float distancia;

void setup()
{
  pinMode(4,OUTPUT); // Trigger
  pinMode(A5,INPUT); // Echo
  pinMode(7,OUTPUT); // LED
  pinMode(8,OUTPUT); // Zumbador
  Serial.begin(9600);
  
}

void loop()
{
  digitalWrite(4,LOW);
  delayMicroseconds(20);
  digitalWrite(4,HIGH);
  delayMicroseconds(10);
  digitalWrite(4,LOW);
  
  
  tiempo = pulseIn(A5,HIGH);
  
  distancia = 0.01716 * tiempo;
  
  if(distancia<100)
  {
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    delay(distancia*10);
                 
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    delay(distancia*10);
      
  }
  
   Serial.println(distancia);
   delay(100);
  

}