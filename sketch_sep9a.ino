#include <SCServo.h>


SMS_STS st;


#define S_RXD 0//Serial receive pins

#define S_TXD 1//Serial transmit piins



void setup() {

  Serial.begin(1000000,SERIAL_8N1);



  //Initializes serial port 1 communication for controlling the serial bus servo's; SERIAL_8N1 is the configuration data, parity, and stop bits; specifies the serial port pins

  //Serial1.begin(1000000, SERIAL_8N1);

  //Set the serial port parameter of the SCServo object to Serial1, indicating that the 1000000 serial port is used to control the servo

  st.pSerial = &Serial;

  delay(1000);

}


void loop()

{
  
  st.WritePosEx(1, 4095, 3400, 50); //Set the position, speed and acceleration of servo 1 with a delay of 2s

  delay(2000);


  st.WritePosEx(1, 2000, 1500, 50); //Set the position, speed and acceleration of servo 1 with a delay of 2s

  delay(2000);




  st.WritePosEx(1, 700, 1500, 50); //Set the position, speed and acceleration of servo 1 with a delay of 2s

  delay(5000);

}