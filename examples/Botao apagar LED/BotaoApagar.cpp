
// Este é um arquivo de exemplo onde o LED fica aceso e apaga quando o botão BOOT do esp32 é pressionado.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37);

#define BOTAO 0

void setup()
{
  pinMode(BOTAO, INPUT_PULLUP);
}

void loop()
{
  LEDA.update();
  !digitalRead(BOTAO) ? LEDA.apagar() : LEDA.acender();
}
