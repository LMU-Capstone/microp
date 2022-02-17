#ifndef LASER_H
#define LASER_H

#include <vector>

#include "../include/global.hpp"


class Laser {

    public:

        void set_position(float new_x, float new_y, float v_x, float v_y);

        void change_location(float new_x, float new_y){
            location = {new_x, new_y};
            return;
        }

    private:
        std::vector<float> location; // where in the x-y plane the laser hits
        float width_of_beam; // assuming perfect collimation

};

#endif