#include "radio.h"
#include <iostream>
#include <linux/spi/spidev.h>
#include <unistd.h>
#include <string>
#include <stdio.h>
#include <fcntl.h>

int fd;
static const char *device = "/dev/spidev0.1";

Radio::Radio(int frequency)
{
    this->set_frequency(frequency);

    fd = open(device, O_RDWR);
    if (fd < 0) 
        perror("Can't open device!");

    int ret = set_init_registers();
    if (ret < 0)
        perror("Radio initialization failed!");
}

int Radio::set_init_registers()
{
    // Send some shit over SPI


}

int Radio::close()
{
    // Close that file descriptor.
    close(fd);
}


/*
 *Frequency to set to: 9Mhz
 */
bool Radio::set_frequency(int frequency_value) 
{
    this->broadcast_frequency = frequency_value;

    unsigned char frequency = 0x01; // filler value
    this->set_register(0x73, frequency); // not correct value & should used #define for register address
}

bool Radio::send_broadcast(std::string message) 
{
    std::cout << message << std::endl;
}

int Radio::listen() 
{
    std::cout << "Listening" << std::endl;
}


int Radio::set_register(unsigned char reg, unsigned char value)
{
    unsigned char data[2];
    data[0] = reg;
    data[1] = value;

    if(write(fd, data, 2) != 2)
    {
        return -1;
    }

    return 1;
}
