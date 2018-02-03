#include <Ultrasonic.h>

#define NOTE_D3  147
#define NOTE_F3  175
#define NOTE_A3  220

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
