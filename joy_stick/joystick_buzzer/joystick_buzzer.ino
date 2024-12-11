const int sw = 2;
const int x =A0;
const int y =A1;
const int buzzer=10;
void setup() {
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);
  pinMode(x, INPUT);
 pinMode(y, INPUT);
 pinMode(buzzer,OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("switch: ");
  Serial.print(digitalRead(sw));
  Serial.print("\t\t");
  Serial.print("VRx:  ");
 
  if (analogRead(y)>1000) {
    Serial.print("right");
    tone(buzzer,1000);
    delay(1000);
    noTone(buzzer);
    delay(1000);

  }
  else if (analogRead(y)<259&& 498<x<520) {
    Serial.print("left");
     tone(buzzer,7000);
    delay(1000);
    noTone(buzzer);
    delay(1000);
   
  }
 

  Serial.print("\t\t");
  Serial.print("VRy: ");
  
  if (analogRead(x)>800) {
    Serial.print("up");
    

  }
  else if (analogRead(x)<259) {
    Serial.print("down");
  }
  
  Serial.println("_______");
  
  delay(500);



}
