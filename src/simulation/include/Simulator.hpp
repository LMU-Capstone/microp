#ifndef SIMULATOR_H
#define SIMULATOR_H

#include <vector>
#include <functional>

#include "../include/Laser.hpp"
#include "../include/Endpoint.hpp"


class Simulator{
    public:
        Simulator(Endpoint, Laser, std::function<void(Laser*)>);
        void tick();
        void set_scene(Endpoint, Laser);
    private:
};

#endif