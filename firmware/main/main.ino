/*  Nombre de archivo: main.ino
*   Proyecto: Caroto
*   Programa principal para el carrito de aldea

 */

//	************************* LIBRARIES ***********************************
#include <Arduino.h>

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
  // put your setup code here, to run once:

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
