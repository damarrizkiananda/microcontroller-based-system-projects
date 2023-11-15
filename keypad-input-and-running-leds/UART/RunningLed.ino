void RunningLed(char mode) {
  switch (mode) {
    case '1':
      for (int i = 0; i <= 1; i++) {
        for (int j = 0; j <= 3; j++) {
          digitalWrite(led[j], HIGH);
          digitalWrite(led[j + 4], LOW);
        }
        delay(500);
        for (int k = 0; k <= 3; k++) {
          digitalWrite(led[k], LOW);
          digitalWrite(led[k + 4], HIGH);
        }
        delay(500);
      }

      break;
    case '2':
      for (int i = 0; i <= 8; i++) { //Membuat iterasi sebanyak 8 kali perulangan
        digitalWrite(led[i], LOW); //Menyalakan LED sesuai nilai n dari for, dimana akan selalu berkurang setiap iterasinya
        digitalWrite(led[i - 1], HIGH); //Mematikan LED yang sudah nyala pada iterasi sebelumnya, misal nilai n=7, maka LED 8 mati, dan LED 7 nyala
        delay(100);
      }
      digitalWrite(led[7], HIGH); //Mematikan LED yang terakhir menyala, yaitu LED ke-8.
      break;
    case '3':
      for (int i = 7; i >= 0; i--) { //Mmebuat iterasi 8 kali perulangan, karena ada 8 led yang diatur
        digitalWrite(led[i], LOW); //Menyalakan LED dari paling besar hingga paling kecil urutannya (8 -> 1)
        digitalWrite(led[8 - i], LOW); //Menyalakan LED dari paling kecil hingga paling besar urutannya (1 -> 8)
        delay(100); // Mempertahankan LED yang sedang menyala selama 0,5 detik sebelum nyalanya berpindah
        digitalWrite(led[i], HIGH); // Mematikan LED yang saat itu sedang menyala urutannya 8->1
        digitalWrite(led[8 - i], HIGH); //Mematikan LED yang saat itu sedang menyala dengan urutan 1->8
      }
      break;
    case '4':
      for (int i = 0; i <= 3; i++) { //Membuat iterasi sebanyak 8 kali perulangan
        digitalWrite(led[i], LOW); //Menyalakan LED sesuai nilai n dari for, dimana akan selalu berkurang setiap iterasinya
        digitalWrite(led[i + 4], LOW);
        digitalWrite(led[i - 1], HIGH); //Mematikan LED yang sudah nyala pada iterasi sebelumnya, misal nilai n=7, maka LED 8 mati, dan LED 7 nyala
        digitalWrite(led[i + 3], HIGH);
        delay(100);
      }
      digitalWrite(led[7], HIGH); //Mematikan LED yang terakhir menyala, yaitu LED ke-8.
      break;
    case '5':
      for (int i = 0; i <= 3; i++) { //Membuat iterasi sebanyak 8 kali perulangan
        digitalWrite(led[i + 1], LOW);
        digitalWrite(led[i], LOW); //Menyalakan LED sesuai nilai n dari for, dimana akan selalu berkurang setiap iterasinya
        digitalWrite(led[i + 4], LOW);
        digitalWrite(led[i + 5], LOW);
        digitalWrite(led[i - 2], HIGH);
        digitalWrite(led[i + 2], HIGH);
        digitalWrite(led[i - 1], HIGH); //Mematikan LED yang sudah nyala pada iterasi sebelumnya, misal nilai n=7, maka LED 8 mati, dan LED 7 nyala
        digitalWrite(led[i + 3], HIGH);
        delay(500);
      }
      digitalWrite(led[7], HIGH); //Mematikan LED yang terakhir menyala, yaitu LED ke-8.
      break;
    case '6':
      for (int i = 0; i <= 7; i++) {
        digitalWrite(led[i], LOW);
        delay(100);
      }
      for (int i = 0; i <= 7; i++) {
        digitalWrite(led[i], HIGH);
        delay(100);
      }
      break;
    case '7':
      for (int i = 0; i <= 3; i++) {
        digitalWrite(led[i], LOW);
        digitalWrite(led[7 - i], LOW);
        delay(100);
      }
      for (int i = 0; i <= 7; i++) {
        digitalWrite(led[i], HIGH);
        digitalWrite(led[7 - i], HIGH);
        delay(100);
      }
      break;
  }
}
