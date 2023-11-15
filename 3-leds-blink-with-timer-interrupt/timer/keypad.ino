char keypad(void) {
  char key;
  int r = 1;
  int pb;
  for (r = 1; r <= 4; r++) {
    digitalWrite(OutRows[r - 1], LOW);
    pb = PollingPushButton();
    switch (r) {
      case 1:
        switch (pb) {
          case 1:
            key = '1';
            break;
          case 2:
            key = '2';
            break;
          case 3:
            key = '3';
            break;
          case 4:
            key = 'A';
            break;
          default:
            key = '\0';
            break;
        }
        break;
      case 2:
        switch (pb) {
          case 1:
            key = '4';
            break;
          case 2:
            key = '5';
            break;
          case 3:
            key = '6';
            break;
          case 4:
            key = 'B';
            break;
          default:
            key = '\0';
            break;
        }
        break;
      case 3:
        switch (pb) {
          case 1:
            key = '7';
            break;
          case 2:
            key = '8';
            break;
          case 3:
            key = '9';
            break;
          case 4:
            key = 'C';
            break;
          default:
            key = '\0';
            break;
        }
        break;
      case 4:
        switch (pb) {
          case 1:
            key = '.';
            break;
          case 2:
            key = '0';
            break;
          case 3:
            key = '#';
            break;
          case 4:
            key = 'D';
            break;
          default:
            key = '\0';
            break;
        }
        break;
    }
    digitalWrite(OutRows[r - 1], HIGH);
    if (key != '\0') {
      //Serial.print(key);
      return (key);
    }
  }
  return '\0';
}
