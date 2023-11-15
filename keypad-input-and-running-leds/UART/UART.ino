const byte OutRows[4] = {22, 21, 20, 19};
const byte InCols[4] = {18, 17, 16, 15};
const byte led[8] = {9, 8, 7, 6, 5, 4, 3, 2};
char mode;

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 4 ; i++) {
    pinMode(InCols[i], INPUT_PULLUP);
    pinMode(OutRows[i], OUTPUT);
    pinMode(led[i], OUTPUT);
    pinMode(led[i + 4], OUTPUT);
    digitalWrite(led[i], HIGH);
    digitalWrite(led[i + 4], HIGH);
    digitalWrite(OutRows[i], HIGH);
  }
  delay(2000);
  Serial.println("Tekan sembarang angka dari 1 - 8");
}

void ledClear(void) {
  for (int i = 0; i <= 7; i++) {
    digitalWrite(led[i], HIGH);
  }
}
void serialFlush() {
  while (Serial.available() > 0) {
    char trash = Serial.read();
  }
}
void loop() {
  String key = "";

  while (!Serial.available()) {}

  if (Serial.available() > 0) {
    mode = Serial.read();
    if (mode == '8') {
      ledClear();
      serialFlush();
      Serial.println("Bacaan keypad:");
      while (mode == '8') {
        key = keypad();
        if (key != "") {
          Serial.print(key);
        }
        if (Serial.available() > 0) {
          mode = Serial.read();
          Serial.println();
          break;
        }
      }
    }
    if (mode == '1' || mode == '2' || mode == '3' || mode == '4' || mode == '5' || mode == '6' || mode == '7') {
      ledClear();
      serialFlush();
      Serial.print("LED mode ");
      Serial.println(mode);
      while (mode == '1' || mode == '2' || mode == '3' || mode == '4' || mode == '5' || mode == '6' || mode == '7') {
        RunningLed(mode);
        if (Serial.available() > 0) {
          //mode = Serial.read();
          //Serial.println();
          break;
        }
      }
    }

    else {
      ledClear();
      serialFlush();
      Serial.println("Perintah salah, tekan sembarang angka dari 1 - 8");
    }
  }
}
