#include "LED.h"

Led::Led(uint8_t pin0) : pin(pin0),
                         estado(LOW),
                         apagarNoTempo(false),
                         apagarNoMomento(false),
                         TempoEspera(0),
                         MudarEm(0),
                         repeticoes(0)
{

    this->pin = pin0;
    estado = LOW;
    pinMode(pin, OUTPUT);
}

void Led::acender()
{
    apagarNoTempo = false;
    piscando = false;
    estado = HIGH;
}

void Led::acender(uint32_t tempoLigado)
{
    piscando = false;
    estado = HIGH;
    apagarNoTempo = true;
    apagarNoMomento = (millis() + tempoLigado);
}

void Led::piscar()
{
    apagarNoTempo = false;
    estado = HIGH;
    piscando = true;
    TempoEspera = 1000;
    MudarEm = millis() + TempoEspera; // Mudar em 1000ms
    repeticoes = -1;
}

void Led::piscar(float frequencia)
{

    if (frequencia == 0)
    {
        return;
    }
    apagarNoTempo = false;
    estado = HIGH;
    piscando = true;
    TempoEspera = (1000.0f / (2.0f * frequencia));
    MudarEm = millis() + TempoEspera; // Mudar em 1000ms
    repeticoes = -1;
}

void Led::piscar(float frequencia, uint16_t repeticoes)
{
    if (frequencia == 0)
    {
        return;
    }
    apagarNoTempo = false;
    estado = HIGH;
    piscando = true;
    TempoEspera = (1000.0f / (2.0f * frequencia));
    MudarEm = millis() + TempoEspera; // Mudar em 1000ms
    this->repeticoes = repeticoes * 2;
}

void Led::apagar()
{
    apagarNoTempo = false;
    piscando = false;
    estado = LOW;
}

void Led::alternar()
{
    estado = !estado;
}

void Led::setEstado(bool estado)
{
    this->estado = estado;
}

void Led::FApagarTempo()
{
    piscando = false;

    if (millis() >= apagarNoMomento)
    {
        estado = LOW;
        apagarNoTempo = false;
    }
}

void Led::FPiscada()
{
    apagarNoTempo = false;

    if (millis() >= MudarEm)
    {
        alternar();
        MudarEm = millis() + TempoEspera;
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                piscando = false;
                estado = LOW;
            }
        }
    }
}

uint8_t Led::getPin()
{
    return pin;
}
void Led::update()
{
    if (apagarNoTempo)
        FApagarTempo();
    if (piscando)
        FPiscada();

    digitalWrite(pin, estado);
}
