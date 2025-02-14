// C++ code
// Programação para o circuito com o Arduino.

constexpr int led = 13;

char entrada = '0';

void configurarPinos() {
    Serial.begin(9600);
    pinMode(led, OUTPUT);
}

void piscarLED(int intervalo) {
    for (int i = 0; i < 10; i++) {
        digitalWrite(led, HIGH);
        delay(intervalo);
        digitalWrite(led, LOW);
        delay(intervalo);
    }
}

void enviarMorse(const char *codigo) {
    while (*codigo) {
        if (*codigo == '.') {
            digitalWrite(led, HIGH);
            delay(100); // Ponto: LED acende por 100ms
        } else if (*codigo == '-') {
            digitalWrite(led, HIGH);
            delay(300); // Traço: LED acende por 300ms
        }
        digitalWrite(led, LOW);
        delay(200);
        codigo++;
    }
}

void ajustarBrilhoLED() {
    for (int brilho = 0; brilho <= 255; brilho += 51) { // Aumenta gradualmente o brilho
        analogWrite(led, brilho);
        delay(200);
    }
    for (int brilho = 255; brilho >= 0; brilho -= 51) { // Diminui gradualmente o brilho
        analogWrite(led, brilho);
        delay(200);
    }
}

void processarEntrada(char comando) {
    switch (comando) {
        case 'a': piscarLED(100); break; // Pisca a cada 100ms
        case 'b': piscarLED(50); break; // Pisca a cada 50ms
        case 'p': enviarMorse(".--."); break; // Código Morse para 'P'
        case 'u': enviarMorse("..-"); break; // Código Morse para 'U'
        case 'c': enviarMorse("-.-."); break; // Código Morse para 'C'
        case 'x': digitalWrite(led, LOW); break; // Apaga o LED
        case 'w': ajustarBrilhoLED(); break;
        default: Serial.println("Comando inválido."); break;
    }
}

void loop() {
    if (Serial.available() > 0) {
        entrada = Serial.read();
        processarEntrada(entrada);
    }
}

void setup() {
    configurarPinos();
}
