// C++ code
// Programação para o circuito com o Arduino.

constexpr int LED_PIN = 7;
constexpr int INTERVALO = 150;

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(INTERVALO);
  digitalWrite(LED_PIN, LOW);
  delay(INTERVALO);
}
