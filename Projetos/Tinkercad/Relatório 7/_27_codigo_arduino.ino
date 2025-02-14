// C++ code
// Programação para o circuito com o Arduino.

constexpr int sensor = A1;
constexpr int buzzer = 4;

void configurarPinos() {
    pinMode(buzzer, OUTPUT);
    Serial.begin(9600);
}

void ajustarSom(int valor) {
    if (valor >= 1000) {
        tone(buzzer, 1500); // Som agudo para luz intensa
    } else if (valor > 700) {
        tone(buzzer, 1200); // Som médio-alto
    } else if (valor > 500) {
        tone(buzzer, 800);  // Som médio
    } else if (valor > 400) {
        tone(buzzer, 350);  // Som grave
    } else {
        noTone(buzzer); // Silêncio no escuro
    }
}

void loop() {
    int valor = analogRead(sensor);
    Serial.println(valor);
    delay(200);
    ajustarSom(valor);
}

void setup() {
    configurarPinos();
}