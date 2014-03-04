int val=0;

void setup()
{
Serial.begin(9600);  
pinMode(7,OUTPUT);
digitalWrite(7,LOW);
}

void loop()
{
digitalWrite(7,HIGH);
delay(250);
int val = analogRead(A0);
float voltage = (val) * 3.3;
voltage /= 1024.0;
Serial.print(voltage); Serial.println(" volts");
float temperatureF = (voltage - 0.5) * 10 ; 
Serial.print(temperatureF);
Serial.println(" degrees F");
digitalWrite(7,LOW);
delay(250);
}
