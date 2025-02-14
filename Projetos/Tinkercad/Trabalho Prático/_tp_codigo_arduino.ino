// C++ code
// Programação para o circuito com o Arduino.

#include <Keypad.h>
#include <Servo.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);

Servo servo_Motor;

constexpr int BUZZER = 10;
constexpr int LED_VERMELHO = 12;
constexpr int LED_VERDE = 11;
constexpr int SERVO_PIN = 13;

// Senha de acesso (flexível)
const char password[] = "1A4B7C";
int position = 0;

// Teclado matricial
constexpr byte ROWS = 4;
constexpr byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};  
byte colPins[COLS] = {5, 4, 3, 2};  

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

bool locked = true;
unsigned long lastInputTime = 0;  // Para exibir senha temporariamente

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Digite sua Senha");
  lcd.setCursor(0, 1);
  lcd.print("Senha: ");

  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  servo_Motor.attach(SERVO_PIN);
  
  setLocked(true);  // Inicia trancado
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    lastInputTime = millis();  // Atualiza o tempo do último input

    lcd.setCursor(6 + position, 1);
    lcd.print(key);  // Mostra a tecla digitada
    delay(500);  // Exibe por 500ms
    lcd.setCursor(6 + position, 1);
    lcd.print('*');  // Substitui por asterisco

    if (key == '*' || key == '#') {
      resetSystem();
    } 
    else if (key == password[position]) {
      position++;
      if (position == strlen(password)) {  // Verifica tamanho da senha dinamicamente
        setLocked(false);
        delay(5000);  // Mantém destrancado por 5 segundos
        resetSystem();
      }
    } 
    else {
      resetSystem();  // Reseta se um caractere estiver errado
    }
  }
}

void resetSystem() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Digite sua Senha");
  lcd.setCursor(0, 1);
  lcd.print("Senha: ");
  position = 0;
  setLocked(true);
}

void setLocked(bool lockState) {
  locked = lockState;

  if (locked) {
    tone(BUZZER, 293);  
    delay(400);
    noTone(BUZZER);
    
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, LOW);
    
    servo_Motor.write(0);
  } 
  else {
    tone(BUZZER, 500);
    delay(400);
    noTone(BUZZER);
    
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, HIGH);
    
    servo_Motor.write(90);
  }
}
