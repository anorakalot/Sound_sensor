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

//delay variables
int ascend_descend_delay = 50;
int beats_delay = 50;
int bell_delay = 1000;



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
  Serial.println("Which alarm do you wnat?");
  Serial.println("1. Ascending 2. Descending 3. Single Low  4. Single High 5.Single Mid 6. Beats 7. Beats_2 ");
  Serial.println("8.Bells 9.Bells_2");
  Serial.println();
  Serial.println("If you want to go back to change your music selection just press 9 during the program running!");
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
  delay(ascend_descend_delay);
  }
//end of ascending function
}

void descending(){
 for(int x = myarraysize; x >= 0; --x){
  tone(3,myarray[x]);
  delay(ascend_descend_delay);
 }
//end of descending function
}

void single_low(){
  tone(3,myarray[0]);
}

void single_high(){
  tone(3,myarray[20]);
}

void single_mid(){
  tone(3,myarray[10]);
}

void beats(){
  tone(3,myarray[10]);
  delay(beats_delay);
  tone(3,myarray[5]);
  delay(beats_delay);
  tone(3,myarray[7]);
  delay(beats_delay);
  tone(3,myarray[3]);
  delay(beats_delay);
}

void beats_2(){
  tone(3,myarray[3]);
  delay(beats_delay);
  tone(3,myarray[5]);
  delay(beats_delay);
  tone(3,myarray[7]);
  delay(beats_delay);
  tone(3,myarray[10]);
  delay(beats_delay);
}

void bells(){
  tone(3,myarray[20]);
  delay(bell_delay);
  tone(3,myarray[10]);
  delay(bell_delay);
  tone(3,myarray[0]);
  delay(bell_delay);
}

void bells_2(){
  tone(3,myarray[0]);
  delay(bell_delay);
  tone(3,myarray[10]);
  delay(bell_delay);
  tone(3,myarray[20]);
  delay(bell_delay);
}



//end of music selections
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
    else if(input == '5'){
      single_mid();
    }
    else if (input == '6'){
      beats();
    }
    else if (input == '7'){
      beats_2();
    }
    else if (input == '8'){
      bells();
    }
    else if (input == '9'){
      bells_2();
    }

   
    else{
      ascending();
    }
  //end of distance alarm if conditions
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
