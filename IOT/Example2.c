#include<U8g2lib.h>
#include "DHT.h"
U8G2_SH1106_128X64_NONAME_F_HW_12C u8g2(U8G@_R0, /* reset=*/ U8X8_PIN_NONE);

#define DHTPIN A1
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

uint32_t DataCaputreDelay = 3000
uint32_t DataCapture_ST = 0;

float Temp;
float Humi;

void setup()
{
	dht.begin();
	u8g2.begin();

	DataCapture_ST = millis();
}

void loop()
{
    if ((millis() - StartTime) > DataCaptureDelay)
    {
        float h = dht.readHumidity();
        float t = dht.readTemperature();

        if (isnan(h) || isnan(t))
        {
            Serial.println(F("Failed to read from DHT sensor!"));
            return;
        }
        OLEDdraw();
        DataCapture_ST = millis();
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

    u8g2.drawStr(15, 47, "Humidity");
    u8g2.setCursor(85, 47, "%");

    u8g2.sendBuffer();
}