int TONE = 6;
int LED = 13;

int d_max = 17;  //cm
int d_min = 2;   //cm
float d_step = (d_max - d_min) / 9.0; //８音階

//boolean led_set_off = false; //LED等オフ指示済み？

//テーブLEDの７色定義（虹色）
unsigned char col[7][3] = {
  { 200, 0, 0 },
  { 0, 200, 0 },
  { 0, 0, 200 },
  { 200, 200, 0 },
  { 0, 200, 200 },
  { 200, 0, 200 },
  { 100, 100, 100 }
};

//音階
int tn[] = { 262, 294, 330, 349, 392, 440, 494, 523, 587, 659 };  //C4-E5

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  distance_setup();
  touch_setup();
  ledsetup();
}

unsigned long ctime = 0;
unsigned long ptime = 0;
float d = 0;

void loop() {
  ptime = millis();
  if (ptime - ctime > 100) {
    d = calcDist();
    ctime = ptime;
  }
  
  int ddi = int((d - d_min) / d_step);
  unsigned char *p = col[ddi % 7];

  Serial.println(d);

  if (d < d_max) {
    showColor(p[0], p[1], p[2]);
  } else {
    showColor(0, 0, 0);
  }

  if (isTouched()) {
      tone(TONE, tn[ddi]);
      digitalWrite(LED, HIGH);
  } else {
      noTone(TONE);
      digitalWrite(LED, LOW);
  }
}
