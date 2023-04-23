#include <Arduino.h>

// LEDのピン番号を定義
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

// 可変抵抗器のピン番号を定義
int potPin = A0;

void setup()
{
  // 各LEDのピンをOUTPUTに設定
  for (int i = 0; i < 9; i++)
  {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop()
{
  // 可変抵抗器からの入力値を取得
  int speed = analogRead(potPin);
  // LEDを交互に点滅させる
  for (int i = 0; i < 9; i++)
  {
    digitalWrite(ledPins[i], HIGH); // LEDを点灯
    delay(speed);                   // 可変抵抗器の値に応じて待機時間を設定
    digitalWrite(ledPins[i], LOW);  // LEDを消灯
  }
}