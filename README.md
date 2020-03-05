# ESP32 Json-HTTP Post Request

Simple Json post request using ESP32.



## Usage

You need to import following libraries.

```c
#include <ArduinoJson.h>
#include <HTTPClient.h>
#include <WiFi.h>
```
Wifi SSID and Password 
```c
const char* ssid     = "YourWifiSSID";
const char* password = "YourWifiPassword";


WiFi.begin(ssid, password); // Connect the Wifi
```

Create Json Object
```c
StaticJsonDocument<200> doc; //Create json document
    
doc["userName"] = "Nameless";
doc["userScore"] = 1351;
   
JsonArray data = doc.createNestedArray("data");
data.add(21);
data.add(2);
         
String requestBody;
serializeJson(doc, requestBody);
```

Write your server address in http.begin area.(This is an example of firebase server post)
```c
HTTPClient http;   
     
http.begin("https://[your-app-name].firebaseio.com/.json?auth=[your authorization key");  
http.addHeader("Content-Type", "application/json");      

int httpResponseCode = http.POST(requestBody);
```
