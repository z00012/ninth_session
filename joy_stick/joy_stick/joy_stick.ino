const int sw = 2;
const int x = 0;
const int y = 1;
void setup() {
  pinMode(sw, INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("switch: ");
  Serial.print(digitalRead(sw));
  Serial.print("\t\t");
  Serial.print("VRx:  ");
  Serial.print(analogRead(x));
   Serial.print("\t\t");
  Serial.print("VRy: ");
  Serial.print(analogRead(y));
  Serial.println("_______");
  delay(500);



}
