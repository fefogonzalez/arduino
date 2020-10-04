void setup()
{
  pinMode(A0, INPUT); // Sensor de luz
  pinMode(11, OUTPUT); //Led Verde, se enciende si hay mucha luz
  pinMode(12, OUTPUT); //Led Rojo, se enciende si hay poca luz
}

void loop()
{
  if (analogRead(A0) >= 300) { // Si hay mucha luz, encender luz verde
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    delay(5000); // Wait for 5000 millisecond(s)
  } else { // Si hay poca luz, encender luz roja
    digitalWrite(11, LOW);    
    digitalWrite(12, HIGH);
    delay(5000); // Wait for 5000 millisecond(s)
  }
}
