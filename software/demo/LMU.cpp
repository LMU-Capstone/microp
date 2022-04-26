

#include "./include/driver.hpp"
#include "./include/shared_structures.hpp"
#include "./include/global.h"

#include <memory>
#include <array>
#include <iostream>
#include <string>
#include <thread>

std::vector<std::vector<float>> LMU_coordinates = {
        {100, 75},
        {117, 75},
        {119, 23},
        {125, 17},
        {131, 23},
        {133, 75},
        {150, 75},
        {150, 20},
        {140, 5},
        {125, 0},
        {110, 5},
        {100, 20},
        {100, 75},
        {83, 75},
        {75, 60},
        {67,75},
        {50, 75},
        {50, 20},
        {30, 20},
        {30, 75},
        {0, 75},
        {0, 0},
        {50, 0},
        {67, 0},
        {67, 50},
        {71, 40},
        {79, 40},
        {83, 50},
        {83, 0},
        {100, 0},
        {100, 75}
    };
std::vector<float> LMU(int i){
    auto coor = LMU_coordinates[i%LMU_coordinates.size()];
    return {255-coor[0], coor[1]};
};

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
    
    
    for(int i = 0; i < 100000; i++){
        pos_ptr->set_position(LMU(i));
        std::this_thread::sleep_for(std::chrono::microseconds(300));
    }
    
    // std::cout << "hello" << std::endl;
    driver.kill();
    driver_thread.join();
}
