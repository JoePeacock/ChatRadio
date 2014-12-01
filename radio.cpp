#include "radio.h"

Radio::Radio(int frequency){
    this->set_frequency(frequency);
}

bool Radio::set_frequency(int frequency) {
    this->broadcast_frequency = frequency;
}

bool Radio::send_broadcast(char *message[]) {
    std::cout << message << endl;
}

int Radio::listen() {
    std::cout << "Listening" << endl;
}