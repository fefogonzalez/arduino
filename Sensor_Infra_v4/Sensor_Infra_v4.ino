#include <LiquidCrystal_I2C.h>
#include <Servo.h>

//This code is to use with FC51 IR proximity sensor, when it detects an obstacle it lights the internal LED
//of the Arduino Board, refer to Surtrtech for more information
//#include <LiquidCrystal_I2C.h>

const int SensorProximidad = 8; //Declaring where the Out pin from the sensor is wired
const int Led = 2;
const int Buzzer = 3;
const int PinBarrera = 10;
LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2)
Servo Barrera;

void setup() {                
  pinMode(Led, OUTPUT);   // setting the pin modes, the "13" stands for the internal Arduino uno internal LED
  pinMode(Buzzer, OUTPUT);
  pinMode(SensorProximidad,INPUT); // then we have the out pin from the module

  Barrera.attach(PinBarrera);

  lcd.init();
  lcd.backlight();
  //lcd.clear();
  //delay(300);
}

void loop() {

  //lcd.display();
  //delay(500);
  
  if(digitalRead(SensorProximidad)==HIGH)      // Se verifica si hay algo cerca al sensor de Proximidad
  {
    digitalWrite(Led, LOW);
    digitalWrite(Buzzer, LOW); // Si no hay nada cerca, el led y el buzzer se mantienen apagados
    lcd.clear();

        Barrera.write(0);
  }
  else
  {
    digitalWrite(Led, HIGH);    // Si hay algo cerca, el led y el buzzer alertan
    digitalWrite(Buzzer, HIGH);




    //lcd.setCursor(4,0);
    //lcd.print("Intruso");
    //lcd.setCursor(3,1);
    //lcd.print("detectado");



    lcd.setCursor(4,0);
    lcd.print("Cuidado");
    lcd.setCursor(1,1);
    lcd.print("viene el tren");

     delay(2000);    


    Barrera.write(90);

  }
  delay(800);             
}
