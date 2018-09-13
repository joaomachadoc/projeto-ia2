//Projeto IA II
#define LM35 A0
#define led0 2
#define led1 4
#define led2 7
int i;

void setup() {
  //Executado uma unica vez
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(led0, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  analogReference(DEFAULT);
}

void loop() {
  for(i=0; i < 100; i++){
  double temperatura = (((analogRead(LM35) * 5.0) / 1023.0) * 100.0);  // o analog read vai retornar em volts, as leituras do lm35 e depois (* 100) p trazer a celsius
  Serial.println(temperatura); //Escreve na porta serial USB
  delay(100); 
  }
  
  if(temperatura >= 5 and temperatura <22){
    digitalWrite(led0, HIGH); //Led Verde
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }else{                             
      if(temperatura >=22 and temperatura <24){
        digitalWrite(led0, LOW);
        digitalWrite(led1, HIGH); //Led Amarelo
        digitalWrite(led2, LOW);
      }else{
        if(temperatura >= 24 and temperatura <35){
           digitalWrite(led0, LOW);
           digitalWrite(led1, LOW);
           digitalWrite(led2, HIGH); //Led Vermelho
         }else{
           digitalWrite(led0, HIGH);
           digitalWrite(led1, HIGH);
           digitalWrite(led2, HIGH);
         } 
       }
    }
  delay(5000);  
  digitalWrite(led0, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}
  
