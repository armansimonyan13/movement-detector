int ms0 = 0;
int ms1 = 1;
int ms2 = 2;
int sw = 3;
int ls = A2;
bool isOn = false;
int timer = 0;
unsigned long previousMillis = 0;

void setup() {
  pinMode(ms0, INPUT);
  pinMode(ms1, INPUT);
  pinMode(ms2, INPUT);
  pinMode(sw, OUTPUT);
  pinMode(ls, INPUT);
  Serial.begin(57600);
  while(!Serial) {
    ;
  }
  Serial.println("ok");
}

void loop() {
  if (isOn) {
    if (timer >= 0) {
      int diffMillis = millis() - previousMillis;
      timer -= diffMillis;
    }
    if (timer < 0) {
      isOn = false;
    }
  } else {
    int msValue0 = digitalRead(ms0);
    int msValue1 = digitalRead(ms1);
    int msValue2 = digitalRead(ms2);
    if (msValue0 == HIGH || msValue1 == HIGH || msValue2 == HIGH) {
      isOn = true;
      timer = 10000;
      previousMillis = millis();
    }
  }

  digitalWrite(sw, isOn);
  print();
}

void print() {
  Serial.print("isOn: ");
  Serial.println(isOn);
  Serial.print("timer: ");
  Serial.println(timer);
  Serial.print("previousMillis: ");
  Serial.println(previousMillis);
}



//
//void loop() {
//  val = analogRead(analogPin);
//
//  if (val < 200) {
//    digitalWrite(pin, HIGH);
//  } else {
//    digitalWrite(pin, LOW);
//  }
//}

//
//void loop() {
//  long currentMillis = millis();
//  if (currentMillis - previousMillis > 2000) {
//    previousMillis = currentMillis;
//
//    isOn = !isOn;
//
//    if (isOn) {
//      digitalWrite(pin, HIGH);
//    } else {
//      digitalWrite(pin, LOW);
//    }
//  }
//}
