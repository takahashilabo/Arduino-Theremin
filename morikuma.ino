void morikuma_loop(float d) {
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
  static int tn[] = { 
    262, /* 0:C */
    294, /* 1:D */
    311, /* 2:D# */
    330, /* 3:E */
    349, /* 4:F */
    370, /* 5:F# */
    392, /* 6:G */
    440, /* 7:A */
    494, /* 8:B */
    523  /* 9:C */
  };

  static int mb[] = { 
    6, 5, 6, 3, 3, 2, 3, 0, 3, 1, 0, 1, 6, 7, 6, 3, 
    6, 7, 8, 9, 6, 3, 0, 7, 7, 8, 7, 6, 4, 3, 1, 0 
    };
  
  static int mb_len = sizeof(mb) / sizeof(int);

  static int melo_c = 0;
  static boolean flag = false;
    
  int ddi = int((d - d_min) / d_step);
  unsigned char *p;

  Serial.println(ddi);
  
  if (d >= d_max) {
    showColor(0, 0, 0);
    noTone(TONE);
    digitalWrite(LED, LOW);
    flag = false;
  } else if (ddi < 3 || ddi > 6) {
    if (!flag) {
      p = col[mb[melo_c] % 7];
      showColor(p[0], p[1], p[2]);
      tone(TONE, tn[mb[melo_c]]);
      melo_c = ++melo_c % mb_len;
      digitalWrite(LED, HIGH);
      flag = true;
    }
  }
  else {
    flag = false;
  }
}
