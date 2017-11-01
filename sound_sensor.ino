#define trig_pin 13
#define echo_pin 12
#define led 7

//LED GOES ON WHEN DISTANCE IS LESS THAN 20
//YOU CAN CHECK EXACT DISTANCE IN THE SERIAL MONITOR AS WELL
void setup() {
Serial.begin(9600);
pinMode(trig_pin,OUTPUT);
pinMode(echo_pin,INPUT);
pinMode(led,OUTPUT);
}

void loop() {
  long duration;
  long distance;
  digitalWrite(trig_pin,LOW);
  delay(10);
  digitalWrite(trig_pin,HIGH);
  delay(10);
  digitalWrite(trig_pin,LOW);
  duration = pulseIn(echo_pin,HIGH);
  distance = (duration/2) / 29.1;
  Serial.println(distance);
  if (distance<20){
    digitalWrite(led,HIGH);
  }
  else{
    digitalWrite(led,LOW);
  }
}
