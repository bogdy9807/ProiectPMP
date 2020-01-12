// Pinii motor 1
#define mpin00 5
#define mpin01 6
// Pinii motor 2
#define mpin10 3
#define mpin11 11

#define controlpin1 A1
#define controlpin2 A2


volatile int up = 0;
volatile int down =0;
volatile int valide = 0;

void setup() {
  Serial.begin(9600);
  digitalWrite(mpin00, 0);
  digitalWrite(mpin01, 0);
  digitalWrite(mpin10, 0);
  digitalWrite(mpin11, 0);
  pinMode (mpin00, OUTPUT);
  pinMode (mpin01, OUTPUT);
  pinMode (mpin10, OUTPUT);
  pinMode (mpin11, OUTPUT);
  pinMode (13,INPUT);
  pinMode (12,INPUT);
  pinMode (A0,INPUT);
}

void loop(){
  down = digitalRead(controlpin1); //13
  up = digitalRead(controlpin2);   //12
  valide = digitalRead(A0);
  if(valide == 1){
  if(down == 1 && up == 0){
      StartMotor (mpin00, mpin01, 0, 128);
      StartMotor (mpin10, mpin11, 0, 128);
      delay (500);
      delayStopped(500);
      //down;
   }
   if(up == 1 && down == 1){
    StartMotor (mpin00, mpin01, 1, 128);
    StartMotor (mpin10, mpin11, 1, 128);
    delay (500);
    delayStopped(500);
    //up;
   }
   if(up == 0 && down == 0){
    StartMotor (mpin00, mpin01, 0, 128);
    StartMotor (mpin10, mpin11, 1, 128);
    delay (500);
    delayStopped(500);
    //right;
   }
   if(up == 1 && down == 0){
    StartMotor (mpin00, mpin01, 1, 128);
    StartMotor (mpin10, mpin11, 0, 128);
    delay (500);
    delayStopped(500);
    //left;
   }
  }
}

void StartMotor (int m1, int m2, int forward, int speed)
{
  if (speed==0) // oprire
  {
    digitalWrite(m1, 0);
    digitalWrite(m2, 0);
  }
  else
  {
    if (forward)
    {
      digitalWrite(m2, 0);
      analogWrite(m1, speed); // folosire PWM
    }
    else
    {
       digitalWrite(m1, 0);
       analogWrite(m2, speed);
    }
  }
}

void delayStopped(int ms)
{
  StartMotor (mpin00, mpin01, 0, 0);
  StartMotor (mpin10, mpin11, 0, 0);
  delay(ms);
}
