#define LED1_PIN 5
#define LED2_PIN 4
#define LED3_PIN 3
#define LED4_PIN 2

#define SOUND_PIN 9
#define ULT_SON_PIN 7

#define MAX_DIST 200
#define MIN_DIST 25

int reflectionTIme;
int cm;
int piezoReading;


void setup()
{
  Serial.begin(9600);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  pinMode(LED3_PIN, OUTPUT);
  pinMode(LED4_PIN, OUTPUT);
  
  pinMode(SOUND_PIN, OUTPUT);
  
}

void loop()
{
  ledControl();
}


void ledControl(){
  int distance = ultraSonic();
  
  digitalWrite(SOUND_PIN, LOW);
  
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  digitalWrite(LED3_PIN, LOW);
  digitalWrite(LED4_PIN, LOW);
  
  if(distance <= 30 && distance > MIN_DIST){
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    digitalWrite(LED4_PIN, HIGH);
    
    soundSensor();
    soundSensor();
    soundSensor();
    soundSensor();
  } else if (distance <= 80){
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    digitalWrite(LED3_PIN, HIGH);
    
    soundSensor();
    soundSensor();
    soundSensor();
  } else if (distance <= 140){
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    
    soundSensor();
    soundSensor();
  } else if (distance <= MAX_DIST){
    
    digitalWrite(LED1_PIN, HIGH);
    soundSensor();
  }
  
  //Serial.println(distance);
  
}

void soundSensor(){
  digitalWrite(SOUND_PIN, HIGH);
}


int ultraSonic(){
  
  pinMode(ULT_SON_PIN, OUTPUT);
  
  digitalWrite(ULT_SON_PIN, LOW);
  delay(2);
  digitalWrite(ULT_SON_PIN, HIGH);
  delay(10);
  digitalWrite(ULT_SON_PIN, LOW);
  
  pinMode(ULT_SON_PIN, INPUT);
  
  reflectionTIme = pulseIn(ULT_SON_PIN, HIGH);
  cm = microsecondsToCentimeters(reflectionTIme);
  
  return cm;
  
}

long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}