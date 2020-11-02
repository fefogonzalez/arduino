/*
 Con los codigos obtenidos en el codigo anterior, tomaremos distintas acciones en nuestro programa.
 En nuestro ejemplo usaremos los Botones 1, 2 y 3 del control remoto para encender un led Rojo, Verde o Azul respecticamente
*/


#include <IRremote.h>     // importa libreria IRremote
/*
Mapeo de los botones del control remoto con los codigos obtenidos previamente
para simplificar el ejemplo de uso, solo usaremos 3 botones.
*/
#define Boton_1 0x80BF49B6    // Se debera reemplazar con el codigo HEX correspondiente al boton
#define Boton_2 0x80BFC936    // Se debera reemplazar con el codigo HEX correspondiente al boton
#define Boton_3 0x80BF33CC    // Se debera reemplazar con el codigo HEX correspondiente al boton

int SENSOR = 12;
IRrecv irrecv(SENSOR);
decode_results codigo;

int LEDROJO = 2;
int LEDVERDE = 3;
int LEDAZUL = 4;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LEDROJO, OUTPUT);
  pinMode(LEDVERDE, OUTPUT);
  pinMode(LEDAZUL, OUTPUT);
} 

void loop() {
  if (irrecv.decode(&codigo)) {
    Serial.println(codigo.value, HEX);    // A modo de Debug se muestra el valor HEX en el monitor serial
    if (codigo.value == Boton_1)      // si se apreto el Boton_1
      digitalWrite(LEDROJO, !digitalRead(LEDROJO)); // Se enciende o apaga el led rojo, dependendiendo del estado en que se encontraba

    if (codigo.value == Boton_2)      // si se apreto el Boton_2
      digitalWrite(LEDVERDE, !digitalRead(LEDVERDE)); // Se enciende o apaga el led verde, dependendiendo del estado en que se encontraba

    if (codigo.value == Boton_3)      // si se apreto el Boton_3
      digitalWrite(LEDAZUL, !digitalRead(LEDAZUL)); // Se enciende o apaga el led azul, dependendiendo del estado en que se encontraba
    
    irrecv.resume();
  }
  delay (100);
}
