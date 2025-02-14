// C++ code
// Programação para o circuito com o Arduino.

constexpr int led1 = 13;
constexpr int led2 = 12;
constexpr int led3 = 11;
constexpr int led4 = 10;

constexpr int botao1 = A1;

void configurarPinos() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(botao1, INPUT);
}

void acionarSequenciaLEDs() {
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led3, HIGH);
    delay(1000);
    digitalWrite(led4, HIGH);
    delay(1000);
    
    delay(1000);
    
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    delay(1000);
}

void setup() {
    configurarPinos();
}

void loop() {
    if (digitalRead(botao1) == HIGH) {
        acionarSequenciaLEDs();
    }
}
