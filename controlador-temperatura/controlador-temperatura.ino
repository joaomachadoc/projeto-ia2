const int hot = 30; //set hot parameter
const int cold = 26; //set cold parameter
void setup() {
pinMode(A2, INPUT); //sensor
pinMode(2, OUTPUT); //blue
pinMode(3, OUTPUT); //green
pinMode(4, OUTPUT); //red
Serial.begin(9600);
analogReference(DEFAULT);
}
void loop() {
int sensor = analogRead(A2);
double tempC =(((analogRead(A2) * 5.0) / 1023.0) * 100.0);

Serial.print("temp: ");
Serial.println(tempC);
if (tempC < cold) { //cold
digitalWrite(2, HIGH);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
Serial.println("1");
}
else if (tempC >= hot) { //hot
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, HIGH);
Serial.println("3");
}
else { //fine
digitalWrite(2, LOW);
digitalWrite(3, HIGH);
digitalWrite(4, LOW);
Serial.println("2");
}
delay(5000);
digitalWrite(2, LOW);
digitalWrite(3, LOW);
digitalWrite(4, LOW);
delay(200);
}
