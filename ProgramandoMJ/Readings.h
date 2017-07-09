#include <Arduino.h>
#include <Wire.h>


/*
  FUNÇÕES de leitura DO ROBÔ
*/

int lerTodosQTR() {
  unsigned int position = qtra.readLine(sensorValues, QTR_EMITTERS_ON, 1);
  return position;
}

unsigned int lerQTR(int pino) {
  return analogRead(QTR[pino]);  
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
  allsensors += "   ---- ";
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
} 

