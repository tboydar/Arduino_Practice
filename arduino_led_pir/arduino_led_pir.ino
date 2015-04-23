/*
  PIR("Passive Infrared Sensor") Motion Sensor,
 紅外線動作感測器, 或稱人體紅外線感測器
 */


//led

int brightness = 0;
int fadeAmount = 5;
int delayDuration = 60;



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

  if (sensorValue) {

    brightness = brightness + fadeAmount;
    if (brightness <= 0 || brightness >= 255) {
      fadeAmount = -fadeAmount ;
    }
  }
  brightness =  constrain(brightness, 0, 255);

  analogWrite(9, brightness);

  delay(delayDuration);

}
