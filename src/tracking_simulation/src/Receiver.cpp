/*

Simulates the receiver in our algorithm

*/
#include <iostream>
#include <vector>

#include "../include/Receiver.hpp"

void Receiver::tick(float current_time){
    // get velocity
    auto velocity = this->velocityPattern.get_current_velocity(current_time);
    // get dt
    auto dt = current_time - this->past_time;
    // update x
    this->x += dt * velocity[0];
    // update y
    this->y += dt * velocity[1];
}

void Receiver::reset(){
    this->past_time = 0;
    this->x = 0;
    this->y = 0;
}