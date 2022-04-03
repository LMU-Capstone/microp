
#include "../include/driver.hpp"
#include "../include/shared_structures.hpp"
#include "../include/global.h"

#include <chrono>
#include <thread>
#include <math.h>
#include <iostream>


void Driver::run(){
    // while(true){
        if(this->shared_position->is_updated()){
            std::cout << "output" << std::endl;
            this->update_position(this->shared_position->get_position());
        }
        else {
            std::this_thread::sleep_for(this->wait_time);
        }
    // }
}

void Driver::update_position(std::vector<float> new_position){
    this->update_pins(new_position[0], this->x_pins);
    this->update_pins(new_position[1], this->y_pins);
    this->write_position();
}

void Driver::update_pins(float new_position, std::array<float, number_of_driver_pins> output_pinout){
    
    int new_position_int = (int)std::round(new_position);

    for(int i = 0; i < number_of_driver_pins; i++){
        std::cout << ((new_position_int>>i)&1) << std::endl;
        digitalWrite(output_pinout[i], (new_position_int>>i)&1);
    }
    std::cout << "---" << std::endl;
}

void Driver::write_position(){
    digitalWrite(this->latch_pins[0], 0);
    std::cout << "xxx" << std::endl;
    std::cout << this->latch_pins[1] << std::endl;
    digitalWrite(this->latch_pins[1], 0);
    std::this_thread::sleep_for(this->latch_time);
    digitalWrite(this->latch_pins[0], 1);
    digitalWrite(this->latch_pins[1], 1);
}