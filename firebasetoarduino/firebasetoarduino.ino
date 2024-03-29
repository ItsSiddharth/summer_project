#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://nodemcu-4eb31.firebaseio.com/"
#define FIREBASE_AUTH ""
#define WIFI_SSID "siddharth"
#define WIFI_PASSWORD "siddharth"

const int leftForward = D5;
const int leftBackward = D4;
const int rightForward = D0;
const int rightBackward = D3;

const int en1 = D7;
const int en2 = D6;

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
if (Firebase.getFloat(firebaseData, "x-pos")) 
{
    if (firebaseData.dataType() == "float") 
    {
      x = firebaseData.floatData();
      Serial.println(x);
      
      if( x == y)
      {
        digitalWrite(leftForward,LOW);
        digitalWrite(leftBackward,LOW);
        digitalWrite(rightForward,LOW);
        digitalWrite(rightBackward,LOW);
      }
      
      if (x - y > 20 )
      { //analogWrite(en1,230);
        //analogWrite(en2,230);
        digitalWrite(leftForward,LOW);
        digitalWrite(leftBackward,LOW);
        digitalWrite(rightForward,LOW);
        digitalWrite(rightBackward,HIGH);
      }

      if (y - x > 20)
      {
        //analogWrite(en1,230);
        ///analogWrite(en2,230);
        digitalWrite(leftForward,LOW);
        digitalWrite(leftBackward,HIGH);
        digitalWrite(rightForward,LOW);
        digitalWrite(rightBackward,LOW);
      }
      
      y = x;
    }

  } else 
  {
    Serial.println(firebaseData.errorReason());
  }
  
}
