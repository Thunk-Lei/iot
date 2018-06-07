int ASignal = A0;

void setup() {
pinMode(ASignal, INPUT);
Serial.begin(9600);
}

void loop() {
int sensorValue = analogRead(ASignal);
unsigned long test = 1023 - sensorValue;
Serial.print("rain=");
Serial.println(test);
delay(1000);
}
