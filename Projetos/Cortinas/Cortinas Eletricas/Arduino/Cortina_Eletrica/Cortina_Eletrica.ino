

#include <EEPROM.h>    

#define potenciometro A0

#define motor2_dir A2
#define motor2_sw A3
 
#define motor1_sw  A4
#define motor1_dir  A5

#define comando_abrir  A6
#define comando_fechar  A7


unsigned int tempo = 0;

bool posicaocortina1  = EEPROM.read(1);
bool posicaocortina2  = EEPROM.read(2);

 void setup() {
  
    pinMode(comando_abrir, INPUT);
    pinMode(comando_fechar, INPUT);
    pinMode(potenciometro, INPUT);
    pinMode(motor2_dir, OUTPUT);
    pinMode(motor2_sw, OUTPUT);
    pinMode(motor1_sw, OUTPUT);
    pinMode(motor1_dir, OUTPUT);

}



void loop(){
 
 tempo = analogRead(potenciometro) * 60;

 if(digitalRead(comando_abrir) == HIGH && posicaocortina1 == LOW && posicaocortina2 == LOW )  { 

 
    digitalWrite(motor1_dir, HIGH); // HIGH abre,   LOW fecha 
    digitalWrite(motor1_sw, HIGH);
    delay(tempo);
    digitalWrite(motor1_sw, LOW);
    digitalWrite(motor1_dir, LOW);  // HIGH abre,   LOW fecha 
    posicaocortina1 = HIGH;
    EEPROM.write(1, posicaocortina1);
    
    delay(1000);
    
    digitalWrite(motor2_dir, HIGH);  // HIGH abre,   LOW fecha 
    digitalWrite(motor2_sw, HIGH);
    delay(tempo);
    digitalWrite(motor2_sw, LOW);
    digitalWrite(motor2_dir, LOW); // HIGH abre,   LOW fecha 
    posicaocortina2 = HIGH;
    EEPROM.write(2, posicaocortina2);
    
    }

  
 if(digitalRead(comando_abrir) == LOW)  { 

    
    }


 if(digitalRead(comando_fechar) == HIGH && posicaocortina1 == HIGH && posicaocortina2 == HIGH  )  { 


    digitalWrite(motor2_dir, LOW); // HIGH abre,   LOW fecha 
    digitalWrite(motor2_sw, HIGH);
    delay(tempo);
    digitalWrite(motor2_sw, LOW);   
    digitalWrite(motor2_dir, LOW); // HIGH abre,   LOW fecha 
    posicaocortina1 = LOW;
    EEPROM.write(1, posicaocortina1);
    
    delay(1000);
    
    digitalWrite(motor1_dir, LOW); // HIGH abre,   LOW fecha 
    digitalWrite(motor1_sw, HIGH);
    delay(tempo);
    digitalWrite(motor1_sw, LOW);
    digitalWrite(motor1_dir, LOW); // HIGH abre,   LOW fecha 
    posicaocortina2 = LOW;
    EEPROM.write(2, posicaocortina2);
   }
 
   
 if(digitalRead(comando_fechar) == LOW)  { 

    
    }
 
}