int LED = 3; // Led conectado a la salida 3
int BRILLO;
int POT = 0; // Potenciometro conectado a A0

void setup() {
  // put your setup code here, to run once:
  pinMode (LED, OUTPUT);
  // La entrada (A0) por ser analogica no se inicializa
}

void loop() {
  // put your main code here, to run repeatedly:
  /* analogWrite espera valores entre 0 y 255 en cambio
   * las entradas analogicas manejan valores entre 0 y 1023
   * por tal motivo, en la siguiente linea dividimos el valor
   * obtenido con analogRead por 4
   */
  BRILLO = analogRead(POT) / 4;
  analogWrite(LED, BRILLO);
}
