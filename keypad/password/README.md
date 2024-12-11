# گزارش کار : پروژه PASSWORD

## هدف پروژه :
هدف این پروژه پیادهسازی یک سیستم قفل رمزدار با استفاده از آردوینو و یک صفحه کلید ماتریسی (Keypad) است . در این
پروژه، کاربر میتواند یک رمز عبور تعیین کند و سپس با وارد کردن رمز صحیح، یک LED روشن میشود .
## قطعات مورد نیاز :
1.برد اردوینو uno 
2. صفحه کلید ماتریسی 4x4. 
4. مقاومت 220 اهم برای LED
5. سیمهای جامپر
6. برد بورد

## شماتیک
![pass_schematic](https://github.com/user-attachments/assets/02c766d0-412d-4621-a9cf-fb1cf86dec0c)

## کد 
```
#include <Keypad.h>
int led = 13;
float pass = 0;
float firstNumber = 0;
const byte ROWS = 4;  //four rows
const byte COLS = 4;  //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  { '1', '2', '3', 'A' },
  { '4', '5', '6', 'B' },
  { '7', '8', '9', 'C' },
  { '*', '0', '#', 'D' }
};
byte colPins[ROWS] = { 5, 4, 3, 2 };  // Pins used for the rows of the keypad
byte rowPins[COLS] = { 9, 8, 7, 6 };  // Pins used for the columns of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  Serial.println("set password : ");

  for (int i = 0; i < 4; i++) {
    int button = int(customKeypad.getKey()) - 48;
    Serial.println(button);
    if (0 <= button && button <= 10) {
      Serial.print(button);
      pass = pass * 10 + button;
    }
  }
  Serial.println("set password is copmleted, Enter code:");
}
void loop() {
  int button = int(customKeypad.getKey()) - 48;
  if (0 <= button && button <= 10) {
    Serial.print(button);
    for (int i = 0; i < 4; i++) {
      firstNumber = firstNumber * 10 + button;
    }
  }

  if (pass == firstNumber) {
    digitalWrite(led, HIGH);

  } else {
    digitalWrite(led, LOW);
  }
  firstNumber = 0;
  delay(1000);
}
```
## توضیح کد :
1. تعریف و مقداردهی اولیه :
- کتابخانه `Keypad` برای کار با صفحه کلید ماتریسی استفاده شده است . - پینهای متصل به ردیفها و ستونهای صفحه کلید مشخص شدهاند . - ماتریس کلیدها ( کاراکترهای صفحه کلید ) تعریف شده است .
2. تنظیمات اولیه در تابع setup():
- پین LED به عنوان خروجی تعریف شده است . - از سریال مانیتور برای نمایش مراحل عملیات استفاده میشود . - کاربر از طریق سریال مانیتور رمز عبور چهار رقمی را تعیین میکند و مقدار آن در متغیر `pass` ذخیره میشود .
3. تابع loop():
- برنامه منتظر ورود رمز عبور توسط کاربر میماند . - هر دکمهای که فشار داده میشود، خوانده و بررسی میشود . - اگر رمز وارد شده با رمز تعیین شده برابر باشد، LED روشن میشود؛ در غیر این صورت خاموش باقی میماند .
ر شح عملکرد کد :
1. تعیین رمز عبور :
- در ابتدای برنامه، کاربر باید یک رمز چهار رقمی وارد کند . - دکمههای فشار داده شده از طریق `customKeypad.getKey()` خوانده میشوند و به عدد صحیح تبدیل میشوند . - رمز عبور وارد شده در متغیر `pass` ذخیره میشود .
2. بررسی رمز وارد شده :
- برنامه منتظر وارد کردن رمز توسط کاربر است . - دکمههای فشار داده شده در متغیر `firstNumber` ذخیره میشوند . - اگر مقدار `firstNumber` با `pass` برابر باشد، LED روشن میشود؛ در غیر این صورت خاموش باقی میماند .
3. ریست مقدار `firstNumber`:
- در انتهای هر چک کردن، مقدار `firstNumber` به صفر بازنشانی میشود تا آماده بررسی ورودی جدید باشد .
## نتیجه گیری :
این پروژه به خوبی نحوه تعامل آردوینو با صفحه کلید ماتریسی را نشان میدهد و میتواند به عنوان پایهای برای سیستمهای
قفل رمزدار پیچیدهتر استفاده شود . با اعمال بهبودهای پیشنهادی، میتوان عملکرد و قابلیت اطمینان سیستم را افزایش داد .
