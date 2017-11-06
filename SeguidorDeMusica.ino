#include "Ultrasonic.h"     //Libreria del sonar
Ultrasonic ultrasonic1(9,10); //Trigger, Echo
Ultrasonic ultrasonic2(12,11);

#include <LiquidCrystal.h> // Incluye la Libreria LiquidCrystal
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); // Crea un Objeto LC. Parametros: (rs, enable, d4, d5, d6, d7)

int sonar1;
int sonar2;
void setup()
{
   lcd.begin(16,2); // Inicializa la interface para el LCD screen, and determina sus dimensiones (ancho y alto) del display
   pinMode(8,OUTPUT);
   pinMode(13,OUTPUT);
   Serial.begin(9600);
}

void loop()
{
  
  lcd.setCursor(0,0);
  lcd.print("Proyecto 2"); 
  lcd.setCursor(0,1);
  lcd.print(" Lab Micros"); 
  sonar1 = ultrasonic1.Ranging(CM);  
  sonar2 = ultrasonic2.Ranging(CM);
  int siga;  
  int x=0;
  int estado=0 ;
  if(Serial.available()>0){
    estado = Serial.read();
   }
   if (estado =='3'){
    x=1;
    siga=1;
    }
   if(estado=='1'){
    x=2;
    }
   if(estado=='2'){
    x=3;
    siga=1;
    }
    delay(800);
    lcd.clear();
    
    while (x==1){
      while (siga){
      delay (1000);
      lcd.setCursor(0,0);
      lcd.print("Proyecto 2"); 
      lcd.setCursor(0,1);
      lcd.print("Lab Micros");
      lcd.setCursor(11,0);
      lcd.print("Party");
      lcd.setCursor(13,1);
      lcd.print("ON");
      sonar2 = ultrasonic2.Ranging(CM);
      sonar1 = ultrasonic1.Ranging(CM);
      
      if((sonar1<20)&&(sonar2<20)&& (siga==1)){
        digitalWrite(13,LOW);
        digitalWrite(8,LOW);
        sonar1 = ultrasonic1.Ranging(CM);
        sonar2 = ultrasonic2.Ranging(CM);
        if(Serial.available()>0){
          estado = Serial.read();
        }
        if (estado == '1'){
          siga=0;
          }
        if (estado == '2'){
          siga=0;
          }
        }
      else if ((sonar1 < 20)&& (siga==1)){
        digitalWrite(13,HIGH);
        digitalWrite(8,LOW);
        sonar1 = ultrasonic1.Ranging(CM);
        sonar2 = ultrasonic2.Ranging(CM);
        if(Serial.available()>0){
          estado = Serial.read();
        }
        if (estado == '1'){
          siga=0;
          }
        if (estado == '2'){
          siga=0;
          }
        }
      else if ((sonar2 < 20)&& (siga==1)){
        digitalWrite(13,LOW);
        digitalWrite(8,HIGH);
        sonar1 = ultrasonic1.Ranging(CM);
        sonar2 = ultrasonic2.Ranging(CM);
        if(Serial.available()>0){
           estado = Serial.read();
        }
        if (estado == '1'){
          siga=0;
          }
        if (estado == '2'){
          siga=0;
          }
        }
      else {
        
        digitalWrite(8,HIGH);
        digitalWrite(13,HIGH);
        if(Serial.available()>0){
           estado = Serial.read();
        }
        if (estado == '1'){
          siga=0;
          }
        if (estado == '2'){
          siga=0;
          }
        }

      }
      x=0;
  }
      
    while (x==2){
    while (siga){
      delay (1000);
      lcd.setCursor(0,0);
      lcd.print("Proyecto 2"); 
      lcd.setCursor(0,1);
      lcd.print(" Lab Micros");
      lcd.setCursor(13,0);
      lcd.print("SEG");
      lcd.setCursor(13,1);
      lcd.print("ON");
      sonar2 = ultrasonic2.Ranging(CM);
      sonar1 = ultrasonic1.Ranging(CM);
      if ((sonar1 < 20)&& (siga==1)){
        digitalWrite(13,HIGH);
        digitalWrite(8,LOW);
        sonar1 = ultrasonic1.Ranging(CM);
        sonar2 = ultrasonic2.Ranging(CM);
        if(Serial.available()>0){
          estado = Serial.read();
        }
        if (estado == '2'){
          siga=0;
        }
        if (estado == '3'){
          siga=0;
        }
        }
      else if ((sonar2 < 20)&& (siga==1)){
        digitalWrite(13,LOW);
        digitalWrite(8,HIGH);
        sonar1 = ultrasonic1.Ranging(CM);
        sonar2 = ultrasonic2.Ranging(CM);
        if(Serial.available()>0){
          estado = Serial.read();
        }
        if (estado == '2'){
          siga=0;
        }
        if (estado == '3'){
          siga=0;
        }
       }
      else {
        digitalWrite(8,HIGH);
        digitalWrite(13,HIGH);
        if(Serial.available()>0){
          estado = Serial.read();
        }
        if (estado == '2'){
          siga=0;
        }
        if (estado == '3'){
          siga=0;
        }
      }

    }
    x=0;
  }
   while (x==3){
   while (siga){
    delay (1000);
    
    lcd.setCursor(0,0);
    lcd.print("Proyecto 2"); 
    lcd.setCursor(0,1);
    lcd.print(" Lab Micros");
    lcd.setCursor(12,0);
    lcd.print("HOME");
    lcd.setCursor(13,1);
    lcd.print("ON");
    digitalWrite(13,LOW);
    digitalWrite(8,LOW);
    if(Serial.available()>0){
    estado = Serial.read();
    }
    if (estado == '1'){
      siga=0;
    }
    if (estado == '3'){
      siga=0;
    }
    
    }
    x=0;
  }
    
      
  
}
