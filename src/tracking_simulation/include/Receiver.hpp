#ifndef RECEIVER_H
#define RECEIVER_H

#include <iostream>

#include "../include/global.hpp"
#include "../include/VelocityPattern.hpp"

class Receiver { 
    public:
        Receiver(VelocityPattern velocityPattern){
            this->set_pattern(velocityPattern);
        }
        void tick(float);
        void reset();


        void set_pattern(VelocityPattern newVelocityPattern){
            this->velocityPattern = newVelocityPattern;
        }
        
    //output and operator casting
    friend std::ostream& operator<<(std::ostream& os, Receiver& r) {
		return os;
	}
    private:
        float x = 0, y = 0, past_time = 0;
        VelocityPattern velocityPattern;
};

#endif