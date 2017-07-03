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
  
 Serial.begin(9600);

  // SETUP DE TUDO
  ligarMotores(); // ligar motores
  
  AlertaDeInicio();
  delay(500); 
    
  Serial.println("Calibration Run");
  Serial.println("Calibration Running...");
  
  for (int i = 0; i < 100; i++)  // make the calibration take about 10 seconds
  {
    LED1.turnOn();
    qtra.calibrate();       // reads all sensors 10 times at 2500 us per read (i.e. ~25 ms per call)
    LED1.turnOff();
    delay(10);
  }
  
  LED3.turnOff();
  Serial.println("Calibration Done!");

  
  // Mostrar 'Inicializando...'
  Serial.println("Inicializando...");
  delay(800);
 
  
}

int tchela=0;
void loop() {
       
    //qtra.read(sensorValues);

  //Serial.println(lerTodosQTR());  
  //lerTodosSensores();
  //Serial.println(lerQTR(8));
  //Serial.println(lerQTRVerde(3));
  /*lerTodosSensores();
  if(lerQTR(8) < 800) {
    tchela++;
      if(tchela > 10) {
        while(1) {
          lerTodosSensores();
       Buzzer.turnOn();
        pararMotores();
      }
    }
  } 
  
  else {*/
    qtra.read(sensorValues);
    if(lerTodosQTR() > 1800 && lerTodosQTR() < 3000) {
      mover(255, 255);
    } else {
      PID(KP, KI, KD, 255, 2500);
    }
  //}
  //mover(70, 70);


//  if(Botao1.readValue() == HIGH) {
      //LED2.turnOn();
      //delay(1000);
      //Seguidor(true);
      //LED2.turnOff();
  //}
  

}