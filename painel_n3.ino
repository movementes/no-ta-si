// Notas

#define NOTE_C3  131
#define NOTE_D3  147
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_D4  294
#define NOTE_F4  349

const int trigPin = 3;
const int echoPin = 4;
long sensor = 0;
int flag = 0;

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void setup() {
  Serial.begin(9600);
}
 
void loop() {

  long duration, cm;
  
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  // debug
  //Serial.print("cm: ");
  //Serial.println(cm);

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
  
  // debug
  //Serial.print("sensor: ");
  //Serial.println(sensor);

  if (sensor > 20 && sensor <= 56) {
    tone(8, NOTE_B3, 500);
    //Serial.println("NOTE_B3");
  } else if (sensor > 56 && sensor <= 92) {
    tone(8, NOTE_D4, 500);
    //Serial.println("NOTE_D4");
  } else if (sensor > 92 && sensor <= 130) {
    tone(8, NOTE_F4, 500);
    //Serial.println("NOTE_F4");
  } else {
    noTone(8);
    //Serial.println("SILENCIO");
  }
  
  delay(100);
}
