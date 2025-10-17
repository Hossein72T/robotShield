#include <Arduino.h>
#include "SRF05.h"

const int trigEchoPin = A3;

float getDistance() {
  pinMode(trigEchoPin, OUTPUT);
  digitalWrite(trigEchoPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigEchoPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigEchoPin, LOW);

  pinMode(trigEchoPin, INPUT);
  unsigned long duration = pulseIn(trigEchoPin, HIGH, 30000);

  if (duration == 0) return -1;
  return duration / 58.0;
}

bool isObjectDetected(float thresholdCM) {
  float d = getDistance();
  return (d > 0 && d <= thresholdCM);
}

float getFilteredDistance() {
  float sum = 0;
  int count = 0;

  for (int i = 0; i < 5; i++) {
    float d = getDistance();
    if (d > 0) {
      sum += d;
      count++;
    }
    delay(100);
  }

  if (count == 0) return -1;
  return sum / count;
}
