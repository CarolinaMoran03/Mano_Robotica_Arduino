
//Libreria de driver PCA 9685
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver servos = Adafruit_PWMServoDriver();

int pos0=102;
int pos180=512;
int Mano;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  servos.begin();
  servos.setPWMFreq(50);

}

void loop() {
  
  if (Serial.available() > 0){

    Mano= Serial.read();

    if(Mano == 'E'){ //Mano ABIERTA
  setServo(0,0);  //PULGAR
  setServo(1,0);  //MENIQUE
  setServo(2,0); //EL QUE SIGUE
  setServo(3,0); //MEDIO
  setServo(4,0); //INDICE
  setServo(5,180); //PULGAR RETORNO
  setServo(6,30); //MENIQUE RETORNO
  setServo(7,180); //QLE Q SIGUE RETORNO}
  setServo(8,180); //MEDIO RETORNO
  setServo(9,180); //INDICE
    }

    if(Mano == 'N'){ //Mano CERRADA
  setServo(0,180); //PULGAR
  setServo(1,180); //MENIQUE
  setServo(2,180); //ANULAR
  setServo(3,180); //MEDIO
  setServo(4,180); //indice
  setServo(5,0);    //pulgar retorno
  setServo(6,180);  //MENIQUE RETORNO
  setServo(7,0);    //ANULAR ETORNO
  setServo(8,0);    //MEDIO RETORNO
  setServo(9,0);    //indice retorno
  
    }

    if(Mano == 'O'){ //pulgar
  setServo(0,0); //PULGAR
  setServo(1,180); //MENIQUE
  setServo(2,180); //ANULAR
  setServo(3,180); //MEDIO
  setServo(4,180); //indice
  setServo(5,180);    //pulgar retorno
  setServo(6,180);  //MENIQUE RETORNO
  setServo(7,0);    //ANULAR ETORNO
  setServo(8,0);    //MEDIO RETORNO
  setServo(9,0);    //indice retorno
  
    }
    
    if(Mano == 'T'){ //menique
  setServo(0,180); //PULGAR
  setServo(1,0); //MENIQUE
  setServo(2,180); //ANULAR
  setServo(3,180); //MEDIO
  setServo(4,180); //indice
  setServo(5,0);    //pulgar retorno
  setServo(6,30);  //MENIQUE RETORNO
  setServo(7,0);    //ANULAR ETORNO
  setServo(8,0);    //MEDIO RETORNO
  setServo(9,0);    //indice retorno
  
    }

    if(Mano == 'H'){ //ANULAR ARRIBA
  setServo(0,180); //PULGAR
  setServo(1,180); //MENIQUE
  setServo(2,0); //ANULAR
  setServo(3,180); //MEDIO
  setServo(4,180); //indice
  setServo(5,0);    //pulgar retorno
  setServo(6,180);  //MENIQUE RETORNO
  setServo(7,180);    //ANULAR ETORNO
  setServo(8,0);    //MEDIO RETORNO
  setServo(9,0);    //indice retorno
  
    }


    if(Mano == '6'){ //MEDIO
  setServo(0,180); //PULGAR
  setServo(1,180); //MENIQUE
  setServo(2,180); //ANULAR
  setServo(3,0); //MEDIO
  setServo(4,180); //indice
  setServo(5,0);    //pulgar retorno
  setServo(6,180);  //MENIQUE RETORNO
  setServo(7,0);    //ANULAR ETORNO
  setServo(8,180);    //MEDIO RETORNO
  setServo(9,0);    //indice retorno
  
    }
    if(Mano == '7'){ //INDICE
  setServo(0,180); //PULGAR
  setServo(1,180); //MENIQUE
  setServo(2,180); //ANULAR
  setServo(3,180); //MEDIO
  setServo(4,0); //indice
  setServo(5,0);    //pulgar retorno
  setServo(6,180);  //MENIQUE RETORNO
  setServo(7,0);    //ANULAR ETORNO
  setServo(8,0);    //MEDIO RETORNO
  setServo(9,180);    //indice retorno
  
    }
  }

}


void setServo(uint8_t n_servo, int angulo) {
  int duty;
  duty=map(angulo,0,180,pos0, pos180);
  servos.setPWM(n_servo, 0, duty);
}