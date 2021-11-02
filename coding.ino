// FOR NODEMCU

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>

String tag = "";

int pin1 = D1;
int pin2 = D2;
int pin3 = D5;

int datapin1 = 0;
int datapin2 = 0;
int datapin3 = 0;

const char* ssid = "POCOPHONE F1"; 
const char* password = "nafza9494";

String dataStatus = "";

String serverName = "http://192.168.43.206/project_poli";

String payload;

String StatusIN = "No data";
String StatusOUT = "IN";
String StatusOFF = "OUT";

StaticJsonDocument<200> doc;


void setup() {
  Serial.begin(9600);
  pinMode (datapin1, INPUT);
  pinMode (datapin2, INPUT);
  pinMode (datapin3, INPUT);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}

void loop() {
  datapin1 = digitalRead(pin1);
  datapin2 = digitalRead(pin2);
  datapin3 = digitalRead(pin3);

  if (datapin1 == HIGH){
    tag = "8319420126";
    datagetStatus();
    if (dataStatus == StatusIN){
      getdataIN();
      delay (1000);
      tag = "";
      }
    if (dataStatus == StatusOUT){
      getdataOUT();
      delay (1000);
      tag = "";
      }

    if (dataStatus == StatusOFF){
      tag = "";
      }
    }

  if (datapin2 == HIGH){
    tag = "13116319226";
    datagetStatus();
    if (dataStatus == StatusIN){
      getdataIN();
      delay (1000);
      tag = "";
      }
    if (dataStatus == StatusOUT){
      getdataOUT();
      delay (1000);
      tag = "";
      }

    if (dataStatus == StatusOFF){
      tag = "";
      }
    }

  if (datapin3 == HIGH){
    tag = "154466437";
    datagetStatus();
    if (dataStatus == StatusIN){
      getdataIN();
      delay (1000);
      tag = "";
      }
    if (dataStatus == StatusOUT){
      getdataOUT();
      delay (1000);
      tag = "";
      }
    }
    
    if (dataStatus == StatusOFF){
      tag = "";
      }
}

void datagetStatus(){
  
  if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;

      String serverPath = serverName + "/api.php?Id_card=" + tag;
      
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
    DeserializationError error = deserializeJson(doc, payload);

    const char* Status = doc["Status"];
    dataStatus = String(Status);
  }

void getdataOUT(){   
  if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;

      String serverPath = serverName + "/updatedata.php?Status=OUT&Id_card=" + tag;
      
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  
  }  

void getdataIN(){
  if(WiFi.status()== WL_CONNECTED){
      WiFiClient client;
      HTTPClient http;

      String serverPath = serverName + "/updatedata.php?Status=IN&Id_card=" + tag;
      
      // Your Domain name with URL path or IP address with path
      http.begin(client, serverPath.c_str());
      
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      
      if (httpResponseCode>0) {
        Serial.print("HTTP Response code: ");
        Serial.println(httpResponseCode);
        payload = http.getString();
        Serial.println(payload);
      }
      else {
        Serial.print("Error code: ");
        Serial.println(httpResponseCode);
      }
      // Free resources
      http.end();
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
