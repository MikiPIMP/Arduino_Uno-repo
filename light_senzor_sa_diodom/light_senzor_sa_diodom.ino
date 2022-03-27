// constants won't change
const int LIGHT_SENSOR_PIN = A0;
const int LED_PIN          = 3;
const int ANALOG_THRESHOLD = 10;

int analogValue;

void setup() {
  pinMode(LED_PIN, OUTPUT); 
}

void loop() {
  analogValue = analogRead(LIGHT_SENSOR_PIN); 
  if(analogValue < ANALOG_THRESHOLD)
    digitalWrite(LED_PIN, LOW);
  else
    digitalWrite(LED_PIN, HIGH);
}
