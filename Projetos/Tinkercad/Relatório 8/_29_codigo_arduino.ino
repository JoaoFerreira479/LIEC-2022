// C++ code
// Programação para o circuito com o Arduino.

constexpr int led1 = 13; 
constexpr int led2 = 12; 
constexpr int led3 = 11; 

constexpr int buzzer = 8;
constexpr int trigger = 3;
constexpr int echo = 2;

void configurarPinos() {
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(buzzer, OUTPUT);
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
}

long medirDistancia() {
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    long temp = pulseIn(echo, HIGH);
    return (temp / 2) / 29.1;
}

void desligarTudo() {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    noTone(buzzer);
}

void atualizarIndicadores(long dist) {
    if (dist > 200) {
        digitalWrite(led1, HIGH);
        tone(buzzer, 1500);
    } else if (dist > 100) {
        digitalWrite(led2, HIGH);
        tone(buzzer, 1000);
    } else {
        digitalWrite(led3, HIGH);
        tone(buzzer, 100);
    }
}

void loop() {
    long distancia = medirDistancia();
    Serial.print(distancia);
    Serial.println(" cm");
    delay(100);
    desligarTudo();
    atualizarIndicadores(distancia);
}

void setup() {
    configurarPinos();
}
