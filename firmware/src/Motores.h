// Motores.h

//El motor A es el derecho y el motor B es el Izquierdo

#ifndef _MOTORES_h
#define _MOTORES_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#include "pins.h"	//Cabecera para incluir la distribución d elos pines

#define MUCHO	100
#define POCO	80

class Motores
{
public:
	// ****** CONSTRUCTOR
	
	/** Constructor with the pins for the motors
	* \param pwmA Valor de calibracion para el motor A
	* \param motA1 pin 1 del motor A
	* \param motA2 pin 2 del motor A
	* \param pwmB Valor de calibracion para el motor B
	* \param motB1 pin 1 del motor A
	* \param motB2 pin 2 del motor A
	*/
	Motores(int pwmA, int motA1, int motA2, int pwmB, int motB1, int motB2);

	/** Default destructor */
	~Motores();

	/** Inicializa los motores */
	void begin();

	// ****** ACCESSORS & MUTATORS
	/** Configurar el pwm del motor A
	* \param pwmA Valor de calibracion para el motor A
	*/
	void configurarA(int pwm);

	/** Regresa el valor del pwm del motor A
	* \return pwmA Valor de calibracion para el motor A
	*/
	int retroA();

	/** Configurar el pwm del motor B
	* \param pwmB Valor de calibracion para el motor B
	*/
	void configurarB(int pwm);

	/** Regresa el valor del pwm del motor B
	* \return pwmB Valor de calibracion para el motor B
	*/
	int retroB();

	/** Configurar el pwm tanto del motor A como del motor B
	* \param pwmA Valor de calibracion para el motor A
	* \param pwmB Valor de calibracion para el motor B
	*/
	void configurar(int pwmA, int pwmB);

	// ****** FUNCTIONS
	/** Eleva la base a la potencia
	* \return el valor de la base ya elevado a la potencia
	*/
	void avanza();

	/** Eleva la base a la potencia
	* \return el valor de la base ya elevado a la potencia
	*/
	void retrocede();

	/** Eleva la base a la potencia
	* \return el valor de la base ya elevado a la potencia
	*/
	void detiene();

	/** Eleva la base a la potencia
	* \return el valor de la base ya elevado a la potencia
	*/
	void girarIzq();

	/** Eleva la base a la potencia
	* \return el valor de la base ya elevado a la potencia
	*/
	void girarDer();

private:
	// ***** DATA MEMBERS
	int pinPWM_A;	//!< PWM del motor A
	int pinAIN1;	//!< pin 1 del motor A
	int pinAIN2;	//!< pin 2 del motor A
	int pinPWM_B;	//!< PWM del motor B
	int pinBIN1;	//!< pin 1 del motor B
	int pinBIN2;	//!< pin 2 del motor B
	int pwm_motorA;	//!< PWM de calibración para el motor A
	int pwm_motorB;	//!< PWM de calibración para el motor B

}; //End of class motores



#endif

