#include <Arduino.h>
/*
* Getting Started example sketch for nRF24L01+ radios
* This is a very basic example of how to send data from one node to another
* Updated: Dec 2014 by TMRh20

    sender script120
*/

#include <SPI.h>
#include "RF24.h"

/****************** User Config ***************************/

/* Hardware configuration: Set up nRF24L01 radio on SPI bus plus pins 7 & 8 */
RF24 radio(D1,D2); // CE, CSN

/**********************************************************/

byte addresses[][6] = {"1Node","2Node"};
int on = 1;
int off = 0;

void setup() {
  Serial.begin(9600);
  pinMode(D8, INPUT);

  radio.begin();

  // Set the PA Level low to prevent power supply related issues since this is a
 // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
  radio.setPALevel(RF24_PA_LOW);
  radio.setChannel(120);  // 2,4GhZ -> 2,525 GhZ (0 ... 124)

  radio.openWritingPipe(addresses[1]);

}

void loop() {

  radio.write( &on, sizeof(int));
  delay(500);
  radio.write( &off, sizeof(int));
  delay(500);

} // Loop
