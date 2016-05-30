/*  Nombre de archivo: main.ino
*   Proyecto: Carbeto
*   Programa principal para el carrito de aldea
*/

//	************************* LIBRARIES ***********************************
#include <Arduino.h>

#include "src/carbeto.h"

//	************************* VARIABLES ***********************************
enum Estados {
  ESPERA,
  GUARDAR,
  DECIDIR,
  ADELANTE,
  IZQUIERDA,
  DERECHA,
  ERROR,
  LEVANTADO
};

Estados estadoCarbeto; //!< Estado actual en el que se encuentra el robot

//	************************* SETUP ***************************************

void setup() {
  //Entradas
  pinMode(PISO, INPUT);
  pinMode(CHOQUE, OUTPUT);

  //Salidas
  pinMode(RGB, OUTPUT);
  pinMode(BUZZ, OUTPUT);

  pinMode(PWM_A, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  pinMode(PWM_B, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  //COMUNICACIÓN SERIAL
  Serial.begin(9600);


}

//	************************* PROGRAM ***************************************

void loop() {
  switch (estadoCarbeto) {
    case ESPERA:
      break;

    case GUARDAR:
      break;

    case DECIDIR:
      break;

    case ADELANTE:
      break;

    case IZQUIERDA:
      break;

    case DERECHA:
      break;

    case ERROR:
      break;

    case LEVANTADO:
      break;

    default:
      //Nunca debe de llegar aquí
      //Lanzar un mensaje de error de HW y ver si SW
      break;

  } //End switch Maq estados

} //End Loop
