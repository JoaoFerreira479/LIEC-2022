// C++ code
// Programação para o circuito com o Arduino.

constexpr int RED = 9;
constexpr int GREEN = 10;
constexpr int BLUE = 11;

struct Cor {
    int r;
    int g;
    int b;
};

void setColor(const Cor& cor);

constexpr Cor cores[] = {
    {255, 0, 0},    // Vermelho
    {0, 255, 0},    // Verde
    {0, 0, 255},    // Azul
    {255, 255, 0},  // Amarelo
    {0, 255, 255},  // Ciano
    {255, 0, 255},  // Magenta
    {255, 255, 255},// Branco
    {0, 0, 0}       // Apagado
};

constexpr size_t numCores = sizeof(cores) / sizeof(cores[0]);

unsigned long tempoAnterior = 0;
const unsigned long intervaloTroca = 1000;
size_t indiceCor = 0;

void setup() {
    pinMode(RED, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(BLUE, OUTPUT);
}

void loop() {
    unsigned long tempoAtual = millis();
    
    if (tempoAtual - tempoAnterior >= intervaloTroca) {
        tempoAnterior = tempoAtual;
        
        setColor(cores[indiceCor]);
        indiceCor = (indiceCor + 1) % numCores;
    }
}

void setColor(const Cor& cor) {
    analogWrite(RED, cor.r);
    analogWrite(GREEN, cor.g);
    analogWrite(BLUE, cor.b);
}
