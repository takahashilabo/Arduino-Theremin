#define SENSOR_1_OUT 7
#define SENSOR_1_IN  8
#define THRED 5

void touch_setup() {
  pinMode(SENSOR_1_OUT, OUTPUT);
  pinMode(SENSOR_1_IN, INPUT);
}

static int prev_c = 0;

boolean isTouched() {
  int c = 0;
  digitalWrite(SENSOR_1_OUT, HIGH);
  while (digitalRead(SENSOR_1_IN) != HIGH) c++;
  digitalWrite(SENSOR_1_OUT, LOW);  
  delay(1);
  c = 0.8 * prev_c + 0.2 * c;
  prev_c = c;
  return (c > THRED);
}
