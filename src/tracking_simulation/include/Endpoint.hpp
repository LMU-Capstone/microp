#ifndef ENDPOINT_H
#define ENDPOINT_H

#include <iostream>

#include "../include/global.hpp"
#include "../include/VelocityPattern.hpp"

class Endpoint { 
    public:
        Endpoint(VelocityPattern velocityPattern){
            this->set_pattern(velocityPattern);
        }
        void tick(float);
        void reset();


        void set_pattern(VelocityPattern newVelocityPattern){
            this->velocityPattern = newVelocityPattern;
        }

        // getters 
        float get_x(){return this->x;}
        float get_y(){return this->y;}
        
    //output and operator casting
    friend std::ostream& operator<<(std::ostream& os, Endpoint& r) {
		return os;
	}
    private:
        float x = 0, y = 0, past_time = 0;
        VelocityPattern velocityPattern;
};

#endif