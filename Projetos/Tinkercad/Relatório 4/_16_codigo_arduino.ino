// C++ code
// Programação para o circuito com o Arduino.

constexpr int VERDE = 13;
constexpr int AMARELO = 12;
constexpr int VERMELHO = 11;
constexpr int AZUL = 10;

class Temporizador {
private:
    unsigned long tempoInicial;
    unsigned long intervalo;

public:
    Temporizador(unsigned long intervalo) : intervalo(intervalo) {
        tempoInicial = millis();
    }

    bool passouTempo() {
        if (millis() - tempoInicial >= intervalo) {
            tempoInicial = millis();
            return true;
        }
        return false;
    }

    unsigned long tempoDecorrido() {
        return millis() - tempoInicial;
    }
};

Temporizador semaforoTimer(9000);
Temporizador piscaTimer(2000);

void setup() {
    pinMode(VERDE, OUTPUT);
    pinMode(AMARELO, OUTPUT);
    pinMode(VERMELHO, OUTPUT);
    pinMode(AZUL, OUTPUT);
}

void semaforo() {
    unsigned long tempo = semaforoTimer.tempoDecorrido();

    if (tempo < 4000) {
        digitalWrite(VERDE, HIGH);
        digitalWrite(AMARELO, LOW);
        digitalWrite(VERMELHO, LOW);
    } else if (tempo < 6000) {
        digitalWrite(VERDE, LOW);
        digitalWrite(AMARELO, HIGH);
    } else if (tempo < 9000) {
        digitalWrite(AMARELO, LOW);
        digitalWrite(VERMELHO, HIGH);
    }

    if (semaforoTimer.passouTempo()) {
        semaforoTimer = Temporizador(9000);
    }
}

void ledPisca() {
    unsigned long tempo = piscaTimer.tempoDecorrido();

    if (tempo < 1000) {
        digitalWrite(AZUL, HIGH);
    } else {
        digitalWrite(AZUL, LOW);
    }

    if (piscaTimer.passouTempo()) {
        piscaTimer = Temporizador(2000);
    }
}

void loop() {
    semaforo();
    ledPisca();
}
