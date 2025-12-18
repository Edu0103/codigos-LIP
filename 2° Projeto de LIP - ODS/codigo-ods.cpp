int counter;

void setup()
{
  pinMode(A5, INPUT);
  pinMode(5, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(4, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(9, INPUT);
  pinMode(8, OUTPUT);
}

void loop()
{
  if (analogRead(A5) >= 164) {
    digitalWrite(5, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    tone(7, 523, 500); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(5, LOW);
  }
  if (analogRead(A0) < 438) {
    // solo meio úmido ou seco, liga a bomba d'agua
    digitalWrite(4, HIGH);
    tone(7, 29, 5000); // play tone 10 (A#0 = 29 Hz)
    for (counter = 0; counter < 10; ++counter) {
      // loop enquanto irriga
      delay(500); // Wait for 500 millisecond(s)
    }
    digitalWrite(4, LOW);
    // desliga a bomba
  }
  if (analogRead(A1) <= 790 && digitalRead(9) == 1) {
    // verifica se está dia e se tem movimento
    digitalWrite(8, HIGH);
    delay(1000); // Wait for 1000 millisecond(s)
    tone(7, 523, 500); // play tone 60 (C5 = 523 Hz)
  } else {
    digitalWrite(8, LOW);
    // desliga à noite
  }
}