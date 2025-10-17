#include "SRF05.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  float distance = getDistance();
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (isObjectDetected(30)) {
    Serial.println("Object detected within 30 cm");
  } else {
    Serial.println("No object within range");
  }

  float filtered = getFilteredDistance();
  Serial.print("Filtered Distance: ");
  Serial.print(filtered);
  Serial.println(" cm");

  Serial.println("-----------------------");
  delay(1000);
}
