#include <LiquidCrystal.h>
#include <ESP8266WiFi.h>

// GPIO -> LCD pin mapping
// D1=5, D2=4, D5=14, D6=12, D7=13, D8=15
const int rs = 5, en = 4, d4 = 14, d5 = 12, d6 = 13, d7 = 16;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
// REPLACE WITH YOUR SSID & PASSWORD
const char* ssid = "####";
const char* password = "####";

void setup() {
  // wait for LCD to warm up
  delay(650);
  lcd.begin(16,2);
  lcd.print("Connecting...");

  WiFi.begin(ssid, password);

  int counter = 0;
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    lcd.setCursor(counter % 16, 1);
    lcd.print(".");
    counter++;

    // if the connection takes too long, just give up and tell user.
    if(counter>30){
      lcd.clear();
      lcd.print("Connection Failed!");
      while(1);
    }
  }

  // the wifi has been connected so continue
  lcd.clear();
  lcd.print("WiFi Connected");
  lcd.setCursor(0,2);
  lcd.print(WiFi.localIP()); // for testing purpose

}

void loop() {
  // put your main code here, to run repeatedly:

}
