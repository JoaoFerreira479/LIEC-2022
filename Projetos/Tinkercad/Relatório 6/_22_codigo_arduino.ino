// C++ code
// Programação para o circuito com o Arduino.

char entrada;

constexpr int led1 = 13;
constexpr int led2 = 12;
constexpr int led3 = 11;
constexpr int led4 = 10;

void configurarPinos() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void desligarTodosLeds() {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
}

void processarEntrada(char comando) {
    desligarTodosLeds();
    
    switch (comando) {
        case 'r': digitalWrite(led1, HIGH); break; // Vermelho
        case 'y': digitalWrite(led2, HIGH); break; // Amarelo
        case 'g': digitalWrite(led3, HIGH); break; // Verde
        case 'b': digitalWrite(led4, HIGH); break; // Azul
        case 'a': // Acende todos os LEDs
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            break;
        case 'x': // Apaga todos os LEDs
            desligarTodosLeds();
            break;
    }
}

void setup() {
    Serial.begin(9600);
    configurarPinos();
}

void loop() {
    if (Serial.available() > 0) {
        entrada = Serial.read();
        processarEntrada(entrada);
    }
}
