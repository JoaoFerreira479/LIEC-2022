// C++ code
// Programação para o circuito com o Arduino.

constexpr int led1 = 13;
constexpr int led2 = 12;
constexpr int led3 = 11;
constexpr int led4 = 10;

constexpr int botao1 = A2;
constexpr int botao2 = A3;

void configurarPinos() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(botao1, INPUT_PULLUP);
    pinMode(botao2, INPUT_PULLUP);
}

void controlarLeds() {
    int estadoBotao1 = digitalRead(botao1);
    int estadoBotao2 = digitalRead(botao2);
    
    digitalWrite(led1, estadoBotao1 == LOW ? HIGH : LOW);
    digitalWrite(led3, estadoBotao1 == LOW ? HIGH : LOW);
    digitalWrite(led2, estadoBotao2 == LOW ? HIGH : LOW);
    digitalWrite(led4, estadoBotao2 == LOW ? HIGH : LOW);
}

void setup() {
    configurarPinos();
}

void loop() {
    controlarLeds();
}
