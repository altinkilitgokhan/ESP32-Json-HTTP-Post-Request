/*
 POST Json Object to HTTP Server.
 First of all you need to connect the Wifi with your Esp device.
 
 Import ArduinoJson Library, but be careful about the version. Version 6 is used in the tutorial.
 There are some differences between version5 and version 6.
*/

#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>

const char* ssid     = "YourWifiSSID";
const char* password = "YourWifiPassword";


WiFiServer server(80);

void setup()
{
    Serial.begin(115200);

    delay(10);

    // We start by connecting to a WiFi network

    Serial.println();
    Serial.println();
    Serial.print("Connecting to ");
    Serial.println(ssid);

    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }

    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
    
    server.begin();
    postDataToServer();
}

int value = 0;

void loop(){
  //No need to write anything for now.
}
void postDataToServer() {
 
  Serial.println("Posting JSON data to server...");
  // Block until we are able to connect to the WiFi access point
  if (WiFi.status() == WL_CONNECTED) {
     
    HTTPClient http;   
     
    http.begin("https://[your-app-name].firebaseio.com/.json?auth=[your authorization key");  
    http.addHeader("Content-Type", "application/json");         
     
    StaticJsonDocument<200> doc; //Create json document
    
    doc["userName"] = "Nameless";
    doc["userScore"] = 1351;
   
  JsonArray data = doc.createNestedArray("data"); // This 3 lines used for create jsonarray
    data.add(21);
    data.add(2);
         
    String requestBody;
    serializeJson(doc, requestBody);
     
    int httpResponseCode = http.POST(requestBody);
 
    if(httpResponseCode>0){
       
      String response = http.getString();                       
       
      Serial.println(httpResponseCode);   
      Serial.println(response);
     
    }
    else {
     
       
    }
     
  }
}
