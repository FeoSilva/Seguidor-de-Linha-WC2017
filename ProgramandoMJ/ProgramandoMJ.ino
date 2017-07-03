/*
 * Programacao para o torneio Winter Challenge 2017
 * Desenvolvido por Felipe Silva, Felipe Tiozo, Yasmin Ribeiro, Kherollyn Alencar
 * Equipe Tamandutech (RAS UFABC)[Think Team]
 * Apoio: 
 * http://facebook.com/IEEERASUFABC
 * https://www.facebook.com/ThinkTeamBR/
 * https://www.facebook.com/tamandutech/
 */

#include <QTRSensors.h>

#include "Wire.h"
#include <Thread.h>
#include "AnalogIn.h"
#include "DigitalIn.h"
#include "DigitalOut.h"
#include <ArduinoSensors.h>
#include <sensors/AnalogVoltage.h>

/// Basic robot definitions
#include "Config.h"

#include "Readings.h" // lê
#include "Verifications.h" // verifica
#include "Actions.h" // age
#include "Controllers.h" // controla


void setup() {
  
 Serial.begin(115200);

  // SETUP DE TUDO
  ligarMotores(); // ligar motores
  
  AlertaDeInicio();
  delay(500); 
    
  Serial.println("Calibration Run");
  Serial.println("Calibration Running...");
  
  for (int i = 0; i < 100; i++)  // make the calibration take about 10 seconds
  {
    LED3.turnOn();
    qtra.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
    LED3.turnOff();
    delay(10);
  }
  
  LED3.turnOff();
  Serial.println("Calibration Done!");

  
  // Mostrar 'Inicializando...'
  Serial.println("Inicializando...");
  delay(800);
 
  
}


void loop() {
       
  //qtra.read(sensorValues);
  
  //lerTodosSensores();
  //Serial.println(lerSharp(1));
  //Serial.println(lerQTRVerde(3));
  //PID(KP, KI, KD, 35, 3500);
  //mover(70, 70);


  if(Botao1.readValue() == HIGH) {
      LED2.turnOn();
      delay(1000);
      Seguidor(true);
      LED2.turnOff();
  }
  

}
