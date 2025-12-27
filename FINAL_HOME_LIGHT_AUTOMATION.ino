#define LM393_SENSOR_PIN D2  // LM393 Digital Output
#define LED_PIN D4           // LED controlled via Blynk/LM393
#define LED_VPIN V2  // Virtual pin for LED control in Blynk
#define LIGHT_SENSOR_VPIN V1  // Light Sensor virtual pin
#define API_TOGGLE_VPIN V3  // Toggle switch for using API
#define BLYNK_TEMPLATE_ID "TMPL3d5b7C0Kd"
#define BLYNK_TEMPLATE_NAME "HOME LIGHT AUTOMATION"
#define BLYNK_AUTH_TOKEN "k3sSym2Hqst5IJ6Sgj5phM45mbS61wmc"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ArduinoJson.h>
#include <WiFiClientSecure.h>

// WiFi and Blynk Credentials
char ssid[] = "Network101";
char pass[] = "12348765";
char auth[] = "k3sSym2Hqst5IJ6Sgj5phM45mbS61wmc";

// Google API URL
const char* google_api_url = "https://api.sunrise-sunset.org/json?lat=30.3398&lng=76.3869&formatted=0";

WiFiClientSecure client;
bool useAPI = false;  // Controlled via Blynk (V3)
String sunriseTime, sunsetTime;

void setup() {
    Serial.begin(115200);
    WiFi.begin(ssid, pass);
    Blynk.begin(auth, ssid, pass);

    pinMode(LM393_SENSOR_PIN, INPUT);
    pinMode(LED_PIN, OUTPUT);
    
    connectToGoogleAPI(); // Fetch sunrise/sunset times at startup
}

void loop() {
    Blynk.run();
    int lightStatus = digitalRead(LM393_SENSOR_PIN);
    Blynk.virtualWrite(LIGHT_SENSOR_VPIN, lightStatus);
    
    if (useAPI) {
        if (isDaytime()) {
            digitalWrite(LED_PIN, LOW); // Turn off LED
            Serial.println("Daytime - LED OFF (API Control)");
        } else {
            digitalWrite(LED_PIN, HIGH); // Turn on LED
            Serial.println("Nighttime - LED ON (API Control)");
        }
    } else {
        if (lightStatus == LOW) {
            digitalWrite(LED_PIN, LOW);
            Serial.println("Too Bright - LED OFF (LM393)");
        } else {
            digitalWrite(LED_PIN, HIGH);
            Serial.println("Dark - LED ON (LM393)");
        }
    }
    Blynk.virtualWrite(LED_VPIN, digitalRead(LED_PIN));
    delay(500);
}

BLYNK_WRITE(API_TOGGLE_VPIN) {
    useAPI = param.asInt(); // Toggle API mode via Blynk
    Serial.print("API Mode: "); Serial.println(useAPI ? "Enabled" : "Disabled");
}

void connectToGoogleAPI() {
    Serial.println("Connecting to Google API...");
    client.setInsecure();
    if (!client.connect("api.sunrise-sunset.org", 443)) {
        Serial.println("Connection Failed!");
        useAPI = false;
        return;
    }

    client.print(String("GET ") + google_api_url + " HTTP/1.1\r\n" +
                 "Host: api.sunrise-sunset.org\r\n" +
                 "Connection: close\r\n\r\n");
    
    String response;
    while (client.available()) {
        response += client.readString();
    }
    parseGoogleAPIResponse(response);
}

void parseGoogleAPIResponse(String response) {
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, response);

    if (error) {
        Serial.println("JSON Parsing Failed!");
        useAPI = false;
        return;
    }

    sunriseTime = doc["results"]["sunrise"].as<String>();
    sunsetTime = doc["results"]["sunset"].as<String>();
    
    Serial.print("Sunrise: "); Serial.println(sunriseTime);
    Serial.print("Sunset: "); Serial.println(sunsetTime);
    
    useAPI = true;
}

bool isDaytime() {
    // Placeholder: Implement time conversion and comparison logic here
    return true;
}
