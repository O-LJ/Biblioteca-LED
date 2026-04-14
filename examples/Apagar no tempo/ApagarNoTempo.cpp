
//Este é um arquivo de exemplo onde o LED fica aceso por durante 5 segundos e então é automaticamente desligado.

#include <Arduino.h>
#include <LED.h>

Led LEDA(37); //define o LED A como pino 37

void setup() {
LEDA.acender(5000); //Acende o LED por 5000ms (e depois o apaga). Parâmetro é opcional.
}

void loop() {
LEDA.update(); //Atualiza continuamente o estado do LED. DEVE ser incluido no void loop().

}
