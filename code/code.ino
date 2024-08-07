#include <WiFi.h>
#include <WiFiClient.h>
#include <WebServer.h>
#include "ZMPT101B.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include "index.h"

WebServer server(80);

const char* ssid     = "YOUR_NETWORK";
const char* password = "YOUR_PASSWORD";

char caracter = '0';
String texto = "";
String texto_send = "";

LiquidCrystal_I2C lcd(0x27, 16, 2);

ZMPT101B voltageSensor(15);
int state = 1;
float U;
float temperatureC;
const int sensorIn = 34;      // pin where the OUT pin from sensor is connected on Arduino
int mVperAmp = 185;           // this the 5A version of the ACS712 -use 100 for 20A Module and 66 for 30A Module
int Watt = 0;
double Voltage = 0;
double VRMS = 0;
double AmpsRMS = 0;

#define sensorPin 2

void handleRoot() {
 String s = MAIN_page;
 server.send(200, "text/html", s);
}
 
void handleADC() {
String volt = String(U);
 String amp = String(AmpsRMS);
 String deg = String(temperatureC);
 
 server.send(200, "text/plane", volt+"|"+amp+"|"+deg);//Send ADC value only to client ajax request
}

void onOff(){
  if (state == 1){
    state = 0;
    //relay off
    }
   else {
    state = 1;
    //relay on
    }
  }
  
void setup(void){
  Serial.begin(115200);
  Serial.println();
  Serial.println("Booting Sketch...");


//  WiFi.mode(WIFI_AP); //AP mode
//  WiFi.softAP(ssid, password);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.println("Connecting to ");
  Serial.print(ssid);


  while(WiFi.waitForConnectResult() != WL_CONNECTED){      
      Serial.print(".");
    }
    

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP()); 
 
  server.on("/", handleRoot);      
  server.on("/readADC", handleADC);
  server.on("/onOff", onOff);
 
  server.begin();
  Serial.println("HTTP server started");

  lcd.begin();

  // Turn on the blacklight and print a message.
  lcd.backlight();
  voltageSensor.calibrate();
  pinMode(4,OUTPUT);
  pinMode(25,OUTPUT);
  pinMode(26,OUTPUT);
  pinMode(27,OUTPUT);
}


void loop(void){
  server.handleClient();

U= voltageSensor.getVoltageAC();
    ////////////////
   Voltage = getVPP();
  VRMS = (Voltage/2.0) *0.707;   //root 2 is 0.707
  AmpsRMS =(VRMS *10)/mVperAmp;///////////////////////////change here
 

}
 
 
float getVPP()
{
  float result;
  int readValue;                // value read from the sensor
  int maxValue = 0;             // store max value here
  int minValue = 1024;          // store min value here
  
   uint32_t start_time = millis();
   while((millis()-start_time) < 1000) //sample for 1 Sec
   {
       readValue = analogRead(sensorIn);
       // see if you have a new maxValue
       if (readValue > maxValue) 
       {
           /*record the maximum sensor value*/
           maxValue = readValue;
       }
       if (readValue < minValue) 
       {
           /*record the minimum sensor value*/
           minValue = readValue;
       }
   }
   
   // Subtract min from max
   result = ((maxValue - minValue) * 5.0)/1024.0;
      
   
  ///////////////
 /* Serial.print(U);
  Serial.print("  volt  ");
    Serial.print(AmpsRMS);
  Serial.print(" Amps RMS");
  Watt = AmpsRMS*U;    // 1.3 is an empirical calibration factor
  Serial.print(Watt);
  Serial.println(" W");*/
   Watt = AmpsRMS*U; 
   ////////////
     int reading = analogRead(sensorPin);
  float voltage = reading * (3.3 / 1024.0);
  float temperatureC = voltage * 100;

  ///////////////////
  lcd.setCursor(0,0);
  lcd.print(U);
  lcd.setCursor(5,0);
  lcd.print("V  |");
    lcd.setCursor(10,0);
  lcd.print(AmpsRMS);
  lcd.setCursor(15,0);
  lcd.print("A");
     lcd.setCursor(0,1);
  lcd.print(Watt);
  lcd.setCursor(4,1);
  lcd.print("Watt |");
  lcd.setCursor(9,1);
  lcd.print(temperatureC);
  lcd.setCursor(14,1);
  lcd.print("C");
  if(temperatureC>250)
  {
   digitalWrite(25,HIGH); 
   digitalWrite(4,LOW); 
    }
    else 
     {
      digitalWrite(4,HIGH); 
   digitalWrite(25,LOW); 
    }
    if(U>230)
  {
   digitalWrite(26,HIGH); 
    }
    else 
     {
   digitalWrite(26,LOW); 
   digitalWrite(4,HIGH);
    }
    if(AmpsRMS>0.25)
  {
   digitalWrite(27,HIGH); 
    }
    else 
     {
   digitalWrite(27,LOW); 
   digitalWrite(4,HIGH);
    }
  
return result;
}
