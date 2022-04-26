
#include "../include/driver.hpp"
#include "../include/shared_structures.hpp"
#include "../include/global.h"

#include <chrono>
#include <thread>
#include <math.h>
#include <iostream>

void Driver::run()
{
    while (this->is_running())
    {
        if (this->shared_position->is_updated())
        {
            this->update_position(this->shared_position->get_position());
        }
        else
        {
            std::this_thread::sleep_for(this->wait_time);
        }
    }
}

void Driver::kill()
{
    std::lock_guard<std::mutex> guard(this->check_running_mutex);
    this->running = false;
}

void Driver::start()
{
    std::lock_guard<std::mutex> guard(this->check_running_mutex);
    this->running = true;
}

bool Driver::is_running()
{
    std::lock_guard<std::mutex> guard(this->check_running_mutex);
    return this->running;
}

void Driver::update_position(std::vector<float> new_position)
{
    this->update_pins(new_position[0], this->x_pins);
    this->update_pins(new_position[1], this->y_pins);
    this->write_position();
}

void Driver::update_pins(float new_position, std::array<float, number_of_driver_pins> output_pinout)
{

    int new_position_int = (int)std::round(new_position);

    for (int i = 0; i < number_of_driver_pins; i++)
    {
        digitalWrite(output_pinout[i], (new_position_int >> i) & 1);
    }
}

void Driver::write_position()
{
    digitalWrite(this->latch_pins[0], 0);
    digitalWrite(this->latch_pins[1], 0);
    std::this_thread::sleep_for(this->latch_time);
    digitalWrite(this->latch_pins[0], 1);
    digitalWrite(this->latch_pins[1], 1);
}