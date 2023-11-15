/*
 * Damar Rizki Ananda
 * 17/413505/TK/45945
 * 
 * update terakhir 20 Maret 2020
 * 
 * Program Maple Mini sebagai master
 * untuk kunci pengaman yang ditampilkan di LCD
 */

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
char sandi[17] = "1234567890";
char inputSandi[17] = "";
char c;
bool kunci = 1;
int state = 1;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  int i = 0, k = 0;
  while (state == 1) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Selamat Datang!");
    lcd.setCursor(0, 1);
    char nim[] = "17/413505/TK/45945";
    int len = strlen(nim);
    for (int j = 0; j < 16; j++) {
      lcd.setCursor(j, 1);
      lcd.print(nim[j + i]);
    }
    if (i == 0 || i == 2) {
      delay(500);
    }
    delay(500);
    if (k == 0) {
      i++;
      if (i == 2) {
        k = 1;
      }
    }
    else {
      i--;
      if (i == 0) {
        k = 0;
      }
    }
    if (i == 0) {
      for (int j = 0; j < 16; j++) {
        lcd.setCursor(j, 1);
        lcd.print(nim[j + i]);
      }
      delay(1000);
      Wire.requestFrom(8, 1);
      c = Wire.read();
      if (c == 'C') {
        kunci = 1;
      }
      else if (c != '\0') {
        lcd.clear();
        state = 2;
        break;
      }
      switch (kunci) {
        case 0:
          lcd.clear();
          lcd.setCursor(1, 0);
          lcd.print("Kunci terbuka");
          delay(1000);
          break;
        case 1:
          lcd.clear();
          lcd.setCursor(1, 0);
          lcd.print("Pintu terkunci");
          delay(1000);
          break;
      }
    }

    Wire.requestFrom(8, 1);
    c = Wire.read();
    if (c == 'C') {
      kunci = 1;
      lcd.clear();
      lcd.setCursor(1, 0);
      lcd.print("Pintu terkunci");
      delay(1000);
    }
    else if (c != '\0') {
      lcd.clear();
      state = 2;
      break;
    }
  }

  while (state == 2) {
    lcd.setCursor(0, 1);
    lcd.print("2. Atur sandi");
    switch (kunci) {
      case 0:
        lcd.setCursor(0, 0);
        lcd.print("1. Kunci pintu");
        Wire.requestFrom(8, 1);
        c = Wire.read();
        if (c == '1') {
          lcd.clear();
          lcd.setCursor(1, 0);
          lcd.print("Pintu terkunci");
          delay(1000);
          kunci = 1;
          state = 1;
        }
        break;
      case 1:
        lcd.setCursor(0, 0);
        lcd.print("1. Buka kunci");
        Wire.requestFrom(8, 1);
        c = Wire.read();
        if (c == '1') {
          lcd.clear();
          state = 3;
        }
        break;
    }
    if (c == '2') {
      lcd.clear();
      state = 4;
    }
    if (c == 'B') {
      lcd.clear();
      state = 1;
    }
  }

  while (state == 3) {
    char str[17] = "Masukkan sandi:";
    if (InputSandi(str)) {
      lcd.clear();
      state = 2;
      break;
    }
    if (!strcmp(inputSandi, sandi)) {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Sandi benar,");
      lcd.setCursor(1, 1);
      lcd.print("kunci terbuka");
      delay(3000);
      kunci = 0;
      state = 1;
    }
    else {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Sandi salah,");
      lcd.setCursor(3, 1);
      lcd.print("coba lagi!");
      delay(3000);
      lcd.clear();
    }
  }

  while (state == 4) {
    char str[17] = "Sandi lama:";
    if (InputSandi(str)) {
      lcd.clear();
      state = 2;
      break;
    }
    if (!strcmp(inputSandi, sandi)) {
      lcd.clear();
      char str[17] = "Sandi baru:";
      if (InputSandi(str)) {
        lcd.clear();
        state = 4;
        break;
      }
      strcpy(sandi, inputSandi);
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Sandi diubah");
      delay(1000);
      state = 1;
    }
    else {
      lcd.clear();
      lcd.setCursor(2, 0);
      lcd.print("Sandi salah,");
      lcd.setCursor(3, 1);
      lcd.print("coba lagi!");
      delay(3000);
      lcd.clear();
      break;
    }
  }
}
