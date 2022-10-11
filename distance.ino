#define TRIG 2
#define ECHO 4

void distance_setup() {
  pinMode(ECHO, INPUT);
  pinMode(TRIG, OUTPUT);
}

float calcDist() {
  static float duration = 0;
  static float distance_f = 0; //フィルタ後
  static float speed_of_sound = (331.5 + 0.6 * 25) / 2 * 100 / 1000000 ; // 25℃の気温の想定
  static float filter_a = 0.8; //0<a<1の範囲　大きいほど効果大
  static float distance = 0;

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

float getDist() {
  static unsigned long ctime = 0;
  static unsigned long ptime = 0;
  static float d = 0;

  ptime = millis();
  if (ptime - ctime > 100) {
    d = calcDist();
    ctime = ptime;
  }

  return d;
}
