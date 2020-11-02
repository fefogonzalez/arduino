/*
  Mediante el monitor serial, obtendremos los codigos correspondientes a cada boton de un Control Remoto
  Utilizaremos un modulo receptor KY-022, el cual requiere de la instalacion de la libreria IRremote.
*/

#include <IRremote.h>   // importa libreria IRremote

int SENSOR = 12;    // Pin digital donde se conecto el sensor KY-022
IRrecv irrecv(SENSOR);
decode_results codigo;

void setup() { 
  Serial.begin(9600);     // Se inicia la comunicacion serie a 9600 bps
  irrecv.enableIRIn();    // Se inicia la recepcion de datos
} 

void loop() { 
  if (irrecv.decode(&codigo)) {   
    Serial.println(codigo.value, HEX);  // Muestra el valor en hexadecimal en el monitor serial
    irrecv.resume();
  }
  delay (100);
}

/*
 * En mi caso los codigos obtenidos son
 * en caso de obtener el codigo FFFFFF, es que se presiono una de las teclas de forma repetida.
 * 
 * ARRIBA    FF18E7
 * ABAJO     FF4AB5
 * IZQUIERDA  FF10EF
 * DERECHA    FF5AA5
 * OK         FF38C7
 * 1    FFA25D
 * 2    FF629D
 * 3    FFE21D
 * 4    FF22DD
 * 5    FF02FD
 * 6    FFC23D
 * 7    FFE01F
 * 8    FFA857
 * 9    FF906F
 * 0    FF9867
 * *    FF6897
 * #    FFB04F
 * 
 * En el siguiente ejemplo, usaremos estos codigos para tomar alguna accion en nuestro programa
 */
