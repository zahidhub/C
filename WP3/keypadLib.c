#include <Keypad.h>

#define ROW1 11
#define ROW2 10
#define ROW3 9
#define ROW4 8
#define COLUMN1 7
#define COLUMN2 6
#define COLUMN3 5
#define COLUMN4 4

const int rows = 4;
const int colums = 4;
int oneSec = 1000;

char keys[rows][colums] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPin[rows] = {ROW1, ROW2, ROW3, ROW4};
byte columnPin[colums] = {COLUMN1, COLUMN2, COLUMN3, COLUMN4};

Keypad keypad = Keypad(makeKeymap(keys), rowPin, columnPin, rows, colums);

void setup() {
  Serial.begin(9600);

}

void loop() {
  
  char pressedKey = keypad.getKey();
  
  if (pressedKey){
    Serial.print(pressedKey);
  }
}