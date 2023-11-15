char inputFrekuensi(char str[17]) {
  int i = 6;
  char c;
  lcd.clear();
  //menghapus isi array inputBuffer
  for (int j = 0; j < sizeof(inputBuffer); j++) {
    inputBuffer[j] = (char)0;
  }
  
  lcd.setCursor(2, 0);
  lcd.print(str);

  //ketika belum ditekan 'A' (enter) atau 'B' (kembali), maka selalu looping
  while (c != 'A' || c!='B') {
    c = keypad();
    if (c != '\0') {
      lcd.setCursor(i, 1);

      //hapus karakter yang dimasukkan jika ditekan 'D'
      if (c == 'D' && i > 6) {
        i--;
        lcd.setCursor(i, 1);
        lcd.print(" ");
        inputBuffer[i] = '\0';
      }

      //mengisi array inputBuffer
      else if (c != 'D' && c != 'A' && c !='B' && i < 9) {
        lcd.print(c);
        inputBuffer[i-6] = c;
        i++;
      }

      //'A' untuk tombol enter
      else if (c == 'A') {
        return 0;
      }

      //'B' untuk tombol kembali
      else if(c=='B'){
        return 1;
      }

      //notifikasi untuk jumlah karakter sudah melewati batas (4 digit)
      else if (i >= 9) {
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
        lcd.setCursor(2, 0);
        lcd.print(str);
      }
    }
  }
}
