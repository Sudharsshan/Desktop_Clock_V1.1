#include <ESP8266WiFi.h>
#include <LiquidCrystal.h>
#include <time.h>

// GPIO -> LCD pin mapping
// D1=5, D2=4, D5=14, D6=12, D7=13, D8=15
const int rs = 5, en = 4, d4 = 14, d5 = 12, d6 = 13, d7 = 16;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

const char* ssid = "####";
const char* password = "####"; // Replace with your SSID & PASSWORD

// Time settings for IST +5:30
int timezone = 5.5 * 3600;
int dst = 0;

void setup() {
  // wait for a moment for LCD to prepare
  delay(500);
  lcd.begin(16,2);
  lcd.print("WiFi Connecting");

  WiFi.begin(ssid,password);
  // Connection animation xD
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    lcd.setCursor(0,1);
    lcd.print(".");
  }

  lcd.clear();
  lcd.print("Syncing NTP...");

  // initialize NTP
  configTime(timezone, dst, "pool.ntp.org", "time.nist.gov");

  // wait till NPT is sync
  while(!time(nullptr)){
    delay(1000);
  }
}

void loop() {
  time_t now = time(nullptr);
  struct tm* p_tm = localtime(&now);

  // Line 1 : Date as DD/MM/YYYY
  lcd.setCursor(0,0);
  char dateBuf[17];
  sprintf(dateBuf, "Date: %02d/%02d/%04d", p_tm->tm_mday, p_tm->tm_mon +1, p_tm->tm_year + 1900);
  lcd.print(dateBuf);

  // Line 2 : Time as HH:MM:SS)
  lcd.setCursor(0,1);
  char timeBuf[17];
  sprintf(timeBuf, "Time: %02d:%02d:%02d", p_tm->tm_hour, p_tm->tm_min, p_tm->tm_sec);
  lcd.print(timeBuf);

  delay(500);
}
