
//Este é um arquivo de exemplo onde o LED pisca continuamente.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37); //define o LED A como pino 37

void setup() {
LEDA.piscar(); //Inverte o estado do LED (entre ON e OFF) a cada um segundo continuamente permanentemente.
}

void loop() {
LEDA.update(); //Atualiza continuamente o estado do LED. DEVE ser incluido no void loop().

}
