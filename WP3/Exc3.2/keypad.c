#define ROW1 11
#define ROW2 10
#define ROW3 9
#define ROW4 8
#define COLUMN1 7
#define COLUMN2 6
#define COLUMN3 5
#define COLUMN4 4

int oneSec = 1000;

void setup() {
  Serial.begin(9600);
  
  pinMode(ROW1, OUTPUT);
  pinMode(ROW2, OUTPUT);
  pinMode(ROW3, OUTPUT);
  pinMode(ROW4, OUTPUT);
  
  pinMode(COLUMN1, INPUT);
  pinMode(COLUMN2, INPUT);
  pinMode(COLUMN3, INPUT);
  pinMode(COLUMN4, INPUT);

}

void loop() {
  row1();
  row2();
  row3();
  row4();
  
}


void row1(){
  digitalWrite(ROW1, LOW);
  digitalWrite(ROW2, HIGH);
  digitalWrite(ROW3, HIGH);
  digitalWrite(ROW4, HIGH);
  
  if(digitalRead(COLUMN1) == LOW){
    Serial.print("1");
    delay(oneSec);
  } else if(digitalRead(COLUMN2) == LOW){
    Serial.print("2");
    delay(oneSec);
  } else if(digitalRead(COLUMN3) == LOW){
    Serial.print("3");
    delay(oneSec);
  } else if(digitalRead(COLUMN4) == LOW){
    Serial.print("A");
    delay(oneSec);
  }
  
}

void row2(){
  digitalWrite(ROW1, HIGH);
  digitalWrite(ROW2, LOW);
  digitalWrite(ROW3, HIGH);
  digitalWrite(ROW4, HIGH);
  
  if(digitalRead(COLUMN1) == LOW){
    Serial.print("4");
    delay(oneSec);
  } else if(digitalRead(COLUMN2) == LOW){
    Serial.print("5");
    delay(oneSec);
  } else if(digitalRead(COLUMN3) == LOW){
    Serial.print("6");
    delay(oneSec);
  } else if(digitalRead(COLUMN4) == LOW){
    Serial.print("B");
    delay(oneSec);
  }
  
}

void row3(){
  digitalWrite(ROW1, HIGH);
  digitalWrite(ROW2, HIGH);
  digitalWrite(ROW3, LOW);
  digitalWrite(ROW4, HIGH);
  
  if(digitalRead(COLUMN1) == LOW){
    Serial.print("7");
    delay(oneSec);
  } else if(digitalRead(COLUMN2) == LOW){
    Serial.print("8");
    delay(oneSec);
  } else if(digitalRead(COLUMN3) == LOW){
    Serial.print("9");
    delay(oneSec);
  } else if(digitalRead(COLUMN4) == LOW){
    Serial.print("C");
    delay(oneSec);
  }
  
}

void row4(){
  digitalWrite(ROW1, HIGH);
  digitalWrite(ROW2, HIGH);
  digitalWrite(ROW3, HIGH);
  digitalWrite(ROW4, LOW);
  
  if(digitalRead(COLUMN1) == LOW){
    Serial.print("*");
    delay(oneSec);
  } else if(digitalRead(COLUMN2) == LOW){
    Serial.print("0");
    delay(oneSec);
  } else if(digitalRead(COLUMN3) == LOW){
    Serial.print("#");
    delay(oneSec);
  } else if(digitalRead(COLUMN4) == LOW){
    Serial.print("D");
    delay(oneSec);
  }
  
}
