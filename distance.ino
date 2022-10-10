int TRIG = 2;
int ECHO = 4;

float duration = 0;
float distance = 0;
float distance_f = 0; //フィルタ後
float speed_of_sound = (331.5 + 0.6 * 25) / 2 * 100 / 1000000 ; // 25℃の気温の想定
float filter_a = 0.8; //0<a<1の範囲　大きいほど効果大

void distance_setup() {
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

float getDist() { 
  return distance;
}

float calcDist() {
  digitalWrite(TRIG, LOW); 
  delayMicroseconds(2); 
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10); 
  digitalWrite(TRIG, LOW);
  duration = pulseIn(ECHO, HIGH);
  if (duration > 0) {
    distance = duration * speed_of_sound;
    distance_f = filter_a * distance_f + (1 - filter_a) * distance;
    return distance;
  }
  return 0.0;
}
