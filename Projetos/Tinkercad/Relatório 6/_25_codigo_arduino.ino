// C++ code
// Programação para o circuito com o Arduino.

constexpr int led1 = 13;
constexpr int led2 = 12;
constexpr int led3 = 11;
constexpr int led4 = 10;

char entrada = '0';
bool modoBinario = false;

void configurarPinos() {
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
}

void controleNormal(char comando) {
    if (comando == '1') digitalWrite(led1, HIGH);
    if (comando == '2') digitalWrite(led2, HIGH);
    if (comando == '3') digitalWrite(led3, HIGH);
    if (comando == '4') digitalWrite(led4, HIGH);
    if (comando == '5') {
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
    }
    if (comando == '6') {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
    }
}

void controleBinario(char comando) {
    int numero = comando - '0'; // Converte o caractere para número
    if (numero >= 1 && numero <= 9) {
        digitalWrite(led1, bitRead(numero, 3)); // Bit mais significativo
        digitalWrite(led2, bitRead(numero, 2));
        digitalWrite(led3, bitRead(numero, 1));
        digitalWrite(led4, bitRead(numero, 0)); // Bit menos significativo
    }
}

void loop() {
    if (Serial.available() > 0) {
        entrada = Serial.read();

        if (entrada == '0') {
            modoBinario = true;
            Serial.println("Modo binário ativado!");
        }
        if (entrada == 'n') {
            modoBinario = false;
            Serial.println("Modo normal ativado!");
        }

        if (!modoBinario) {
            controleNormal(entrada);
        } else {
            controleBinario(entrada);
        }
    }
}

void setup() {
    configurarPinos();
}
