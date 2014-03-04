/*
 SparkFun Electronics 2010
 Nathan Seidle
 
 This code is public domain.
 
 Peltier ran at 3.6A @ 11.0V = 39.6W!
 
 The thermo-electric cooler (or Peltier) works well well with a computer power supply for power, a computer 
 CPU heat sink for cooling and a N-Channel MOSFET to control the power. The Peltier is going to use a ton 
 of juice. In this case, I  measured 3.6 amps at 11 volts! I had to attach the hot side of the Peltier 
 to a large computer CPU heat sink but it worked so well that the cold side was so cold I could not keep 
 my finger on the device.
 
 Because I was so scared of pumping 40 watts into a device, I used this program to slowly ramp
 up the power flowing through the MOSFET. Press 'a' to increase power, 'z' to step down.
 
 */

int peltier = 11; //The N-Channel MOSFET is on digital pin 11
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


