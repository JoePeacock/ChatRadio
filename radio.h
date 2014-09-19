#include <iostream>
#include <string>

#ifndef RADIO_H_
#define RADIO_H_

class Radio {

    public:
        Radio(int frequency);
        bool set_frequency(int frequency);
        bool send_broadcast(std::string message);
        int listen(void);
        int close(void);

    private:
        int broadcast_frequency;
        int fd;
        int set_register(unsigned char reg, unsigned char value);
        int set_init_registers(void);
};

#endif
