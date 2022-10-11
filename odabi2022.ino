#define TONE 6
#define LED 13
#define MODE 3

#define d_max 17  //cm
#define d_min 2   //cm
static float d_step = (d_max - d_min) / 9.0; //８音階

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(MODE, INPUT_PULLUP);
  distance_setup();
  touch_setup();
  ledsetup();
}

void loop() {
  static float d = 0;

  d = getDist();

  if (digitalRead(MODE) == LOW) {
    morikuma_loop(d);
  } else {
    free_play_loop(d);
  }
}
