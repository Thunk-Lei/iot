#include <DHT.h>

#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  dhtdemo();
}

void dhtdemo()
{
  long varW_Temperature = dht.readTemperature(); //Add Sensor Data Collection
  Serial.print(varW_Temperature);
  Serial.println(" *C");

  unsigned long varW_Humidity = dht.readHumidity(); //Add Sensor Data Collection
  Serial.print(varW_Humidity);
  Serial.println(" %");
  delay(5000);
}
