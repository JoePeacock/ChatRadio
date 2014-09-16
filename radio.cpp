#include "radio.h"
#include <linux/spi-dev.h>
#include <unistd.h>
#include <fcntl.h>

Radio::Radio(int frequency){
    this->set_frequency(frequency);

    fd = open("/dev/spi-0.1",O_RDWR);
    
}


/*
 *Frequency to set to: 9Mhz
 */
bool Radio::set_frequency(int frequency) {

    this->broadcast_frequency = frequency;

    unsigned char frequency = 0x01; //filler value
    set_reg(0x73,frequency);//not correct value & should used #define for register address

}

bool Radio::send_broadcast(char *message[]) {
    std::cout << message << endl;
}

int Radio::listen() {
    std::cout << "Listening" << endl;
}


int Radio::set_register(unsigned char reg, unsigned char value){

  unsigned char data[2];
  data[0] = reg;
  data[1] = value;
  if( write(fd,data,2) != 2){
    return -1;
  }

  return 1;
  
}
