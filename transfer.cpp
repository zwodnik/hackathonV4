/*
TMRh20 2014

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public License
 version 2 as published by the Free Software Foundation.
 */

/** General Data Transfer Rate Test
 * This example demonstrates basic data transfer functionality with the
 updated library. This example will display the transfer rates acheived using
 the slower form of high-speed transfer using blocking-writes.
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <RF24/RF24.h>
#include <unistd.h>

using namespace std;
//
// Hardware configuration
//

RF24 radio(RPI_V2_GPIO_P1_15, RPI_V2_GPIO_P1_24, BCM2835_SPI_SPEED_8MHZ);

const uint64_t addresses[2] = { 0xABCDABCD71LL, 0x544d52687CLL };

uint8_t data[32];
unsigned long startTime, stopTime, counter, rxTimer=0;

int main(int argc, char** argv){

  radio.begin();                           // Setup and configure rf radio
 
 radio.setChannel(1);
//  radio.setPALevel(RF24_PA_MAX);
  radio.setPALevel(0);
  radio.setDataRate(RF24_250KBPS);
  radio.setAutoAck(1);                     // Ensure autoACK is enabled
  radio.setRetries(2,15);                  // Optionally, increase the delay between retries & # of retries
  radio.setCRCLength(RF24_CRC_16);          // Use 8-bit CRC for performance
  //radio.printDetails();

      radio.openWritingPipe(addresses[0]);
      radio.openReadingPipe(1,addresses[1]);
      radio.startListening();


  for(int i=0; i<32; i++){
     data[i] = rand() % 255;               			//Load the buffer with random data
  }

    // forever loop
    int counter = 0;
    while (1){


   while(radio.available()){
      radio.read(&data,32);
      printf("%d\n",(int)*data);
      counter++;
     }
      if(counter>=1){
      		break;
     }
     //break;

} // loop
} // main






