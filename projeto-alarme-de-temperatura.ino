//Programa 9.1: Projeto de Alarme de Temperatura

#define BUZZER 14 //Define BUZZER como 14 (GPIO14 - D5)
#define BOTAO 5 //Define BOTAO como 5 (GPIO5 - D1)
float Read_A0, V_A0, Temperatura, Ultima_Temperatura; //Define as variáveis

void setup() {
  pinMode(A0, INPUT); //Declara o pino analógico A0 como entrada
  pinMode(BOTAO, INPUT); //Declara o pino do botão como entrada
  Serial.begin(9600); //Inicializa a comunicação com o serial
}

void loop() {
  Read_A0 = analogRead(A0); //Faz a leitura da porta analógica
  V_A0 = Read_A0*(3.3/1023); //Cálculo da tensão da porta analógica
  Temperatura = V_A0/0.01; //Cálculo da temperatura

  if(Temperatura != Ultima_Temperatura){ //Condição para imprimir menos variações
    Ultima_Temperatura = Temperatura; //Salvando a última temperatura
    Serial.print("Temperatura: "); //Imprime
    Serial.print(Temperatura); //Imprime
    Serial.println("°C"); //Imprime
    delay(1000); //Espera 1 segundo
  }
  
  if(Temperatura >= 33.00){ //Condição de ativação do buzzer
    tone(BUZZER, 1200, 250); //Toca o buzzer na frequência de 1200Hz por 250ms
    tone(BUZZER,  800, 250); //Toca o buzzer na frequência de 800Hz por 250ms
    if((digitalRead(BOTAO)) == 1){ //Condição para desligar o buzzer com o botão
      noTone(BUZZER); //Desativa o buzzer
    }
  }
}