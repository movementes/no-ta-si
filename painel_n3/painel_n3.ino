#include <Ultrasonic.h>

#define TONE_PIN 8
#define NOTE_B3  247
#define NOTE_D4  294
#define NOTE_F4  349

long sensor = 0;
int flag = 0;
long cm;

Ultrasonic ultrasonic(3, 4);

void setup() {}
 
void loop() {
  cm = ultrasonic.distanceRead();

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
    tone(TONE_PIN, NOTE_B3, 500);
  } else if (sensor > 56 && sensor <= 92) {
    tone(TONE_PIN, NOTE_D4, 500);
  } else if (sensor > 92 && sensor <= 130) {
    tone(TONE_PIN, NOTE_F4, 500);
  } else {
    noTone(TONE_PIN);
  }
  
  delay(100);
}
