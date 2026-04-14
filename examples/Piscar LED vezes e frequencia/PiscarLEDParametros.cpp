
//Este é um arquivo de exemplo onde o LED pisca 4 vezes por segundo e um total de 16 vezes.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37); //define o LED A como pino 37

void setup() {
LEDA.piscar(4, 16); //Troca o estado do LED (entre ON e OFF) 4 vezes por segundo e parará após desligar 16 vezes.
}

void loop() {
LEDA.update(); //Atualiza continuamente o estado do LED. DEVE ser incluido no void loop().

}
