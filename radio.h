#include <iostream>
#include <string>

class Radio {

    public:
        Radio(int frequency);
        bool set_frequency(int frequency);
        bool send_broadcast(std::string message);
        int listen();
        int close_radio();

    private:
        int broadcast_frequency;
        int fd;
        int set_register(unsigned char reg, unsigned char value);
        unsigned char read_register(unsigned char reg);
        int set_init_registers();
};
