
// Este é um arquivo de exemplo onde o LED fica aceso e apaga quando o botão BOOT do esp32 é pressionado.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37); //define o LED A como pino 37

#define BOTAO 0 //define o BOTAO como pino 0

void setup()
{
  pinMode(BOTAO, INPUT_PULLUP); //define o BOTAO como uma entrada
}

void loop()
{
  LEDA.update(); //Atualiza continuamente o estado do LED. DEVE ser incluido no void loop().
  !digitalRead(BOTAO) ? LEDA.apagar() : LEDA.acender(); //Se o BOTAO for pressionado, desliga o LED, caso esteja solto, acende o LED
}
