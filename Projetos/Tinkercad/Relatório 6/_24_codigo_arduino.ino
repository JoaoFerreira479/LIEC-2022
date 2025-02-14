// C++ code
// Programação para o circuito com o Arduino.

constexpr int led1 = 11;
constexpr int led2 = 10;

int brilhoLed1 = 255;
int brilhoLed2 = 90;

bool estado = true;

void configurarPinos() {
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
}

void alternarBrilho() {
    if (estado) {
        brilhoLed1 = 0;
        brilhoLed2 = 255;
    } else {
        brilhoLed1 = 255;
        brilhoLed2 = 0;
    }

    analogWrite(led1, brilhoLed1);
    analogWrite(led2, brilhoLed2);

    estado = !estado;
}

void setup() {
    configurarPinos();
}

void loop() {
    alternarBrilho();
    delay(3000);
}
