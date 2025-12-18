#include <TimerOne.h> // Biblioteca TimerOne
#include <MultiFuncShield.h> // Biblioteca Multi Function Shield
// Sensores
const int PIR_PIN = 9; // Sensor de movimento (PIR)
const int HUMI_PIN = A5; // Umidade do solo
const int LDR_PIN = A4; // Fotoresistor (LDR)
char comandoSerial = 0; // Armazena comandos recebidos pela Serial
// Função do sensor de presença
int lerPIR() {
return digitalRead(PIR_PIN);
}
// Função do sensor de umidade do solo
int lerUmidade() {
return analogRead(HUMI_PIN);
}
// Função do nível de luz (fotoresistor)
int lerLuz() {
return analogRead(LDR_PIN);
}
// Função para controlar os LEDs do shield conforme a lógica
void controlarLeds(int pirValor, int umidade, int luz) {
// LED 1
if (pirValor == HIGH) {
MFS.writeLeds(LED_1, ON);
} else {
MFS.writeLeds(LED_1, OFF);
}
// LED 2
if (umidade < 550) {
MFS.writeLeds(LED_2, ON); // solo seco
} else {
MFS.writeLeds(LED_2, OFF); // solo úmido
}
// LED 3
if (luz < 400) {
MFS.writeLeds(LED_3, ON); // ambiente escuro → luz ligada
} else {
MFS.writeLeds(LED_3, OFF); // ambiente claro
}
}
// Função SETUP principal
void setup() {
Serial.begin(9600);
Timer1.initialize(); // Inicializa Timer1
MFS.initialize(&Timer1); // Inicializa Shield
pinMode(PIR_PIN, INPUT); // PIR como entrada
MFS.write("INIC"); // Mensagem inicial
delay(1000);
}
// Função LOOP principal
void loop() {
// ------- Leitura dos sensores -------
int pirValor = lerPIR();
int umidade = lerUmidade();
int luz = lerLuz();
// ------- Controle dos LEDs conforme sensores -------
controlarLeds(pirValor, umidade, luz);
// ------- Saída no Serial Monitor -------
Serial.print("PIR: ");
Serial.println(pirValor);
Serial.print("Umidade: ");
Serial.println(umidade);
Serial.print("Luz: ");
Serial.println(luz);
delay(1000);
}