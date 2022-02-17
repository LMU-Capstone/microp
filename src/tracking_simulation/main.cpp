#include <iostream>
#include <chrono>
#include <functional>
#include <vector>

#include "include/global.hpp"
#include "include/VelocityPattern.hpp"
#include "include/Receiver.hpp"

double time_function(std::function<void()> );


int main() { 

    std::vector<std::vector<float>> new_pattern = {{1,2,3}, {4,5,6}, {1,2,8}, {5,4,1}};

    VelocityPattern p(new_pattern);
    std::cout << p;

    for(float cur_time = 0.0; cur_time < 10; cur_time++){
        std::cout << p.get_current_velocity(cur_time)[0] << ", " << p.get_current_velocity(cur_time)[1] << std::endl;
    }

    std::cout << "\n";
    return 0;

}


double time_function(std::function<void()> to_run){
    double sum = 0;
    const int NUMBER_ITERATIONS = 100000;
    for (int i = 0; i < NUMBER_ITERATIONS; i++){
        auto start = std::chrono::system_clock::now();
        to_run();
        auto end = std::chrono::system_clock::now();
        sum += std::chrono::duration_cast<std::chrono::nanoseconds>((end-start)).count();
    }

    double avg =  sum * 1.0 / NUMBER_ITERATIONS;

    std::cout << "Nanoseconds to run (average): "
        << avg << '\n';

    return avg;
}