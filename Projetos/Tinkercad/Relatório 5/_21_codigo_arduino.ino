// C++ code
// Programação para o circuito com o Arduino.

constexpr int ledR = 13;
constexpr int ledG = 11;
constexpr int ledB = 12;

constexpr int bot = A1;

int estadoAnterior = LOW;
int corAtual = 0;

void configurarPinos() {
    pinMode(ledR, OUTPUT);
    pinMode(ledG, OUTPUT);
    pinMode(ledB, OUTPUT);
    pinMode(bot, INPUT);
}

void definirCor(int r, int g, int b) {
    digitalWrite(ledR, r);
    digitalWrite(ledG, g);
    digitalWrite(ledB, b);
}

void atualizarCor() {
    switch (corAtual) {
        case 0: definirCor(1, 0, 0); break; // Vermelho
        case 1: definirCor(0, 0, 1); break; // Azul
        case 2: definirCor(0, 1, 1); break; // Ciano
        case 3: definirCor(1, 1, 1); break; // Branco
        case 4: definirCor(0, 1, 0); break; // Verde
        case 5: definirCor(1, 1, 0); break; // Amarelo
        case 6: definirCor(1, 0, 1); break; // Magenta
        case 7: definirCor(0, 0, 0); break; // LED apagado
    }
}

void loop() {
    int poa_bot = digitalRead(bot);
    
    if (poa_bot == HIGH && estadoAnterior == LOW) {
        corAtual = (corAtual + 1) % 8;
        delay(300);
    }
    
    estadoAnterior = poa_bot;
    atualizarCor();
}

void setup() {
    configurarPinos();
}
