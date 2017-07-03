#include <Arduino.h>

/*
  ROBOT GENERAL CONFIGURATION
*/

/************************ MOTORES ************************/
// Motores: Pololu 298:1 Micro Motor HPCB 12V 0.8A 100 RPM
// Utilizamos 4 motores porém eles estão em paralelo

// Motor ESQUERDO DIANETEIRO
#define MotorEsquerdoFrente 4
#define MotorEsquerdoTras 3

// Motor DIREITO DIANTEIRO
#define MotorDireitoFrente 5
#define MotorDireitoTras 6


void ligarMotores() {
  // MOTOR ESQUERDO DIANTEIRO
  pinMode(MotorEsquerdoFrente, OUTPUT);
  pinMode(MotorEsquerdoTras, OUTPUT);

  
  // MOTOR DIREITO DIANTEIRO
  pinMode(MotorDireitoFrente, OUTPUT);
  pinMode(MotorDireitoTras, OUTPUT);

}

/************************ SENSORES ************************/
// Sensores: Pololu QTR-8A reflectance sensor, Sharp 4-30cm, Divisor de Tensão, GY521 IMU
// PORTAS ANÁLOGICAS

// SENSORES ARRAY QTR-8-A
#define luminosidade1     A0 // SENSOR LINHA 1
#define luminosidade2     A1 // SENSOR LINHA 2
#define luminosidade3     A2 // SENSOR LINHA 3
#define luminosidade4     A3 // SENSOR LINHA 4
#define luminosidade5     A4 // SENSOR LINHA 5
#define luminosidade6     A5 // SENSOR LINHA 6

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
//#define EMITTER_PIN             2  // emitter is controlled by digital pin 2

// Sensores de 0 a 8 que estão conectados nas portas analógicas
QTRSensorsAnalog qtra((unsigned char[]) {luminosidade1, luminosidade2, luminosidade3, luminosidade4, luminosidade5, luminosidade6}, 
  NUM_SENSORS, NUM_SAMPLES_PER_SENSOR);
unsigned int sensorValues[NUM_SENSORS];


 
/************************ INTERFACE ************************/
// Botões para iniciar ações 
// PORTAS DIGITAIS
#define btn1 38 // LED Robô ligado
#define btn2 36 // LED Tensão bateria
#define btn3 34 // LED Teste do robô
#define btn4 32 // LED Calibração

int Botoes[] {
  0,
  btn1,
  btn2,
  btn3,
  btn4
};
DigitalIn Botao1(btn1);
DigitalIn Botao2(btn2);
DigitalIn Botao3(btn3);
DigitalIn Botao4(btn4);


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
unsigned long tempoinicial = millis();
int lastError = 0;
int erro;
int P; int I; int D;
int ganho;

double motorB; double motorC;

//float KP = 0.015;
float KP = 0.018; // Constante do Proporcional
//float KI = 0.03;
float KI = 0.035;
//float KD = 0.4; // Constante da Derivada
float KD = 0; // Constante da Derivada

int branco = 100; // Força normal para seguir linha
int preto = 700; // Força para rampa

int forcaPID = 65;

int offset = ((branco + preto) / 2); // media seguidor

int setPoint = 3500;


