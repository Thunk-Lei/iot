float temp;
void setup()
{
  Serial.begin(115200);
}
void loop()
{
  feng();
}

void feng(){
  int V1 = analogRead(A0);
  Serial.print(V1);
  Serial.println(" V");
  delay(1000);
//  float vol = V1*(5.0 / 1023.0);
//  if (vol == temp)
//  {
//    temp = vol;
//  }
//  else
//  {
//    Serial.print(vol);
//    Serial.println(" V");
//    temp = vol;
//    delay(1000);
//  } 
}

