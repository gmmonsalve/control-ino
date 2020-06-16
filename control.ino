#include <SoftwareSerial.h>

#define AD0 A0
#define AD1 A1

int SW2 = 2;
int valor;

SoftwareSerial BTSerial(10, 11);

void setup() {
 Serial.begin(9600);
 BTSerial.begin(9600);
 pinMode(7, INPUT_PULLUP);
 pinMode(SW2, INPUT);
 digitalWrite(SW2, HIGH);
}

void loop() {
  
  valor = analogRead(AD0);
  BTSerial.print("j0");
  BTSerial.print("|");
  BTSerial.print(valor);
  BTSerial.print("|");
  valor = analogRead(AD1);
  BTSerial.print(valor);
  BTSerial.print("|");
    boolean boton = digitalRead(SW2);
    if (boton == HIGH){
      BTSerial.print("0"); 
    }else{
      BTSerial.print("1");
    }
    BTSerial.print("|");
  int sensorVal = digitalRead(7);
 
  if (sensorVal != HIGH) {
     BTSerial.println("1");
  }else{
    BTSerial.println("0");
    }
    BTSerial.print("\n");
}
