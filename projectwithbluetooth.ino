const int tr1=3;//trigger 1 ultrasonic sensor left
const int tr2=5;//trigger 2 ultrasonic sensor front
const int tr3=7;//trigger 3 ultrasonic sensor right
const int ec1=4;//echo 1 ultrasonic sensor left
const int ec2=6;//echo 2 ultrasonic sensor front
const int ec3=8;//echo 3 ultrasonic sensor right
int rotationtime;//90 deg turn
int correctiontime;//time to correct i.e back to straight path
int fmdist;//front min distance
int smdist;//side min distance
int sfrdist;//side free distance
long du1;//distance of ultrasonic sensor 1
long du2;//distance of ultrasonic sensor 2
long du3;//distance of ultrasonic sensor 3
long int time1;//time of ultrasonic sensor 1
long int time2;//time of ultrasonic sensor 2
long int time3;//time of ultrasonic sensor 3
char input;//input from bluetooth
char f;//forward
char b;//backward
char r;//right
char l;//left
char s;//stop
char de='m';//decider for autonomous or bluetooth i.e autonomous

void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(4,INPUT);

  pinMode(6,INPUT);
  pinMode(8,INPUT);
  

  
  pinMode(9,OUTPUT);//right front
  pinMode(10,OUTPUT);//leftfront
  pinMode(11,OUTPUT);//right back
  pinMode(12,OUTPUT);//left back
  // put your setup code here, to run once:

}

void loop() {
  if(Serial.available()>0){
    input=Serial.read();
    Serial.println(input);
    if(input=='m'){
      de='m';//make car autonomous
      }
    if(input=='n'){
      de='n';//makes car remote controlled
      }
    if(input=='f' && de=='n'){
    digitalWrite(9,1);//right front 1
    digitalWrite(10,1);//left front 1
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0
      }

    if(input=='b' && de=='n'){
    digitalWrite(9,0);//right front 0
    digitalWrite(10,0);//left front 0
    digitalWrite(11,1);//right back 0
    digitalWrite(12,1);//left back 0
      }

    if(input=='r' && de=='n'){
    digitalWrite(9,0);//right front 0
    digitalWrite(10,1);//left front 1
    digitalWrite(11,1);//right back 1
    digitalWrite(12,0);//left back 0
      }

    if(input=='l' && de=='n'){
    digitalWrite(9,1);//right front 1
    digitalWrite(10,0);//left front 0
    digitalWrite(11,0);//right back 0
    digitalWrite(12,1);//left back 1
      }


    if(input=='s' && de=='n'){
    digitalWrite(9,0);//right front 0
    digitalWrite(10,0);//left front 0
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0
      }
    
    
    
    }






  else if(de=='m'){
  digitalWrite(3,0);//tr1 0
  delayMicroseconds(2);
  digitalWrite(5,0);//tr2 0
  delayMicroseconds(2);
  digitalWrite(7,0);//tr3 0
  delayMicroseconds(2);

  
  digitalWrite(3,1);//tr1 1
  delayMicroseconds(10);
  digitalWrite(3,0);//tr1 0
  time1=pulseIn(ec1,1);//time of ultrasonic sensor 1
  digitalWrite(5,1);//tr2 1
  delayMicroseconds(10);
  digitalWrite(5,0);//tr2 0
  time2=pulseIn(ec2,1);//time of ultrasonic sensor 2
  digitalWrite(7,1);//tr3 1
  delayMicroseconds(10);
  digitalWrite(7,0);//tr3 0
  time3=pulseIn(ec3,1);//time of ultrasonic sensor 3

  du1=time1*.034/2;//distance of ultrasonicsensor 1
  du2=time2*.034/2;//distance of ultrasonicsensor 2
  du3=time3*.034/2;//distance of ultrasonicsensor 3

  if(du1<smdist && du2>fmdist){
   digitalWrite(9,0);//right front 0
    digitalWrite(10,1);//left front 1
    digitalWrite(11,1);//right back 1
    digitalWrite(12,0);//left back 0
    delay(correctiontime);
    digitalWrite(9,1);//right front 1
    digitalWrite(10,1);//left front 1
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0 

    
  }
  if(du3<smdist && du2>fmdist){
   digitalWrite(9,1);//right front 1
    digitalWrite(10,0);//left front 0
    digitalWrite(11,0);//right back 0
    digitalWrite(12,1);//left back 1
    delay(correctiontime);
    digitalWrite(9,1);//right front 1
    digitalWrite(10,1);//left front 1
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0 

    
  }


  

  if(du1>sfrdist){
    digitalWrite(9,1);//right front 1
    digitalWrite(10,0);//left front 0
    digitalWrite(11,0);//right back 0
    digitalWrite(12,1);//left back 1
    delay(rotationtime);
    digitalWrite(9,1);//right front 1
    digitalWrite(10,1);//left front 1
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0
    delay(rotationtime);//so that it goes forward
    }

   else if(du2>fmdist){
    
    digitalWrite(9,1);//right front 1
    digitalWrite(10,1);//left front 1
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0
    
    }

   else if(du3>sfrdist){

    digitalWrite(9,0);//right front 0
    digitalWrite(10,1);//left front 1
    digitalWrite(11,1);//right back 1
    digitalWrite(12,0);//left back 0
    delay(rotationtime);
    digitalWrite(9,1);//right front 1
    digitalWrite(10,1);//left front 1
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0
    
    }
   else if(du3<fmdist && du1<fmdist && du2<fmdist){

    digitalWrite(9,0);//right front 0
    digitalWrite(10,1);//left front 1
    digitalWrite(11,1);//right back 1
    digitalWrite(12,0);//left back 0
    delay(rotationtime);//180 deg turn
    delay(rotationtime); 
    digitalWrite(9,1);//right front 1
    digitalWrite(10,1);//left front 1
    digitalWrite(11,0);//right back 0
    digitalWrite(12,0);//left back 0
    
    }

  }
  




}
