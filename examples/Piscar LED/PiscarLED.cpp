
//Este é um arquivo de exemplo onde o LED pisca continuamente.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37);

void setup() {
LEDA.piscar();
}

void loop() {
LEDA.update();

}
