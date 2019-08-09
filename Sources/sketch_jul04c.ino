int data = 0;
const int motorA = 8;
const int motorB = 6;
const int PW_motR = 9;
const int motorC = 10;
const int motorD = 5;
const int PW_motL = 11;

void setup() {
  pinMode(motorA, OUTPUT);
  pinMode(motorB, OUTPUT);
  pinMode(motorC, OUTPUT);
  pinMode(motorD, OUTPUT);
  Serial.begin(9600);//シリアル通信開始
}

void loop() {
  if (Serial.available() > 0) {
    data = Serial.read();//シリアル通信で受け取ったデータを読み込む
    // HIGH/LOW 前回転　LOW/HIGH 後回転　LOW/LOW 停止
    if (data == '0') { //停止
      digitalWrite(motorA, LOW);
      digitalWrite(motorB, LOW);
      digitalWrite(motorC, LOW);
      digitalWrite(motorD, LOW);
      Serial.println("stop");
    } else if (data == '1') { //前進
      digitalWrite(motorA, HIGH);
      digitalWrite(motorB, LOW);
      analogWrite(PW_motR,255);
      digitalWrite(motorC, HIGH);
      digitalWrite(motorD, LOW);
      analogWrite(PW_motL,255);
      Serial.println("front");
    } else if (data == '2') { //後退
      digitalWrite(motorA, LOW);
      digitalWrite(motorB, HIGH);
      analogWrite(PW_motR,255);
      digitalWrite(motorC, LOW);
      digitalWrite(motorD, HIGH);
      analogWrite(PW_motL,255);
      Serial.println("back");
      } else if (data == '3') { //右折
      digitalWrite(motorA, HIGH);
      digitalWrite(motorB, LOW);
      analogWrite(PW_motR,25);
      digitalWrite(motorC, HIGH);
      digitalWrite(motorD, LOW);
      analogWrite(PW_motL,255);
      Serial.println("right");
    } else if (data == '4') { //左折
      digitalWrite(motorA, HIGH);
      digitalWrite(motorB, LOW);
      analogWrite(PW_motR,255);
      digitalWrite(motorC, HIGH);
      digitalWrite(motorD, LOW);
      analogWrite(PW_motL,25);
      Serial.println("left");
    }
    delay(50);
  }
}
