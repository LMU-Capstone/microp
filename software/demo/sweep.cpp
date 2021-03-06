

#include "./include/driver.hpp"
#include "./include/shared_structures.hpp"
#include "./include/global.h"

#include <memory>
#include <array>
#include <iostream>
#include <string>
#include <thread>

int main()
{
    // Position position;
    std::shared_ptr<Position> pos_ptr = std::make_shared<Position>();

    std::array<float, number_of_driver_pins> x_pins = {
        // 21, 19, 15, 13, 3, 5, 7, 11
        13, 12, 3, 2, 8, 9, 7, 0};
    std::array<float, number_of_driver_pins> y_pins = {
        // 22, 18, 16, 12, 24, 26, 32, 36
        6, 5, 4, 1, 10, 11, 26, 27};
    std::array<float, 2> latch_pins = {
        // 38, 40
        28, 29};

    Driver driver(pos_ptr, x_pins, y_pins, latch_pins);

    auto driver_thread = driver.spawn();
    
    
    for(int i = 0; i < 3; i++){
        for (float x = 0; x <= 255; x++)
        {
            for (float y = 0; y <= 255; y++)
            {
                pos_ptr->set_position({x,y});
                std::this_thread::sleep_for(std::chrono::microseconds(100));
            }
        }
    }
    
    // std::cout << "hello" << std::endl;
    driver.kill();
    driver_thread.join();
}