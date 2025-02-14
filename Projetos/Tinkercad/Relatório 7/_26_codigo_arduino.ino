// C++ code
// Programação para o circuito com o Arduino.

constexpr int LED_13 = 13;
constexpr int LED_12 = 12;
constexpr int LED_11 = 11;
constexpr int LED_10 = 10;

constexpr int SENSOR = A1;
constexpr int BUZZER = 4;

void configurarPinos() {
    pinMode(LED_13, OUTPUT);
    pinMode(LED_12, OUTPUT);
    pinMode(LED_11, OUTPUT);
    pinMode(LED_10, OUTPUT);
    pinMode(BUZZER, OUTPUT);
    Serial.begin(9600);
}

void desligarTudo() {
    digitalWrite(LED_13, LOW);
    digitalWrite(LED_12, LOW);
    digitalWrite(LED_11, LOW);
    digitalWrite(LED_10, LOW);
    noTone(BUZZER);
}

void atualizarMonitor(int valor) {
    if (valor >= 1000) {
        analogWrite(LED_13, 255);
        tone(BUZZER, 1500);
    } else if (valor > 700) {
        analogWrite(LED_12, 180);
    } else if (valor > 500) {
        analogWrite(LED_11, 130);
    } else {
        analogWrite(LED_10, 100);
    }
}

void loop() {
    int valor = analogRead(SENSOR);
    Serial.println(valor);
    delay(200);
    
    desligarTudo();
    atualizarMonitor(valor);
}

void setup() {
    configurarPinos();
}
