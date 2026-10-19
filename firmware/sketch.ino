int n = 0;
bool alarm = false;

void setup() {
  Serial.begin(115200);
  pinMode(3, OUTPUT);
  pinMode(4, INPUT);
  digitalWrite(7, HIGH);
  pinMode(7, OUTPUT);
}

void loop() {
  delay(3000);
  n++;

  float s1 = analogRead(A0) * 100.0 / 1023;
  float s2 = -20 + analogRead(A1) * 100.0 / 1023;

  digitalWrite(3, LOW);
  delayMicroseconds(2);
  digitalWrite(3, HIGH);
  delayMicroseconds(10);
  digitalWrite(3, LOW);

  float s3 = pulseIn(4, HIGH, 30000) * 0.034 / 2;

  Serial.print("DATA n=");
  Serial.print(n);
  Serial.print(" s1=");
  Serial.print(s1, 2);
  Serial.print(" s2=");
  Serial.print(s2, 2);
  Serial.print(" s3=");
  Serial.println(s3, 2);

  if (s1 > 30 && !alarm) {
    alarm = true;
    digitalWrite(7, LOW);
    Serial.print("EVENT n=");
    Serial.print(n);
    Serial.println(" type=THRESHOLD");
  }

  if (s1 <= 30 && alarm) {
    alarm = false;
    digitalWrite(7, HIGH);
    Serial.print("EVENT n=");
    Serial.print(n);
    Serial.println(" type=NORMAL");
  }
}