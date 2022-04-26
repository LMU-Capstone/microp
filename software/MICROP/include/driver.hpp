#ifndef DRIVER_H
#define DRIVER_H

#include <wiringPi.h>

#include <array>
#include <chrono>
#include <memory>
#include <thread>

#include "../include/global.h"
#include "../include/shared_structures.hpp"

class Driver {
 public:
  Driver(std::shared_ptr<Position> shared_position, int wait_time,
         int latch_time, std::array<float, number_of_driver_pins> x_pins,
         std::array<float, number_of_driver_pins> y_pins,
         std::array<float, 2> latch_pins)
      : wait_time{std::chrono::nanoseconds(wait_time)},
        latch_time{std::chrono::nanoseconds(latch_time)},
        shared_position{shared_position} {
    wiringPiSetup();
    for (auto i = 0; i < number_of_driver_pins; i++) {
      this->x_pins[i] = x_pins[i];
      pinMode(x_pins[i], OUTPUT);
      this->y_pins[i] = y_pins[i];
      pinMode(y_pins[i], OUTPUT);
    }
    for (int i = 0; i < 2; i++) {
      this->latch_pins[i] = latch_pins[i];
      pinMode(this->latch_pins[i], OUTPUT);
    }
    digitalWrite(this->latch_pins[0], 1);
    digitalWrite(this->latch_pins[1], 1);
  };

  Driver(std::shared_ptr<Position> shared_position,
         std::array<float, number_of_driver_pins> x_pins,
         std::array<float, number_of_driver_pins> y_pins,
         std::array<float, 2> latch_pins)
      : shared_position{shared_position},
        latch_time{std::chrono::nanoseconds(1000)},
        wait_time{std::chrono::nanoseconds(1000)} {
    wiringPiSetup();
    for (auto i = 0; i < number_of_driver_pins; i++) {
      this->x_pins[i] = x_pins[i];
      pinMode(x_pins[i], OUTPUT);
      this->y_pins[i] = y_pins[i];
      pinMode(y_pins[i], OUTPUT);
    }
    for (int i = 0; i < 2; i++) {
      this->latch_pins[i] = latch_pins[i];
      pinMode(this->latch_pins[i], OUTPUT);
    }
    digitalWrite(this->latch_pins[0], 1);
    digitalWrite(this->latch_pins[1], 1);
  };
  bool is_running();
  void run();
  void kill();
  void start();
  std::thread spawn() { return std::thread(&Driver::run, this); }

 private:
  void update_position(std::vector<float>);
  void update_pins(float, std::array<float, number_of_driver_pins>);
  void write_position();

  std::chrono::nanoseconds wait_time, latch_time;

  std::shared_ptr<Position> shared_position;

  std::array<float, number_of_driver_pins> x_pins, y_pins;
  std::array<float, 2> latch_pins;
  std::mutex check_running_mutex;
  bool running = true;
};

#endif