int sequencia[16] = {};

int botoes[4] = {8, 9, 10, 11};
int leds[4] = {2, 3, 4, 5};
int tons[4] = {330, 262, 349, 294};

int tempoMostrar = 1000;
int tempoAceso = 300;
int tempoApagado = 200;

int rodada = 0;
int passo = 0;
int botaoPressionado = 0;
bool gameOver = false;

void setup() {
  Serial.begin(9600);

  // LEDs
  pinMode(2, OUTPUT); //verde
  pinMode(3, OUTPUT); //vermelho
  pinMode(4, OUTPUT); //azul
  pinMode(5, OUTPUT); //amarelo

  // Buzzer 
  pinMode(7, OUTPUT);

  // Botões
  pinMode(8, INPUT_PULLUP);//verde
  pinMode(9, INPUT_PULLUP);//vermelho
  pinMode(10, INPUT_PULLUP);//azul
  pinMode(11, INPUT_PULLUP);//amarelo

  randomSeed(analogRead(A0));

  Serial.println("Jogo iniciado!");
}

void loop() {
  if (gameOver == true) {
    efeito1();   
    reiniciarJogo();
  } 
  else {
    Serial.print("Nível: ");
    Serial.println(rodada);

    proximaRodada();      
    reproduzirSequencia();
    aguardarJogador();
    delay(tempoMostrar);

    if (rodada > 7) {
      tempoMostrar = 500;
      tempoAceso = 150;
      tempoApagado = 100;
    }

    if (rodada == 15) {
      efeito3();
      reiniciarJogo();
    }
  }
}

// Próxima cor
void proximaRodada() {
  sequencia[rodada] = random(4);
  rodada++;
}

// Reproduzir sequência
void reproduzirSequencia() {
  for (int i = 0; i < rodada; i++) {
    tone(7, tons[sequencia[i]]);
    digitalWrite(leds[sequencia[i]], HIGH);
    delay(tempoAceso);
    noTone(7);
    digitalWrite(leds[sequencia[i]], LOW);
    delay(tempoApagado);
  }
}

void aguardarJogador() {
  for (int i = 0; i < rodada; i++) {

    bool jogadaEfetuada = false;

    while (!jogadaEfetuada) {
      for (int j = 0; j < 4; j++) {
        if (digitalRead(botoes[j]) == 0) {
          botaoPressionado = j;

          tone(7, tons[j]);
          digitalWrite(leds[j], HIGH);
          delay(300);
          digitalWrite(leds[j], LOW);
          noTone(7);

          jogadaEfetuada = true;
        }
      }
    }

    if (sequencia[passo] != botaoPressionado) {
      Serial.println("ERROU!");
      efeito2();
      gameOver = true;
      break;
    }

    passo++;
  }

  passo = 0;
}

// Reiniciar
void reiniciarJogo() {
  rodada = 0;
  passo = 0;
  gameOver = false;

  Serial.println("Jogo reiniciado! Nível 0");

  delay(1000);
}

// Perdeu
void efeito1() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  delay(600);
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(600);
}

void efeito2() {
  for (int i = 0; i < 4; i++) {
    tone(7, 70);
    digitalWrite(leds[i], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW);
    noTone(0);
  }
}

// Venceu
void efeito3() {
  int notas[] = {660, 770, 880, 990, 1040};
  int tempo[] = {200, 200, 200, 200, 400};

  for (int i = 0; i < 5; i++) {
    tone(7, notas[i], tempo[i]);

    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(tempo[i]);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(100);
  }

  noTone(7);
}