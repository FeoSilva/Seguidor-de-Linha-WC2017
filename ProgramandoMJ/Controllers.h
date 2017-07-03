#include <Arduino.h>
#include <QTRSensors.h>

/*
  FUNÇÕES de Controles DO ROBÔ
*/
void Seguidor(boolean condicao) {

  while (condicao == true) {

   
    // SEGUIDOR DE LINHA P.I.D.
    PID(KP, KI, KD, forcaPID, setPoint);

    //lerTodosSensores();

  }

};
