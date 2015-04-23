/*
  PIR("Passive Infrared Sensor") Motion Sensor,
 紅外線動作感測器, 或稱人體紅外線感測器
 */
//led

int brightness = 0;
int fadeAmount = 5;          // 漸變程度
int delayDuration = 60;      // 漸變間隔
const int PIRSensor = 2;     // 紅外線動作感測器連接的腳位
const int ledPin =  13;      // LED 腳位
int sensorValue = 0;         // 紅外線動作感測器訊號變數

void setup() {
  pinMode(PIRSensor, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(9, HIGH);
}


void loop() {
  // 讀取 PIR Sensor 的狀態
  sensorValue = digitalRead(PIRSensor);
  // 判斷 PIR Sensor 的狀態
  if (sensorValue == HIGH) {
    digitalWrite(ledPin, HIGH);  // 有人，開燈
  }
  else {
    digitalWrite(ledPin, LOW);   // 沒人，關燈
    brightness = 0;
  }

  //判斷感應狀況, true =>開始漸變
  if (sensorValue) {
    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount ;
    }
  } else {
    brightness = 0;
  }
  // 限制亮度數值在0~255
  brightness =  constrain(brightness, 0, 255);
  // led 亮的程度
  analogWrite(9, brightness);
  // 延遲時間
  delay(delayDuration);

}
