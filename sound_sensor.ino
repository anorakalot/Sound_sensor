/*add more music options and serial available to choose each one*/

#define trig_pin 13
#define echo_pin 12
#define led_1 7
#define led_2 6
#define piezo 3

//GLOBAL VARIABLES
int myarray[] = {0,50,100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000};
short myarraysize = 21;
char input;
char  goback_input;


//MAKE SURE YOU UPDATE myarraysize WHEN YOU CHANGE MYARRAY ELEMENTS SIZE

//LED GOES ON WHEN DISTANCE IS LESS THAN 20
//YOU CAN CHECK EXACT DISTANCE IN THE SERIAL MONITOR AS WELL

void setup() {
  Serial.begin(9600);
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(led_1,OUTPUT);
  pinMode(led_2,OUTPUT);
  pinMode(piezo,OUTPUT);
  //inputs for music selection
  Serial.println("Welcome to the Security Program");
  Serial.println("Which music do you wnat?");
  Serial.println("1. Ascending 2. Descending 3. Single Low  4. Single High");
  Serial.println();
  Serial.println("If you want to go back to change your music selection just press 9 during the program!");
  input = NULL;
  while(input == NULL){ //|| input != '1' || input != '2'){
  if(Serial.available() > 0){
    input = Serial.read();
    delay(500);
    //end of input reading in loop
    }
    /*
   if (input != '1' || input != '2'){
    input = NULL;
    Serial.println("Wrong Input!");
    //end of wrong input checker
   }
   */
  //end of while loop
  }
  //end of setup function
}

void ascending(){
for (int x = 0; x < myarraysize; ++x){
  tone(3,myarray[x]);
  delay(50);
  }
//end of ascending function
}

void descending(){
 for(int x = myarraysize; x >= 0; --x){
  tone(3,myarray[x]);
  delay(50);
 }
//end of descending function
}

void single_low(){
  tone(3,myarray[0]);
}

void single_high(){
  tone(3,myarray[20]);
}
void nomusic(){
  noTone(3);
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

  if (distance<30){
    digitalWrite(led_1,HIGH);
    digitalWrite(led_2,HIGH);
    if (input == '1'){
      ascending();
      //end of choice ascending
    }
    else if(input == '2'){
      descending();
      //end of choice descending
    }
    else if(input == '3'){
      single_low();
    }
    else if(input == '4'){
      single_high();
    }
    else{
      ascending();
    }
  //end of distance alarm condition
   }
   
  else{
    digitalWrite(led_1,LOW);
    digitalWrite(led_2,LOW);
    nomusic();
    //end of no alarm else statement
  }
if (Serial.available()> 0){
    goback_input = Serial.read();
    delay(500);

if (goback_input == '9'){
  setup();
  }
}
//end of go back input checker
}
