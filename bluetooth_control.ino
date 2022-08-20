int r1=10;
int r2=11;
int l1=12;
int l2=13;
int trig =3;
int echo=4;
int ir=8;
char de='m';
char input='m';
void setup(){
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(l1,OUTPUT);
  pinMode(l2,OUTPUT);
  pinMode(ir,INPUT);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);
  Serial.begin(9600);
}

float distance(int trig, int echo){
  digitalWrite(trig,1);
  delayMicroseconds(10);
  digitalWrite(trig,0);
  float t1=pulseIn(echo,1);
  return (t1*0.017);
 
}

void follow(int ir){
  if (digitalRead(ir)==1){
    digitalWrite(l1,1);
    delay(200);
    digitalWrite(l1,0);
  }
  else{
    digitalWrite(r1,1);
    delay(200);
    digitalWrite(r1,0);
  }
}
void loop(){
  if (Serial.available()>0){
    input=Serial.read();
    Serial.println(input);
  }
  if (input=='m'){
    de='m';
    
  }
  else if (input=='n'){
    de='n';
  }
  if (de=='m'){
    if (distance(trig,echo)<15){
      digitalWrite(r2,1);
      digitalWrite(l1,1);
      delay(400);
      digitalWrite(l1,0);
      digitalWrite(r2,0);
      
    }
    else{
      follow(ir);
    }
  }
  else if (de=='n'){
    if (input=='f'){
      digitalWrite(r1,1);
      digitalWrite(l1,1);
      digitalWrite(r2,0);
      digitalWrite(l2,0);
      delay(500);
      digitalWrite(r1,0);
      digitalWrite(l1,0);
      digitalWrite(r2,0);
      digitalWrite(l2,0);
      delay(200);
    }
    if (input=='b'){
      digitalWrite(r1,0);
      digitalWrite(l1,0);
      digitalWrite(r2,1);
      digitalWrite(l2,1);
      delay(300);
      digitalWrite(r1,0);
      digitalWrite(l1,0);
      digitalWrite(r2,0);
      digitalWrite(l2,0);
      delay(200);
    }
    if (input=='r'){
      digitalWrite(r1,0);
      digitalWrite(l1,1);
      digitalWrite(r2,1);
      digitalWrite(l2,0);
      delay(100);
      digitalWrite(r1,0);
      digitalWrite(l1,0);
      digitalWrite(r2,0);
      digitalWrite(l2,0);
      delay(200);
    }
    if (input=='l'){
      digitalWrite(r1,1);
      digitalWrite(l1,0);
      digitalWrite(r2,0);
      digitalWrite(l2,1);
      delay(100);
      digitalWrite(r1,0);
      digitalWrite(l1,0);
      digitalWrite(r2,0);
      digitalWrite(l2,0);
      delay(200);
    }
    if (input=='s'){
      digitalWrite(r1,0);
      digitalWrite(l1,0);
      digitalWrite(r2,0);
      digitalWrite(l2,0);
      delay(200);
    }
  }
  
  
}
