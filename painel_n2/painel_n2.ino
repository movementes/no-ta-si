#define NOTE_D3  147
#define NOTE_F3  175
#define NOTE_A3  220

const int trigPin = 3;
const int echoPin = 4;
long sensor = 0;
int flag = 0;
long duration, cm;

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
 
void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  if (cm <= sensor) {
    sensor = cm;
    flag = 0;
  } else {
    flag++;
  }

  if (flag == 3) {
    sensor = cm;
    flag = 0;
  }

  if (sensor > 20 && sensor <= 56) {
    tone(8, NOTE_D3, 500);
  } else if (sensor > 56 && sensor <= 92) {
    tone(8, NOTE_F3, 500);
  } else if (sensor > 92 && sensor <= 130) {
    tone(8, NOTE_A3, 500);
  } else {
    noTone(8);
  }
  
  delay(100);
}
