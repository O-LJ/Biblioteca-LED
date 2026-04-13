#ifndef LED_h
#define LED_h

#include <Arduino.h>
/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 *
 * Permite ligar, desligar, ligar por um tempo, piscar continuamente
 * e piscar por uma quantidade definida.
 *
 * @param pin > pino ao qual o LED foi conectado.
 *
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
class Led
{
private:
    uint8_t pin;
    bool estado;
    bool apagarNoTempo;
    bool piscando;
    uint32_t TempoEspera;
    uint32_t apagarNoMomento;
    uint32_t MudarEm;
    float repeticoes;

    /**
     * @brief Processa o delsigamento temporizado.
     */
    void FApagarTempo();
    /**
     * @brief Processa a lógica da oscilação do estado do LED.
     */
    void FPiscada();

public:
    /**
     * @brief Constrói um objeto LED.
     * @param pin > Número do pino digital onde o LED está conectado.
     */

    Led(uint8_t pin);

    /**
     *@brief Liga o LED continuamente.
     *
     */
    void acender();
    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado Tempo, em ms, que o LED ficará ligado.
     */
    void acender(uint32_t tempoLigado);
    /**
     * @class Desliga o LED e cancela métodos automáticos.
     *
     */
    void apagar();
    /**
     * @class Pisca o LED continuamente.
     */
    void piscar();
    /**
     * @brief Pisca o LED continuamente.
     *
     * @param frequencia > Quantas vezes por segundo o LED piscará (uma "piscada" = 1 desliga + 1 liga).
     */
    void piscar(float frequencia);
    /**
     * @brief Pisca o LED continuamente.
     *
     * @param frequencia > Quantas vezes por segundo o LED piscará (uma "piscada" = 1 desliga + 1 liga) em hz.
     * @param repeticoes > Quantas vezes o LED piscará no total (uma "piscada" = 1 desliga + 1 desliga).
     */
    void piscar(float frequencia, uint16_t repeticoes);
    /**
     * @brief Alterna o estado do LED entre HIGH e LOW.
     */
    void alternar();
    /**
     * @brief Define o estado do LED.
     */
    void setEstado(bool Estado);

    uint8_t getPin();

    void update();
};

#endif