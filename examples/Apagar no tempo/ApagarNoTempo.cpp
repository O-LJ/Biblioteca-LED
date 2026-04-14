
//Este é um arquivo de exemplo onde o LED fica aceso por durante 5 segundos e então é automaticamente desligado.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37);

void setup() {
LEDA.acender(5000);
}

void loop() {
LEDA.update();

}
