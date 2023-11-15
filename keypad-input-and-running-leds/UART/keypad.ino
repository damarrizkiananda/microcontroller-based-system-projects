String keypad (void) {
  int r = 1;
  String key = "tidak ditekan";
  int pb;
  int x;
  for (r = 1; r <= 4; r++) {
    digitalWrite(OutRows[r - 1], LOW);
    //digitalWrite(led[r-1], LOW);
    pb = PollingPushButton();
    switch (r) {
      case 1:
        switch (pb) {
          case 1:
            key = "1";
            return key;
            break;
          case 2:
            key = "2";
            return key;
            break;
          case 3:
            key = "3";
            return key;
            break;
          case 4:
            key = "A";
            return key;
            break;
          default:
            key = "";
            break;
        }
        break;
      case 2:
        switch (pb) {
          case 1:
            key = "4";
            return key;
            break;
          case 2:
            key = "5";
            return key;
            break;
          case 3:
            key = "6";
            return key;
            break;
          case 4:
            key = "B";
            return key;
            break;
          default:
            key = "";
            break;
        }
        break;
      case 3:
        switch (pb) {
          case 1:
            key = "7";
            return key;
            break;
          case 2:
            key = "8";
            return key;
            break;
          case 3:
            key = "9";
            return key;
            break;
          case 4:
            key = "C";
            return key;
            break;
          default:
            key = "";
            break;
        }
        break;
      case 4:
        switch (pb) {
          case 1:
            key = "*";
            return key;
            break;
          case 2:
            key = "0";
            return key;
            break;
          case 3:
            key = "#";
            return key;
            break;
          case 4:
            key = "D";
            return key;
            break;
          default:
            key = "";
            break;
        }
        break;
    }
    digitalWrite(OutRows[r - 1], HIGH);
    //digitalWrite(led[r-1],HIGH);
    //    Serial.print(r);
    //    Serial.print(" ");

  }
  //  Serial.print(pb);
  //  Serial.print(" ");
  //  Serial.println(key);
}
