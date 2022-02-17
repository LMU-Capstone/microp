#ifndef RECEIVER_H
#define RECEIVER_H

#include <iostream>

#include "../include/global.hpp"

class Receiver { 
    public:

        void tick(float);
        void reset();
        
    //output and operator casting
    friend std::ostream& operator<<(std::ostream& os, Receiver& r) {
		return os;
	}
    private:
};

#endif