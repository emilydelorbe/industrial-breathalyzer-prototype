#include <Wire.h>
#include <U8g2lib.h>

// --- CAMBIO IMPORTANTE: Usamos el modo "1" en lugar de "F" para ahorrar mucha memoria RAM ---
U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0);

const int ledRojo = 8;
const int ledAmarillo = 9;
const int ledVerde = 10;
const int ledAzul = 11;
const int buzzer = 12;
const int sensorAlcohol = A0;

bool buzzerActivo = false;
bool buzzerDesactivado = false;
unsigned long tiempoInicioBuzzer = 0;
const unsigned long duracionBuzzer = 15000; // 15 segundos

int valorFiltrado = 0;
int valorEnReposo = 0;
bool calibrado = false;
unsigned long tiempoInicioCalibracion = 0;
const unsigned long duracionCalibracion = 5000;
int sumaCalibracion = 0;
int muestras = 0;

const char* estadoAnterior = "";

void setup() {
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAzul, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr); // Fuente grande

  apagarTodosLosLeds();

  // Pantalla de carga optimizada
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB08_tr);
    u8g2.setCursor(0, 30);
    u8g2.print("Inicializando...");
  } while ( u8g2.nextPage() );

  tiempoInicioCalibracion = millis();
}

void apagarTodosLosLeds() {
  digitalWrite(ledRojo, LOW);
  digitalWrite(ledAmarillo, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAzul, LOW);
}

void sonarBuzzerCorto() {
  tone(buzzer, 3500);
  delay(150);
  noTone(buzzer);
}

void loop() {
  int valorBruto = analogRead(sensorAlcohol);

  // 1. Lógica de Calibración
  if (!calibrado) {
    if (millis() - tiempoInicioCalibracion < duracionCalibracion) {
      sumaCalibracion += valorBruto;
      muestras++;
      delay(100);
      return;
    } else {
      valorEnReposo = sumaCalibracion / max(muestras, 1);
      calibrado = true;
    }
  }

  // 2. Filtros y Cálculos
  valorFiltrado = 0.2 * valorBruto + 0.8 * valorFiltrado;
  int valor = valorFiltrado;
  float bac = max(0.0, (valor - valorEnReposo) * 0.00035);

  const char* estado = "LIBRE";
  int segundosRestantes = 0;

  apagarTodosLosLeds();

  if (bac >= 0.05) {
    digitalWrite(ledRojo, HIGH);
    estado = "NO APTO";
  } else if (bac >= 0.03) {
    digitalWrite(ledAmarillo, HIGH);
    estado = "PRECAUCION";
  } else if (bac >= 0.01) {
    digitalWrite(ledVerde, HIGH);
    estado = "MODERADO";
  } else {
    digitalWrite(ledAzul, HIGH);
    estado = "LIBRE";
  }

  // 3. Lógica del Buzzer
  if (strcmp(estado, estadoAnterior) != 0) {
    sonarBuzzerCorto();
    estadoAnterior = estado;
  }

  if (strcmp(estado, "NO APTO") == 0) {
    if (!buzzerActivo && !buzzerDesactivado) {
      buzzerActivo = true;
      tiempoInicioBuzzer = millis();
      tone(buzzer, 3500);
    }
  } else {
    buzzerActivo = false;
    buzzerDesactivado = false;
    noTone(buzzer);
  }

  if (buzzerActivo) {
    unsigned long tiempoTranscurrido = millis() - tiempoInicioBuzzer;
    if (tiempoTranscurrido >= duracionBuzzer) {
      noTone(buzzer);
      buzzerActivo = false;
      buzzerDesactivado = true;
    } else {
      segundosRestantes = (duracionBuzzer - tiempoTranscurrido) / 1000;
    }
  }

  // 4. Dibujar en Pantalla (Optimizado para poca memoria)
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB08_tr);
    
    u8g2.setCursor(0, 28);
    u8g2.print("BAC: ");
    u8g2.print(bac, 3);

    u8g2.setCursor(0, 52);
    u8g2.print("Estado: ");
    u8g2.print(estado);

    if (buzzerActivo) {
      u8g2.setCursor(0, 64);
      u8g2.print("ALARMA ");
      u8g2.print(segundosRestantes);
      u8g2.print("s");
    }
  } while ( u8g2.nextPage() );
  
  delay(100);
}