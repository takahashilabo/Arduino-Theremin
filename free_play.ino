void free_play_loop(float d) {
  
  //テーブLEDの７色定義（虹色）
  static unsigned char col[7][3] = {
    { 200, 0, 0 },
    { 0, 200, 0 },
    { 0, 0, 200 },
    { 200, 200, 0 },
    { 0, 200, 200 },
    { 200, 0, 200 },
    { 100, 100, 100 }
  };
  
  //音階
  static int tn[] = { 262, 294, 330, 349, 392, 440, 494, 523, 587, 659 };  //C4-E5

  static int ddi = 0;
  static unsigned char *p;

  ddi = int((d - d_min) / d_step);
  p = col[ddi % 7];
  
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
