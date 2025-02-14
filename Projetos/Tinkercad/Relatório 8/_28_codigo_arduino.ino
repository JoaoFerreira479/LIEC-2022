// C++ code
// Programação para o circuito com o Arduino.

constexpr int led1 = 13;
constexpr int led2 = 12; 
constexpr int led3 = 11; 
constexpr int led4 = 10; 

constexpr int trigger = 3;
constexpr int echo = 2;

void configurarPinos() {
    Serial.begin(9600);
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

int medirDistancia() {
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    int temp = pulseIn(echo, HIGH);
    return (temp / 2) / 29.1;
}

void desligarLeds() {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
}

void atualizarLeds(int dist) {
    if (dist > 150) {
        digitalWrite(led1, HIGH); // LED Azul (distância longa)
    } else if (dist > 100) {
        digitalWrite(led2, HIGH); // LED Verde (média)
    } else if (dist > 70) {
        digitalWrite(led3, HIGH); // LED Amarelo (curta)
    } else {
        digitalWrite(led4, HIGH); // LED Vermelho (muito curta, menos de 70 cm)
    }
}

void loop() {
    int distancia = medirDistancia();
    Serial.print(distancia);
    Serial.println(" cm");
    delay(100);
    desligarLeds();
    atualizarLeds(distancia);
}

void setup() {
    configurarPinos();
}
