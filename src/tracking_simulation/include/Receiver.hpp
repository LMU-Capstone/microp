#ifndef RECEIVER_H
#define RECEIVER_H

#include <iostream>

#include "../include/Pattern.hpp"
#include "../include/global.hpp"

class Receiver { 
    public:
        void tick(float);

    //getters
        float get_x(){return this->x;};
        float get_y(){return this->y;};
        tuple get_point(){
            return {this->x, this->y};
        }

        float get_is_stopped(){return this->is_stopped;}

    //setters
        void set_x(float new_x){this->x = new_x;};
        void set_y(float new_y){this->y = new_y;};
        void set_point(tuple new_point){
            this->x = new_point.a;
            this->y = new_point.b;
        }
        void set_is_stopped(bool new_value){this->is_stopped = new_value;};

    //output and operator casting
    friend std::ostream& operator<<(std::ostream& os, Receiver& r) {
        os << "Receiver at: (" << r.get_x() << ", " << r.get_y() << ")";
		return os;
	}
    private:
        float x, y;
        bool is_stopped;
        Pattern pattern;
};

#endif