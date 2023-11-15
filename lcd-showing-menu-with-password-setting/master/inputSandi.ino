char InputSandi(char str[17]) {
  int i = 0;
  for (int j = 0; j < sizeof(inputSandi); j++) {
    inputSandi[j] = (char)0;
  }
  lcd.setCursor(0, 0);
  lcd.print(str);
  while (c != 'A' || c!='B') {
    lcd.setCursor(0, 1);
    Wire.requestFrom(8, 1);
    c = Wire.read();
    if (c != '\0') {
      lcd.setCursor(i, 1);
      if (c == 'D' && i > 0) {
        i--;
        lcd.setCursor(i, 1);
        lcd.print(" ");
        inputSandi[i] = '\0';
      }
      else if (c != 'D' && c != 'A' && c !='B' && i < 16) {
        lcd.print("*");
        inputSandi[i] = c;
        i++;
      }
      else if (c == 'A') {
        break;
      }
      else if(c=='B'){
        return 1;
      }
      else if (i >= 16) {
        for (int j = 0; j < 16; j++) {
          lcd.setCursor(j, 0);
          lcd.print(" ");
        }
        lcd.setCursor(0, 0);
        lcd.print("Terlalu panjang");
        delay(1000);
        for (int j = 0; j < 16; j++) {
          lcd.setCursor(j, 0);
          lcd.print(" ");
        }
        lcd.setCursor(0, 0);
        lcd.print(str);
      }
    }
  }
}
