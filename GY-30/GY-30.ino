//#include <Adafruit_BMP085.h>

#include <Wire.h> 
#define ADDRESS_BH1750FVI 0x23    //ADDR="L" for this module
#define ONE_TIME_H_RESOLUTION_MODE 0x20
byte highByte = 0;
byte lowByte = 0;
unsigned int sensorOut = 0;
unsigned int illuminance = 0;
//Adafruit_BMP085 bmp;

void setup()
{
Wire.begin();
Serial.begin(115200);
}

void loop()
{
Wire.beginTransmission(ADDRESS_BH1750FVI); //"notify" the matching device
Wire.write(ONE_TIME_H_RESOLUTION_MODE);     //set operation mode
Wire.endTransmission();

delay(180);
Wire.requestFrom(ADDRESS_BH1750FVI, 2); //ask Arduino to read back 2 bytes from the sensor
highByte = Wire.read();  // get the high byte
lowByte = Wire.read(); // get the low byte
sensorOut = (highByte<<8)|lowByte;
illuminance = sensorOut/1.2;
long varW_Lux = illuminance;
Serial.print(varW_Lux);
//Serial.print(illuminance);
//Serial.println(" lux");

/*************************************************************/
//Serial.print("Temperature = ");
//    Serial.print(bmp.readTemperature());
//    Serial.println(" *C");
//    
//    Serial.print("Pressure = ");
//    Serial.print(bmp.readPressure());
//    Serial.println(" Pa");
//    
//    // Calculate altitude assuming 'standard' barometric
//    // pressure of 1013.25 millibar = 101325 Pascal
//    Serial.print("Altitude = ");
//    Serial.print(bmp.readAltitude());
//    Serial.println(" meters");
//
//    Serial.print("Pressure at sealevel (calculated) = ");
//    Serial.print(bmp.readSealevelPressure());
//    Serial.println(" Pa");
//
//  // you can get a more precise measurement of altitude
//  // if you know the current sea level pressure which will
//  // vary with weather and such. If it is 1015 millibars
//  // that is equal to 101500 Pascals.
//    Serial.print("Real altitude = ");
//    Serial.print(bmp.readAltitude(101500));
//    Serial.println(" meters");
    
delay(1000);
}
