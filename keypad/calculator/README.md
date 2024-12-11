# گزارش کار ساخت ماشین حساب ساده با استفاده از کیپد و Arduino

## وسایل مورد نیاز :
1 . برد Arduino Uno
2 . کیپد 4x4 (Keypad 4x4)
3 . سیم اتصال
## نحوه اتصال سخت افزار
اتصالات کیپد :
اتصال پینهای ردیف (rowPins) کیپد به پینهای 6 ، 7 ، 8، و 9.
اتصال پینهای ستون (colPins) کیپد به پینهای 2 ، 3 ، 4، و 5.

![](/calculator/calculator_schematic.jpg)
## کد کامل پروژه :
```c++

#include <Keypad.h>
const byte ROWS = 4; // four rows 
const byte COLS = 4; // four columns

float firstNumber = 0;
float secondNumber = 0;
float result = 0;
bool section = false;
int type = 0;

// Map the buttons to an array for the Keymap instance
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte colPins[ROWS] = {5, 4, 3, 2}; // Pins used for the rows of the keypad
byte rowPins[COLS] = {9, 8, 7, 6}; // Pins used for the columns of the keypad
// Initialise the Keypad
Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);   // Initialise the serial monitor
}

void loop() {
  // Read the pushed button
  int button = int(customKeypad.getKey()) - 48;
  if (0 <= button && button <= 10) {
    Serial.print(button);
    if (section == false) {
      firstNumber = firstNumber * 10 + button;
    } else {
      secondNumber = secondNumber * 10 + button;
    }
  } else {
    switch (button) {
      case 17://A

        section = true;
        type = 1;
        Serial.print('+');
        break;
      case 18://///B

        section = true;
        type = 2;
        Serial.print('-');
        break;
      case 19:////C

        section = true;
        type = 3;
        Serial.print('*');
        break;
      case 20:////D

        section = true;
        type = 4;
        Serial.print('/');
        break;
      case -6:////*

        section = false;
        type = 0;
        Serial.println(' ');
        break;

      case -13://///#
        Serial.print(" = ");
        switch (type) {
          case 1:
            result = (firstNumber + secondNumber);
            break;
          case 2:
            result = (firstNumber - secondNumber);
            break;
          case 3:
            result = (firstNumber * secondNumber);
            break;
          case 4:
            result = (firstNumber / secondNumber);
            break;
        }
        type = 0;
        Serial.println(result);
        firstNumber = 0;
        secondNumber = 0;
        section = false;
        break;

    }
  }
}

```

## شرح کد :
1. تعریف متغیرها و تنظیمات اولیه
تعریف تعداد ردیف و ستون کیپد .
تعریف متغیرهای firstNumber و secondNumber برای ذخیره مقادیر عددی که از کیپد خوانده میشوند .
متغیر type برای ذخیره نوع عملیات ریاضی )جمع، تفریق، ضرب و تقسیم( .
مقداردهی اولیه برای کلیدهای کیپد و تعریف پینهای اتصال .
2. بخش setup
تنظیم ارتباط سریال با سرعت 9600 برای ارتباط با کامپیوتر .
3. بخش loop
خواندن کلید فشردهشده از کیپد .
بررسی اینکه کلید فشردهشده عددی است یا مربوط به یکی از عملیات ریاضی (A, B, C, D).
ذخیره عدد به عنوان firstNumber یا secondNumber بستگی به وضعیت section.
انجام عملیات ریاضی در صورت فشردن کلید #.
نمایش نتیجه محاسبات در Serial Monitor.
## مکانیزم کلی کد :
1 . کلیدهای عددی (0 تا 9) به ترتیب در Serial Monitor نمایش داده میشوند .
2 . با فشردن کلید A جمع (+) ، کلید B تفریق (-) ، کلید C ضرب (*) و کلید D تقسیم (/) انتخاب میشوند .
3 . کلید # به عنوان اقدام برای محاسبه نتیجه در نظر گرفته میشود و نتیجه محاسبات در Serial Monitor نمایش داده
میشود .
4 . با فشردن کلید * ، حالت ذخیره عدد تغییر میکند و مقادیر صفر میشوند .
نتایج اجرای کد :
1 . نمایش کلیدهای فشردهشده در Serial Monitor.
2 . با فشردن کلید # نتیجه محاسبات نمایش داده میشود .
 مثال: عدد اول 5 و عدد دوم 3 با فشردن کلید A جمع شده و 8 در Serial Monitor نمایش داده میشود .
## نتیجه گیری
با استفاده از کد و سختافزار مناسب، ماشین حساب سادهای ایجاد شد که میتواند چهار عمل ریاضی )جمع، تفریق، ضرب و تقسیم(
را با فشردن کلیدها از طریق کیپد انجام دهد و نتایج را در Serial Monitor نمایش دهد .
