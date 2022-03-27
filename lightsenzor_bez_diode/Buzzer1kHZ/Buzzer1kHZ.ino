const int buzzer = 9;

void setup(){
 
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){

  int HZ = 50;
  
  for(int x = 1; x < 1000; x++){
    tone(buzzer, HZ * x );
    delay(1500);   
    noTone(buzzer);
    delay(500);
  }  
  
}
