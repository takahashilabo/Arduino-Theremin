//タッチ検出
const int SENSOR_1_OUT = 7;
const int SENSOR_1_IN = 8;
const int threshold = 6;

void touch_setup() {
  pinMode(SENSOR_1_OUT, OUTPUT);
  pinMode(SENSOR_1_IN, INPUT);
}

int prev_counter = 0;
boolean isTouched() {
  int counter = 0;
  digitalWrite(SENSOR_1_OUT, HIGH);
  while (digitalRead(SENSOR_1_IN) != HIGH) counter++;
  digitalWrite(SENSOR_1_OUT, LOW);  
  delay(1);
  counter = 0.8 * prev_counter + 0.2 * counter;
  prev_counter = counter;
  return (counter > threshold);
}
