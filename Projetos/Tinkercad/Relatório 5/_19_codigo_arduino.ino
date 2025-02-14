// C++ code
// Programação para o circuito com o Arduino.

constexpr int led1 = 10;
constexpr int botao1 = 13;

void configurarPinos() {
    pinMode(led1, OUTPUT);
    pinMode(botao1, INPUT);
}

void piscarLED(int vezes, int intervalo) {
    for (int i = 0; i < vezes; ++i) {
        digitalWrite(led1, HIGH);
        delay(intervalo);
        digitalWrite(led1, LOW);
        delay(intervalo);
    }
}

void setup() {
    configurarPinos();
}

void loop() {
    if (digitalRead(botao1) == HIGH) {
        piscarLED(5, 250);
    } else {
        digitalWrite(led1, LOW);
    }
}
