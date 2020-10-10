// Este proyecto se realizo con un sensor de proximidad FC51 IR

const int SensorProximidad = 8; // Se conecta el sensor de proximidad al pin 8
const int Led = 2; // Se conecta el led en al pin 2
const int Buzzer = 3; // Se conecta el Buzzer al pin 3

void setup() {                
  pinMode(Led, OUTPUT);
  pinMode(Buzzer, OUTPUT);
  pinMode(SensorProximidad,INPUT);
}

void loop() {
  
  if(digitalRead(SensorProximidad)==HIGH)      // Se verifica si hay algo cerca al sensor de Proximidad
  {
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW); // Si no se detecta movimiento, el led y el buzzer se mantienen apagados
  }
  else
  {
    digitalWrite(Led, HIGH);    // Si se detecta movimiento, el led y el buzzer alertan
    digitalWrite(Buzzer, HIGH);
  }
  delay(100);             
}
