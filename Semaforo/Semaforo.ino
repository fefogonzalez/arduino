void setup()
{
  pinMode(2, OUTPUT); // Led Rojo conectado al pin 2
  pinMode(3, OUTPUT); // Led Amarillo conectado al pin 3
  pinMode(4, OUTPUT); // Led Verde conectado al pin 4
}

void loop()
{
  digitalWrite(2, HIGH); // Se enciende led Rojo
  delay(3000); // Durante 3000 milisegundos el led queda encendido
  digitalWrite(2, LOW); // Se apaga led Rojo
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(3, HIGH); // Se enciende led Amarillo
  delay(3000); // Durante 3000 milisegundos el led queda encendido
  digitalWrite(3, LOW); // Se apaga led Amarillo
  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(4, HIGH); // Se enciende led Verde
  delay(3000); // Durante 3000 milisegundos el led queda encendido
  digitalWrite(4, LOW); // Se apaga led Verde
  delay(5000); // Esperar 5000 milisegundos para que se vuelva a encender el led Rojo
}
