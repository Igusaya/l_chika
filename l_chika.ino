void setup() {
    pinMode(17, OUTPUT); // デジタルピン17を出力モードに設定
}

void loop() {
    digitalWrite(17, HIGH); // LEDをON
    delay(1000);            // 1秒間待機
    digitalWrite(17, LOW);  // LEDをOFF
    delay(1000);            // 1秒間待機
}
