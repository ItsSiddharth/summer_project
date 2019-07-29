const int leftForward = D5;
const int leftBackward = D4;
const int rightForward = D0;
const int rightBackward = D2;


void setup() {
  // put your setup code here, to run once:
  pinMode(leftForward,OUTPUT);
  pinMode(leftBackward,OUTPUT);
  pinMode(rightForward,OUTPUT);
  pinMode(rightBackward,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(leftForward,HIGH);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightForward,HIGH);
  digitalWrite(rightBackward,LOW);

  delay(1000);

  // run left
  /*digitalWrite(leftForward,LOW);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightForward,HIGH);
  digitalWrite(rightBackward,LOW);

  delay(1000);
  
  // run forward
  digitalWrite(leftForward,HIGH);
  digitalWrite(leftBackward,LOW);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBackward,LOW);

  delay(1000);
  
  // run backward
  digitalWrite(leftForward,LOW);
  digitalWrite(leftBackward,HIGH);
  digitalWrite(rightForward,LOW);
  digitalWrite(rightBackward,HIGH);

  delay(1000);*/
}
