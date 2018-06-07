#include <Gizwits.h>
#include <Wire.h>
#include <SoftwareSerial.h>
#include <Adafruit_BMP085.h>
#include <DHT.h>

//温湿度功能
#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

//光照度定义
#define ADDRESS_BH1750FVI 0x23
#define ONE_TIME_H_RESOLUTION_MODE 0x20
byte highByte = 0;
byte lowByte = 0;
unsigned int sensorOut = 0;
unsigned int illuminance = 0;

//气压海拔
Adafruit_BMP085 bmp;
int Winds = A0;
int ASignal = A1;

// 按键功能值定义
unsigned long Last_KeyTime = 0;
uint8_t NetConfigureFlag = 0;
uint8_t gaterSensorFlag = 0;

SoftwareSerial mySerial(A2, A3); // A2 -> RX, A3 -> TX

Gizwits myGizwits;

void setup()
{
  Wire.begin();

  dht.begin();

  pinMode(Winds, INPUT);

  pinMode(ASignal, INPUT);

  mySerial.begin(115200);

  myGizwits.begin();

  mySerial.println("GoKit init  OK \n");
}

/**
* Arduino loop 
* @param none
* @return none
*/
void loop()
{
  dhtdemo();
  Windspeed();
  Rainfall();
  pa();
  Lx();
  myGizwits.process();
}

//获取并上报温湿度
void dhtdemo()
{
  long varW_Temperature = dht.readTemperature(); //Add Sensor Data Collection
  myGizwits.write(VALUE_Temperature, varW_Temperature);

  unsigned long varW_Humidity = dht.readHumidity(); //Add Sensor Data Collection
  myGizwits.write(VALUE_Humidity, varW_Humidity);
}

void Windspeed()
{
  float varW_Windspeed = analogRead(Winds);
  myGizwits.write(VALUE_Windspeed, varW_Windspeed);
}

void Rainfall()
{
  int sensorValue = 1023 - analogRead(ASignal);
  unsigned long varW_Rainfall = sensorValue;
  myGizwits.write(VALUE_Rainfall, varW_Rainfall);
}

//获取并上报气压海拔
void pa()
{
  float a = rand() % 100;
    
  int Altitude = (bmp.readAltitude() - 29091);
  unsigned long varW_Altitude = Altitude;
  myGizwits.write(VALUE_Altitude, varW_Altitude);

  float Pressure = (bmp.readPressure() + 650) / 10;
  float varW_Pressure = Pressure + (a/100);
  myGizwits.write(VALUE_Pressure, varW_Pressure);
}

//获取并上报光照度
void Lx()
{
  Wire.beginTransmission(ADDRESS_BH1750FVI);
  Wire.write(ONE_TIME_H_RESOLUTION_MODE);
  Wire.endTransmission();
  Wire.requestFrom(ADDRESS_BH1750FVI, 2);
  highByte = Wire.read();
  lowByte = Wire.read();
  sensorOut = (highByte << 8) | lowByte;
  illuminance = sensorOut / 1.2;

  unsigned long varW_Lux = illuminance;
  myGizwits.write(VALUE_Lux, varW_Lux);
}
