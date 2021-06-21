#include "DHT.h"
#include <SoftPWM.h>

#define DHTPIN A1
#define DHTTYPE DHT22 

DHT dht(DHTPIN, DHTTYPE);
SOFTPWM_DEFINE_CHANNEL(A3);

uint32_t DataCaptureDelay = 2000; //ms
uint32_t StartTime = 0;


void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    dht.begin();
    StartTime = millis();
}

void loop() {
    // put your main code here, to run repeatedly:
    if ((millis() - StartTime) > DataCaptureDelay)
    {
        float h = dht.readHumidity();
        float t = dht.readTemperature();

        if (h >= 30)
        {
            SoftPWM.set(100);
        }

        if (h <= 25 && h > 30)
        {
            SoftPWM.set(0);
        }

        if (h >= 25 && h > 30)
        {
            SoftPWM.set(60);
        }

        if (isnan(h) || isnan(t))
        {
            Serial.println(F("Failed to read from DHT sensor!"));
            return;
        }

        Serial.println(F("Humidity:"));
        Serial.print(h);
        Serial.print(F("% Temperature:"));
        Serial.print(t);
        Serial.println(F("C"));

        StartTime = millis();
    }
}

void OLEDdraw()
{
    u8g2.clearBuffer();

    u8g2.setFont(u8g2_font_ncenB08_te);
    u8g2.drawStr(1, 15, "SMART FARM");

    u8g2.drawStr(15, 36, "Temp");
    u8g2.setCursor(85, 35);
    u8g2.print(Temp);
    u8g2.drawStr(114, 36, "\xb0");
    u8g2.drawStr(119, 36, "C");

    u8g2.drawStr(15, 47, "Fan");
    u8g2.setCursor(85, 47, "%");

    u8g2.sendBuffer();
}
