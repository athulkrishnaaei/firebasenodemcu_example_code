# firebasenodemcu_example_code
contains libraries and code fpr nodemcu firebase


Firebase issue on esp8266

Visit this site

https://www.grc.com/fingerprints.htm

and search your newest fingerprint by typing

test.firebaseio.com

take your fingerprint

look for this library and replace it here your in :

"Arduino/libraries/firebase-arduino-master/src/FirebaseHttpClient.h"


93:49:BD:13:3F:AD:AE:EB:44:9B:DA:EA:6E:7F:27:A3:2E:D1:73:7B change finger print
use arduino json 5.13.5
use esp8266 version 2.7.x

use good usb cable

esp8266 2.7.2
arduinojson used arduino json ver 5.13.1
install ch340  https://www.youtube.com/watch?v=D271p2E2_o4
add firebase libraryy in documents/arduino/library



//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h> //used arduino json ver 5.13.1
//#include <DHT.h>

// Set these to run example.
#define FIREBASE_HOST "drowsiness-detection-2cb1a-default-rtdb.firebaseio.com" //https://drowsiness-detection-2cb1a-default-rtdb.firebaseio.com/
#define FIREBASE_AUTH "favH02cZeOTkcmEVjOSLSZld8NUZ8KXBaBk8oAOk" //favH02cZeOTkcmEVjOSLSZld8NUZ8KXBaBk8oAOk
#define WIFI_SSID  "wifi"
#define WIFI_PASSWORD "123456789"

//#define DHTPIN 2          // Digital pin 4

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

//DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);
//if data not recieving change fingerprint with this site https://www.grc.com/fingerprints.htm
//arduino json 5.13.5 is used
//esp8266 2.7.2 is used
  pinMode(5, OUTPUT); //D1
    pinMode(4, OUTPUT);//D2
     pinMode(LED_BUILTIN, OUTPUT);
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
   Serial.print("Welcome to Driver Alert system ");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    Firebase.setString("Connection", "nodemcuconnectedtofirebase");//this is to check that sending data from arduino to firebase is working
//    dht.begin();
}



void loop() {
Firebase.setString("Connection", "nodemcuconnectedtofirebasefromloop");//this is to check that sending data from arduino to firebase is working
String connection = Firebase.getString("Connection");//this is to check that sending data from  firebase to nodemcu is working receving data from fire base
Serial.println(connection);
/////////////////////////////////////////////////
  //Serial.print("Detection: ");
  String drowsiness = Firebase.getString("drowsiness");
  String yawn       =Firebase.getString("yawn");
  Serial.println(drowsiness);
  Serial.println(yawn);
  delay(1000);
  if (yawn == "yawn detected" || drowsiness == "sleep detected")
  {
    digitalWrite(5,LOW);//D1
     digitalWrite(LED_BUILTIN,LOW);
     delay(5000);//change here to change buzzer ringing time
   
  }
    else{
      digitalWrite(5,HIGH);//D1
     
      digitalWrite(LED_BUILTIN,HIGH);
    }

 delay(1000);
  }
 


