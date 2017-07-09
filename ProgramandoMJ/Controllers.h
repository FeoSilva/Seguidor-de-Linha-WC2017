#include <Arduino.h>
#include <QTRSensors.h>

/*
  FUNÇÕES de Controles DO ROBÔ
*/
void Seguidor(boolean condicao) {

  // Enquanto a variavel de controle 
  while (condicao == true) {

    // variavel que determina o tempo decorrido de segue linha
    tempopercorrido = millis() - tempoinicial;

    // Enquanto o tempo percorrido for maior que o tempo final, o robo para
    while(tempopercorrido > tempofinal) {
      Buzzer.turnOn();
      Serial.println(tempopercorrido);
      pararMotores();
    }

    // Se a leitura do QTR estiver no meio, ele anda reto, se nao faz o P.I.D.
    if(lerTodosQTR() > 1800 && lerTodosQTR() < 3000) {
      mover(forcaReta, forcaReta);
    } else {
      PID(KP, KI, KD, forcaPID, setPoint);
    }

  }

};
