 volatile int state = -1;
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(10, OUTPUT);
  Serial1.begin(38400); // Default communication rate of the Bluetooth module
  Serial.begin(9600);
}
void loop() {
  //19:7:1a16

  digitalWrite(11, LOW);
 if(Serial.available() > 0){ // Checks whether data is comming from the serial port
      state = Serial.read(); // Reads the data from the serial port

//    if(Serial.available())
//      Serial1.write(Serial.read());
//
//    if(Serial1.available())
//      Serial.write(Serial1.read());
 // Controlling the servo motor
 if(state == 0){
      digitalWrite(12,HIGH);
      digitalWrite(13,HIGH);
      digitalWrite(10,HIGH);
      //down
   }
   if(state == 1){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(10,HIGH);
    //up
   }
   if(state == 2){
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    digitalWrite(10,HIGH);
    //right
   }
   if(state == 3){
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
    digitalWrite(10,HIGH);
    //left
   }
  } 
}
