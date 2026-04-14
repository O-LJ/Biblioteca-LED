
//Este é um arquivo de exemplo onde o LED Acende ao apertar o botao BOOT do esp32.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37); //define o LED A como pino 37
#define BOTAO 0 //define o BOTAO como pino 0
void setup() {
      pinMode(BOTAO, INPUT_PULLUP); //define o BOTAO como uma entrada
}

void loop() {
LEDA.update(); //Atualiza continuamente o estado do LED. DEVE ser incluido no void loop().
  !digitalRead(BOTAO) ? LEDA.acender() : LEDA.apagar(); //Se o BOTAO for pressionado, acende o LED, caso esteja solto, desliga o LED
}
