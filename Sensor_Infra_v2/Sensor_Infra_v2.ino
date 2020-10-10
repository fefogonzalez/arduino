//This code is to use with FC51 IR proximity sensor, when it detects an obstacle it lights the internal LED
//of the Arduino Board, refer to Surtrtech for more information

const int SensorProximidad = 8; //Declaring where the Out pin from the sensor is wired
const int Led = 2;
const int Buzzer = 3;

void setup() {                
  pinMode(Led, OUTPUT);   // setting the pin modes, the "13" stands for the internal Arduino uno internal LED
  pinMode(Buzzer, OUTPUT);
  pinMode(SensorProximidad,INPUT); // then we have the out pin from the module
}

void loop() {
  
  if(digitalRead(SensorProximidad)==HIGH)      // Se verifica si hay algo cerca al sensor de Proximidad
  {
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW); // Si no hay nada cerca, el led y el buzzer se mantienen apagados
  }
  else
  {
    digitalWrite(Led, HIGH);    // Si hay algo cerca, el led y el buzzer alertan
    digitalWrite(Buzzer, HIGH);
  }
  delay(100);             
}
