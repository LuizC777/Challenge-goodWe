#include <LiquidCrystal_I2C.h> // Inclui a biblioteca do LCD
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Endereço I2C, colunas, linhas
const int sensorPin = A0;   // Pino onde o meio do potenciômetro está ligado
const int ledPin = 9;       // LED representando carregamento da bateria
int leituraSensor;
int limiar = 500;           // Limite mínimo para ativar o carregamento (0 a 1023)

void setup() {
  lcd.init();          // Inicializa o LCD
  lcd.backlight();     // Liga a luz de fundo
  lcd.setCursor(0, 0);
  lcd.print("Sistema Solar Ativo");
  delay(2000);
  lcd.clear();
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  leituraSensor = analogRead(sensorPin);  // Lê valor do potenciômetro (0 a 1023)

  lcd.setCursor(0, 0);
  lcd.print("--Nivel de luz: ");
  lcd.print(leituraSensor);

  if (leituraSensor > limiar) {

    digitalWrite(ledPin, HIGH);  // Ativa o carregamento (LED ligado)
    lcd.setCursor(0,1);
    lcd.print("-CARREGANDO-        ");
    lcd.setCursor(0,2);
    lcd.print("Status: Nivel de luz");
    lcd.setCursor(0,3);
    lcd.print("ideal               ");

  } else if(leituraSensor == 0) {

    digitalWrite(ledPin, LOW);   // Desativa o carregamento (LED desligado)
    lcd.setCursor(17,0);
    lcd.print("   ");    // Limpa os ultiomos caracteres
    lcd.setCursor(0,1);
    lcd.print("-DESLIGADO-         ");
    lcd.setCursor(0, 3);           
    lcd.print("                    ");  
    lcd.setCursor(0,2);
    lcd.print("Status: Modo noturno");

  } else {

    digitalWrite(ledPin, LOW);   // Desativa o carregamento (LED desligado)
    lcd.setCursor(0,1);
    lcd.print("-DESLIGADO-         ");
    lcd.setCursor(0,2);
    lcd.print("Status: Nivel de luz");
    lcd.setCursor(0,3);
    lcd.print("insuficiente        ");

  }

  if (leituraSensor < 1023){
    lcd.setCursor(19,0); 
    lcd.print(" ");    // Limpa o ultimo caractere
  }

  delay(100);
}
