#include <Arduino.h>

/*
  ROBOT GENERAL CONFIGURATION
*/

/************************ MOTORES ************************/
// Motores: Pololu 30:1 Micro Motor MP 6V

// Motor ESQUERDO DIANETEIRO
#define MotorEsquerdoFrente 6
#define MotorEsquerdoTras 5

// Motor DIREITO DIANTEIRO
#define MotorDireitoFrente 10
#define MotorDireitoTras 11


void ligarMotores() {
  // MOTOR ESQUERDO DIANTEIRO
  pinMode(MotorEsquerdoFrente, OUTPUT);
  pinMode(MotorEsquerdoTras, OUTPUT);

  
  // MOTOR DIREITO DIANTEIRO
  pinMode(MotorDireitoFrente, OUTPUT);
  pinMode(MotorDireitoTras, OUTPUT);

}

/************************ SENSORES ************************/
// Sensores: Pololu QTR-8A reflectance sensor
// PORTAS ANÁLOGICAS

// SENSORES ARRAY QTR-8-A
#define luminosidade1     A5 // SENSOR LINHA 1
#define luminosidade2     A4 // SENSOR LINHA 2
#define luminosidade3     A3// SENSOR LINHA 3
#define luminosidade4     A2 // SENSOR LINHA 4
#define luminosidade5     A1 // SENSOR LINHA 5
#define luminosidade6     A0 // SENSOR LINHA 6

#define luminosidade7    A6 // SENSOR ESQUERDA
#define luminosidade8     A7 // SENSOR DIREITA

int QTR[] = {
  0,
  luminosidade1,
  luminosidade2,
  luminosidade3,
  luminosidade4,
  luminosidade5,
  luminosidade6,
  luminosidade7,
  luminosidade8
    
};

// SETTINGS PARA LER O ARRAY COM A FUNÇÃO .readLine()
#define NUM_SENSORS             6  // number of sensors used
#define NUM_SAMPLES_PER_SENSOR  4  // average 4 analog samples per sensor reading

// Sensores de 0 a 8 que estão conectados nas portas analógicas
QTRSensorsAnalog qtra((unsigned char[]) {luminosidade1, luminosidade2, luminosidade3, luminosidade4, luminosidade5, luminosidade6}, 
  NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);
unsigned int sensorValues[NUM_SENSORS];

 
/************************ INTERFACE ************************/

// LEDs para identificação de ações 
#define led1  7 // LED
#define led2  8 // LED
#define led3  9 // LED

int LEDs[] {
  0,
  led1,
  led2,
  led3
};

DigitalOut LED1(led1);
DigitalOut LED2(led2);
DigitalOut LED3(led3);


// Buzzer para fazer barulinho
#define buzzer 12
DigitalOut Buzzer(buzzer);


/************************ ESTADOS *********************/
#define ESQUERDA -1
#define DIREITA   1

#define CIMA 1
#define BAIXO 0
#define IDDLE   0

/************************ VARIÁVEIS DO ROBÔ ************************/
unsigned long tempoinicial = 0;
unsigned long int tempopercorrido = 0;
int tempofinal = 16000;

int erro; int P; int I; int D;
int ganho;
double motorB; 
double motorC;

int lastError = 0;

float KP = 0.03;
float KI = 0;
float KD = 0.89;

int forcaPID = 68;

int forcaReta = 78;

int setPoint = 2500;


