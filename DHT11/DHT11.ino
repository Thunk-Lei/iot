#include <DHT.h>

#define   DHTPIN           2
#define   DHTTYPE          DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  long varW_Temperature = dht.readTemperature();
  unsigned long varW_Humidity = dht.readHumidity();

  Serial.print("Humidity (%): ");
  Serial.println(varW_Humidity);

  Serial.print("Temperature (oC): ");
  Serial.println(varW_Temperature);
 delay(2000);
}
