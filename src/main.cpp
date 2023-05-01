#include <Arduino.h>

// LEDを制御するためのピン番号
const byte LED_PINS[] = {2, 3, 4, 5, 6, 7, 8, 9};

// LEDのピン番号を定義
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

// ピン11の状態を保存する変数
int pin11State = LOW;

// LED点滅のための変数
unsigned long previousMillis = 0; // 前回LEDが点滅した時間
const long interval = 500;        // LEDの点滅周期

void setup()
{
  // 各LEDのピンをOUTPUTに設定
  for (int i = 0; i < 9; i++)
  {
    pinMode(LED_PINS[i], OUTPUT);
    pinMode(ledPins[i], OUTPUT);
  }

  pinMode(11, INPUT); // ピン11を入力モードに設定する
  Serial.begin(9600); // シリアル通信の初期化
}

void loop()
{
  int buttonState = digitalRead(11); // ピン11の状態を読み取る
  Serial.println(buttonState);       // 状態をシリアルモニタに出力する

  // ピン11がHighになった場合
  if (buttonState == HIGH)
  {
    for (int i = 0; i < 9; i++)
    {
      digitalWrite(LED_PINS[i], HIGH); // LEDを点灯させる
    }
    delay(500); // 0.5秒待つ
    for (int i = 0; i < 9; i++)
    {
      digitalWrite(LED_PINS[i], LOW); // LEDを消灯させる
    }
    delay(500);
  }
  else
  {                                         // Lowになった場合
    unsigned long currentMillis = millis(); // 現在の時間を取得する
    if (currentMillis - previousMillis >= interval)
    {                                 // interval時間経過した場合
      previousMillis = currentMillis; // 前回LEDが点滅した時間を更新する
      // LEDを交互に点滅させるプログラムを実行する
      int speed = analogRead(A0);
      for (int i = 0; i < 9; i++)
      {
        digitalWrite(ledPins[i], HIGH);
        delay(speed);
        digitalWrite(ledPins[i], LOW);
      }
    }
  }
}