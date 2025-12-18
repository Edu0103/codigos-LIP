// C++ code
//
int var = 0;
void setup()
{
  pinMode(A5, INPUT);
  pinMode(A4, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
}
void loop()
{
  var = 0; // variavel para ser um contador
  if (analogRead(A5) > 265) { // verifica se tá de dia
    while (var < 15 && analogRead(A4) != 1023) { // loop que enquanto o contador(var) menor que 15 e o botão não é precionado(1023) o semaforo está verde para carros
      // verde para carros e vermelho para pedestre
  digitalWrite(7, LOW);
      digitalWrite(6, HIGH);
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      var += 1; // aumenta o contador em 1
      delay(1000); // Wait for 1000 millisecond(s)
    }
    delay(3000); // Wait for 3000 millisecond(s) - esses 3 segundos de delay soma ao 15 do while totalizando 18s, pois se a pessoa clicar possui um delay de 3s após apertar o botão
    // vermelho para carros e verde para pedestre 
digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    tone(5, 523, 8000); // play tone 60 (C5 = 523 Hz)
    delay(8000); // Wait for 8000 millisecond(s)
// amarelo para carros e vermelho para pedestre 
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    delay(8000); // Wait for 8000 millisecond(s)
  } else { // caso seja noite executa
// apaga todos as luzes
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
    digitalWrite(7, LOW);
digitalWrite(6, LOW);
    while (analogRead(A5) <= 265) { // caso seja noite, pisca amarelo a cada 1 segundo
      digitalWrite(12, HIGH);
      delay(1000); // Wait for 1000 millisecond(s)
      digitalWrite(12, LOW);
      delay(1000); // Wait for 1000 millisecond(s)
    }
  }
}