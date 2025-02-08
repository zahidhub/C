#define RED_PIN 2
#define GREEN_PIN 4
#define YELLOW_PIN 7

#define DHT_TEMPPIN A0
#define DHT_PHOTOPIN A1

int periodicity = 1000;


void setup()
{
  Serial.begin(115200);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  
}

void loop()
{
  
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  
  int tempVal = analogRead(DHT_TEMPPIN);
  //convert the ADC reading to voltage
  float voltage = (tempVal/1024.0) * 5.0;
  
  // convert the voltage to temperature in degrees
  float temperature = (voltage - .5) * 100;
  
  
  int photoSen = analogRead(DHT_PHOTOPIN);
  int perPhoto = map(photoSen, 1017, 344, 0, 100);
  
  if((perPhoto <= 100 && perPhoto >=61)){
    if(temperature >= 21){
      digitalWrite(GREEN_PIN, HIGH);
    }else if (temperature < 21){
      digitalWrite(YELLOW_PIN, HIGH);
    }
  }
  
  if((perPhoto <= 60 && perPhoto >=21)){
    if(temperature <= 20 && temperature >= 0){
      digitalWrite(GREEN_PIN, HIGH);
    } else if (temperature > 21){
      digitalWrite(RED_PIN, HIGH);
    } else if (temperature < 0){
      digitalWrite(YELLOW_PIN, HIGH);
    }
  }
  
  if((perPhoto <= 20 && perPhoto >=1)){
    if(temperature <= 0 && temperature >= -12){
      digitalWrite(GREEN_PIN, HIGH);
    } else if (temperature > 0){
      digitalWrite(RED_PIN, HIGH);
    } else if (temperature < -12){
      digitalWrite(YELLOW_PIN, HIGH);
    }
    
  } 
  
  if(perPhoto == 0){
    if(temperature < -12){
      digitalWrite(GREEN_PIN, HIGH);
    } else if (temperature > -12){
      digitalWrite(RED_PIN, HIGH);
    }
    
  } 
  
  Serial.println("Photoresistor: ");
  Serial.println(perPhoto);
  Serial.print("degrees C: ");
  Serial.println(temperature);
  delay(periodicity);
  
}