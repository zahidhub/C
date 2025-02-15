#define TEMP_PIN A0

void setup()
{
  Serial.begin(9600);
  pinMode(TEMP_PIN, INPUT);
}

void loop()
{
  float temp = analogRead(TEMP_PIN);
  
  float volt = (temp) * 4.9;
  temp = (volt - 500)/10;
  
  
  Serial.println("Voltage: ");
  Serial.println(volt);
  Serial.println("Temp C: ");
  Serial.println(temp);
  delay(500);
  
}