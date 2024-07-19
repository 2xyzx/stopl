const int pirPin = 7;
const int buzzer = 8;
const int laserPin = 13;
const int ldrPin = A0; 
int pir = LOW; // PIR 초기상태
int ldrValue = 250; // LDR 임계값, 환경에 따른 조정 가능

float tones[]={262,293,329,349,392,440,493,523};

void setup() {
  Serial.begin(9600);
  pinMode(pirPin,INPUT);
  pinMode(laserPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop() { // 실행시 계속 반복 
  pir = digitalRead(pirPin); // PIR 상태를 읽어 저장
  int ldr = analogRead(ldrPin); // 조도센서 값을 읽어 저장

  Serial.print("ldr=");
  Serial.println(ldr);
  delay(1000);

  if(pir == HIGH) { // PIR 인체 감지
    digitalWrite(laserPin, HIGH); // 레이저 켜기
    delay(1000); // 1초 대기

    if(ldr < ldrValue) { // 접촉
	    Serial.println("Come in"); 
    	tone(buzzer, 262, 500);
    	delay(100);
  	  noTone(buzzer); // 재생 중지
    }

    else { // 비접촉
      Serial.println("OK"); 
      digitalWrite(laserPin, LOW); // 레이저 끄기
    }
  }     

  else { // PIR 인체 감지 없음
    digitalWrite(laserPin, LOW); // 레이저 끄기
  } 

  delay(10); // 갱신시간
}