#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://nodemcu-4eb31.firebaseio.com/"
#define FIREBASE_AUTH "4KSBSA5ZKwliFIRsWusU0xt7x2u7vfi2TT8Li16M"
#define WIFI_SSID "siddharth"
#define WIFI_PASSWORD "siddharth"

const int leftForward = D5;
const int leftBackward = D4;
const int rightForward = D0;
const int rightBackward = D2;
const int en1 = D6;
const int en2 = D7;

float xi = 0;
float x = 0;
float y = 0;

FirebaseData firebaseData;

void setup() {
  Serial.begin(115200);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("connected"); 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);
  pinMode(leftForward,OUTPUT);
  pinMode(leftBackward,OUTPUT);
  pinMode(rightForward,OUTPUT);
  pinMode(rightBackward,OUTPUT);
}



void loop() {
if (Firebase.getFloat(firebaseData, "x-pos")) {

    if (firebaseData.dataType() == "float") {
      x = firebaseData.floatData();
      Serial.println(x);
      if(x < 200)
      { //analogWrite(en1,255);
        //analogWrite(en2,255);
        digitalWrite(leftForward,LOW);
        digitalWrite(leftBackward,HIGH);
        digitalWrite(rightForward,LOW);
        digitalWrite(rightBackward,HIGH);
      }

      if(x> 200)
      {
        //analogWrite(en1,255);
        //analogWrite(en2,255);
        digitalWrite(leftForward,HIGH);
        digitalWrite(leftBackward,LOW);
        digitalWrite(rightForward,HIGH);
        digitalWrite(rightBackward,LOW);
      }
      y = x;
    }

  } else {
    Serial.println(firebaseData.errorReason());
  }
  
}
