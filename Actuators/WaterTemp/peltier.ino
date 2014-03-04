
//Peltier Tutorial From- http://garagelab.com/profiles/blogs/how-to-use-a-peltier-with-arduino?xg_source=activity
//On this tutorial, we will show how to use a Peltier with Arduino. The Peltier, or Thermoelectric coolers, are a device that can transfer heat from one side to another when a current is applied. You can use it as a heater or a cooler. This Peltier can be powered up to 15,4V and 7A.
//To control the current, we will use a PWM port. It can be used the pins 3,5,6,9,10 and 11. We are going to use the pin 3.

To use the Peltier, you will need a N-channel Mosfet and a 10K resistor.

int peltier = 3; //The N-Channel MOSFET is on digital pin 3
int power = 0; //Power level fro 0 to 99%
int peltier_level = map(power, 0, 99, 0, 255); //This is a value from 0 to 255 that actually controls the MOSFET

void setup(){
Serial.begin(9600);

//pinMode(peltier, OUTPUT);
}

void loop(){
char option;

if(Serial.available() > 0)
{
option = Serial.read();
if(option == 'a') 
power += 5;
else if(option == 'z')
power -= 5;

if(power > 99) power = 99;
if(power < 0) power = 0;

peltier_level = map(power, 0, 99, 0, 255);
}

Serial.print("Power=");
Serial.print(power);
Serial.print(" PLevel=");
Serial.println(peltier_level);

analogWrite(peltier, peltier_level); //Write this new value out to the port

}