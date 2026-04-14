
//Este é um arquivo de exemplo onde o LED pisca 4 vezes por segundo e um total de 16 vezes.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37);

void setup() {
LEDA.piscar(4, 16);
}

void loop() {
LEDA.update();

}
