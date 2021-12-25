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
#include <FirebaseArduino.h>
#include <DHT.h>

// Set these to run example.
#define FIREBASE_HOST "blackbox-7e17f-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "vxVJCFq2BvADKlmGopOEBvqzTziRlFvwpLuFD4nB"
#define WIFI_SSID  "Pranav"
#define WIFI_PASSWORD "12345678"

#define DHTPIN 2          // Digital pin 4

// Uncomment whatever type you're using!
#define DHTTYPE DHT11     // DHT 11
//#define DHTTYPE DHT22   // DHT 22, AM2302, AM2321
//#define DHTTYPE DHT21   // DHT 21, AM2301

DHT dht(DHTPIN, DHTTYPE);


void setup() {
  Serial.begin(9600);


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
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    
    dht.begin();
}

int n = 0;

void loop() {
 
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  String stringOne = String(t, 2);
  // set value
  Firebase.setString("Temp", stringOne);
   
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
    String stringTwo = String(h, 2);
   Firebase.setString("Humi", stringTwo);
  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /number failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // get value 
  Serial.print("Temperature: ");
  Serial.println(Firebase.getString("Temp"));
  delay(1000);
  Serial.print("Humidity: ");
  Serial.println(Firebase.getString("Humi"));
  float speed=(Firebase.getFloat("Blackbox/Speed"));
  
  delay(1000);
  float speedt=(Firebase.getFloat("Blackbox/Speed"));
  
  float acce =(speedt-speed)/(1000);
  String stringa = String(acce, 2);
  Firebase.setString("Blackbox/vAcceleration",stringa);
  
  // remove value
 

  // set string value
 
  // set bool value
  

  // append a new value to /logs

  delay(1000);
}
