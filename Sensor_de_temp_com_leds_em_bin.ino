//Projeto IA II
#define LM35 A0
#define led0 2
#define led1 4
#define led2 7
#define led3 8
#define led4 12
int i;

void setup() {
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  Serial.begin(9600);
  analogReference(DEFAULT);
  tone (13, 3000, 100);
}

//Esse codigo faz uma leitura no lm35(sensor de temp) e acende 5 leds informando a temp em binario
//Os leds assumem posição High ou Low como 1 ou 0

void loop() {
  double temperatura = (((analogRead(LM35) * 5.0) / 1023.0) * 100.0);  // o analog read vai retornar em volts, as leituras do lm35 e depois (* 100) p trazer a celsius
  Serial.println(temperatura);
  if(temperatura >= 5 and temperatura <23){
    digitalWrite(led0, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }else{                             
      if(temperatura >=23 and temperatura <24){
        digitalWrite(led0, HIGH);
        digitalWrite(led1, LOW);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        digitalWrite(led4, HIGH);
      }else{
         if(temperatura >= 31 and temperatura <35){
              digitalWrite(led0, HIGH);
              digitalWrite(led1, HIGH);
              digitalWrite(led2, HIGH);
              digitalWrite(led3, HIGH);
              digitalWrite(led4, HIGH);
       }else{
            //se for abaixo de 5 graus celsius ou maior que 35
            tone (13, 3000, 50);
            for(i=0;i<20;i++){
            digitalWrite(led0, HIGH);
            digitalWrite(led1, HIGH);
            digitalWrite(led2, HIGH);
            digitalWrite(led3, HIGH);
            digitalWrite(led4, HIGH);
            delay(100);
            digitalWrite(led0, LOW);
            digitalWrite(led1, LOW);
            digitalWrite(led2, LOW);
            digitalWrite(led3, LOW);
            digitalWrite(led4, LOW);
            delay(100);
            } 
        }
      }
    }
  delay(10000);
  //desligando os leds para nao interferir na leitura do lm35, já que ele faz a leitura em volts
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  delay(500);
}
  
