
//Este é um arquivo de exemplo onde o LED Acende.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37);

void setup() {
LEDA.acender();
}

void loop() {
LEDA.update();

}
