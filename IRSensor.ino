/**
 * Controls an output state through an infrared sensor activity.
 *
 * Author: Thiago Bonfim
 * Created: 07/06/2016
 *
 */

int sensorValue;
int ledState = 0;
int ledCounter = 0;

void setup() {
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(A7);
  Serial.print(sensorValue);
  Serial.print('#');
  if (sensorValue < 10 && ledCounter == 0) {
    ledState = ~ledState;
    digitalWrite(2, ledState);
    ledCounter = 50;
  } else if (ledCounter > 0) {
    ledCounter--;
  }
}
