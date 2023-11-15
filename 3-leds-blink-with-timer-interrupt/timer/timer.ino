#include <LiquidCrystal_I2C.h>
#include <Wire.h>
//Tambahkan dua baris kode berikut setelah baris "#include <Wire.h>" pada file LiquidCrystal_I2C.cpp
//untuk menggunakan pin I2C pada pin PB11 dan PB10 (pin 0 dan 1)
//  TwoWire WIRE2 (2, I2C_FAST_MODE);
//  #define Wire WIRE2

LiquidCrystal_I2C lcd(0x27, 16, 2); //definisi variabel untuk lcd
const byte OutRows[4] = {22, 21, 20, 19}; //definisi array untuk pin baris keypad
const byte InCols[4] = {18, 17, 16, 15}; //definisi array untuk pin kolom keypad
const byte led[3] = {3, 4, 5};

//definisi timer 1, 2, dan 3
HardwareTimer timer_1(1);
HardwareTimer timer_2(2);
HardwareTimer timer_3(3);

int state[3] = {0, 0, 0};
float frekuensi[3] = {0, 0, 0};
char inputBuffer[4];
char str[16];
void setup() {
  Wire.begin();
  Serial.begin(115200);
  //inisiasi keypad
  for (int i = 0; i < 4 ; i++) {
    pinMode(InCols[i], INPUT_PULLUP);
    pinMode(OutRows[i], OUTPUT);
    digitalWrite(OutRows[i], HIGH);
  }

  //inisiasi LED
  for (int i = 0; i < 3; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], LOW);
  }

  //inisiasi LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop() {
  char key=keypad();

  //tekan '1', '2', atau '3' untuk mengatur frekuensi kedipan LED 1, 2, atau 3
  if (key == '1' || key == '2' || key == '3') {
    int x = key - '0';
    state[x - 1] = 0;
  }

  //jika ditekan '1', masukkan nilai frekuensi
  if (state[0] == 0) {
    char str[17] = "Frekuensi 1?";

    //mengatur masukan frekuensi
    if (inputFrekuensi(str)) {
      //jika ditekan tombol 'B' (kembali), maka kembali ke tampilan frekuensi
      state[0]=1;
      lcd.clear();
    }

    //jika frekuensi sudah ditetapkan, maka atur timernya.
    else {
      state[0] = 1;
      lcd.clear();
      frekuensi[0] = strtof(inputBuffer, NULL);
      timer_1.pause();
      timer_1.setPeriod(1000000 / frekuensi[0]);
      timer_1.setChannel1Mode(TIMER_OUTPUT_COMPARE);
      timer_1.setCompare(TIMER_CH1, 1);
      timer_1.attachInterrupt(1, handlerLed1);
      timer_1.refresh();
      timer_1.resume();
    }
  }

  //jika ditekan '2', masukkan nilai frekuensi
  if (state[1] == 0) {
    char str[17] = "Frekuensi 2?";

    //mengatur masukan frekuensi
    if (inputFrekuensi(str)) {
      //jika ditekan tombol 'B' (kembali), maka kembali ke tampilan frekuensi
      state[1]=1;
      lcd.clear();
    }

    //jika frekuensi sudah ditetapkan, maka atur timernya.
    else {
      state[1] = 1;
      lcd.clear();
      frekuensi[1] = strtof(inputBuffer, NULL);
      timer_2.pause();
      timer_2.setPeriod(1000000 / frekuensi[1]);
      timer_2.setChannel1Mode(TIMER_OUTPUT_COMPARE);
      timer_2.setCompare(TIMER_CH1, 1);
      timer_2.attachInterrupt(1, handlerLed2);
      timer_2.refresh();
      timer_2.resume();
    }
  }

  //jika ditekan '3', masukkan nilai frekuensi
  if (state[2] == 0) {
    char str[17] = "Frekuensi 3?";

    //mengatur masukan frekuensi
    if (inputFrekuensi(str)) {
      //jika ditekan tombol 'B' (kembali), maka kembali ke tampilan frekuensi
      state[2]=1;
      lcd.clear();
    }

    //jika frekuensi sudah ditetapkan, maka atur timernya.
    else {
      state[2] = 1;
      lcd.clear();
      frekuensi[2] = strtof(inputBuffer, NULL);
      timer_3.pause();
      timer_3.setPeriod(1000000 / frekuensi[2]);
      timer_3.setChannel1Mode(TIMER_OUTPUT_COMPARE);
      timer_3.setCompare(TIMER_CH1, 1);
      timer_3.attachInterrupt(1, handlerLed3);
      timer_3.refresh();
      timer_3.resume();
    }
  }
  //menampilkan frekuensi di LCD
  lcd.setCursor(0, 0);
  lcd.print(" f1    f2    f3 ");
  lcd.setCursor(0, 1);
  lcd.print(frekuensi[0]);
  lcd.setCursor(6, 1);
  lcd.print(frekuensi[1]);
  lcd.setCursor(12, 1);
  lcd.print(frekuensi[2]);
  for(int i=4;i<15;i+=6){
    lcd.setCursor(i,1);
    lcd.print(" ");
  }
}

//handler jika terjadi interupsi di timer_1
void handlerLed1(void) {
  digitalWrite(led[0], !digitalRead(led[0]));
}

//handler jika terjadi interupsi di timer_2
void handlerLed2(void) {
  digitalWrite(led[1], !digitalRead(led[1]));
}

//handler jika terjadi interupsi di timer_3
void handlerLed3(void) {
  digitalWrite(led[2], !digitalRead(led[2]));
}
