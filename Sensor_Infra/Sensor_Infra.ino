// Este proyecto se realizo con un sensor de proximidad FC51 IR

const int SensorProximidad = 8; // Se conecta el sensor de proximidad al pin 8
const int Led = 2; // Se conecta el led en al pin 2

void setup() {                
  pinMode(Led, OUTPUT);
  pinMode(SensorProximidad, INPUT);
}

void loop() {
  
  if(digitalRead(SensorProximidad)==HIGH)      // Se verifica si hay algo cerca al sensor de Proximidad
  {
    digitalWrite(Led, LOW);  // Si no se detecta movimiento, el led permanecera apagado
  }
  else
  {
    digitalWrite(Led, HIGH);    // Si se detecta movimiento, se enciende un led a modo de alerta
  }
  delay(100);             
}
