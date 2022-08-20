int rf=4;
int rb=5;
int lf=6;
int lb=7;

int trig_1=11;
int echo_1=10;

int trig_2=12;
int echo_2=13;

int min_side=30, fwd_side_dist=20;


int rotation_time=960*9/13;

void setup() {
  pinMode(rf,OUTPUT);
  pinMode(rb,OUTPUT);
  pinMode(lf,OUTPUT);
  pinMode(lb,OUTPUT);

  pinMode(trig_1,OUTPUT);
  pinMode(trig_2,OUTPUT);

  pinMode(echo_1,INPUT);
  pinMode(echo_2,INPUT);
}

float dist(int trigPin, int echoPin){
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  double duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  float distance = duration * 0.034 / 2;
  return distance;
}

void fwd_toggle(bool n){
  digitalWrite(rf,n);
  digitalWrite(lf,n);
}


void rt(){
  digitalWrite(rb,1);
  digitalWrite(lf,1);
  delay(rotation_time);
  digitalWrite(rb,0);
  digitalWrite(lf,0);
}


void lt(){
  digitalWrite(rf,1);
  digitalWrite(lb,1);
  delay(rotation_time);
  digitalWrite(rf,0);
  digitalWrite(lb,0);
}

void loop() {
  if (dist(trig_2,echo_2)>min_side){
    delay(500);
    fwd_toggle(0);
    lt();
    fwd_toggle(1);
    delay(500);
    }
  else if ((dist(trig_2,echo_2)<min_side) and (dist(trig_1,echo_1)>fwd_side_dist)){
    fwd_toggle(1);
  }
  else if (dist(trig_1,echo_1)<fwd_side_dist){
    fwd_toggle(0);
    rt();
  }
  
}
