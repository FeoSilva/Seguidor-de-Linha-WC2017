#include <Arduino.h>
#include <Wire.h>


/*
  FUNÇÕES de leitura DO ROBÔ
*/

int lerTodosQTR() {
  unsigned int position = qtra.readLine(sensorValues);
  return position;
}

unsigned int lerQTR(int pino) {
  
  //qtra.read(sensorValues);
  return analogRead(QTR[pino]);
  //return sensorValues[pino-1];
  
}

String allsensors;

void lerTodosSensores() {
  allsensors = "";
  allsensors += lerQTR(1);
  allsensors += " ";
  allsensors += lerQTR(2);
  allsensors += " ";
  allsensors += lerQTR(3);
  allsensors += " ";
  allsensors += lerQTR(4);
  allsensors += " ";
  allsensors += lerQTR(5);
  allsensors += " ";
  allsensors += lerQTR(6);
  allsensors += lerTodosQTR();
  allsensors += "    -------------  ";
  allsensors += analogRead(A0);
  allsensors += " ";
  allsensors += analogRead(A1);
  allsensors += " ";
  allsensors += analogRead(A2);
  allsensors += " ";
  allsensors += analogRead(A3);
  allsensors += " ";
  allsensors += analogRead(A4);
  allsensors += " ";
  allsensors += analogRead(A5);

  Serial.println(allsensors);   
  Serial.println();
  //delay(250);
}

