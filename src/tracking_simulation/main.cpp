#include <iostream>
#include <chrono>
#include <functional>
#include <vector>

#include "include/global.hpp"
#include "include/Pattern.hpp"
#include "include/Receiver.hpp"

double time_function(std::function<void()> );


int main() { 

    Pattern pattern;
    std::vector<float> temp = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    pattern.set_pattern({1,2,3,4,5,6,7,8,9,10,11,12,13,14});

    while(!pattern.is_done()){
        std::cout << pattern.get_next_vector() << std::endl;
    }

    Receiver r;
    r.set_point({1,2});
    std::cout << r << std::endl;
    r.tick(1.5); 

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