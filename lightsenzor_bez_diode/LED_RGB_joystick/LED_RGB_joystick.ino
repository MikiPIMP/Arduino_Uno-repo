 const int PUSHBUTTON_PIN = 2;  
 const int RED_PIN = 11;  
 const int GREEN_PIN = 10;  
 const int BLUE_PIN = 9;  
 const int redX = 512;  
 const int redY = 1023;  
 const int greenX = 1023;  
 const int greenY = 0;  
 const int blueX = 0;  
 const int blueY = 0;
  
 void setup() {
  Serial.begin(9600);  
  // Set the Joystick button as an input  
  pinMode(PUSHBUTTON_PIN, INPUT);  
  digitalWrite(PUSHBUTTON_PIN, HIGH);  
  pinMode(RED_PIN, OUTPUT);  
  pinMode(GREEN_PIN, OUTPUT);  
  pinMode(BLUE_PIN, OUTPUT);  
 }  
 
 void loop() { 
   
  int xAxis = analogRead(A0);  
  int yAxis = analogRead(A1);  
  
  // Flip orientation (if needed)  
  xAxis = map(xAxis, 0, 1023, 0, 1023);  
  yAxis = map(yAxis, 0, 1023, 1023, 0); 
   
  int distanceRed = sqrt(pow(abs(redX - xAxis), 2) + pow(abs(redY - yAxis), 2));  
  int distanceGreen = sqrt(pow(abs(greenX - xAxis), 2) + pow(abs(greenY - yAxis), 2));  
  int distanceBlue = sqrt(pow(abs(blueX - xAxis), 2) + pow(abs(blueY - yAxis), 2));  
  int brightRed = 255 - constrain(map(distanceRed, 0, 1023, 0, 255), 0, 255);  
  int brightGreen = 255 - constrain(map(distanceGreen, 0, 1023, 0, 255), 0, 255);  
  int brightBlue = 255 - constrain(map(distanceBlue, 0, 1023, 0, 255), 0, 255);
    
  if (digitalRead(PUSHBUTTON_PIN) == 0) {  
   brightRed = 255;  
   brightGreen = 255;  
   brightBlue = 255;  
  }
  
  analogWrite(RED_PIN, brightRed);  
  analogWrite(GREEN_PIN, brightGreen);  
  analogWrite(BLUE_PIN, brightBlue);
    
  Serial.print("KEY: ");  
  Serial.print(digitalRead(PUSHBUTTON_PIN));  
  Serial.print(", X: ");  
  Serial.print(xAxis);  
  Serial.print(", Y: ");  
  Serial.print(yAxis);  
  Serial.print(", R: ");  
  Serial.print(brightRed);  
  Serial.print(", G: ");  
  Serial.print(brightGreen);  
  Serial.print(", B: ");  
  Serial.print(brightBlue);  
  Serial.println("\n");
    
  delay(100);
  
 }
