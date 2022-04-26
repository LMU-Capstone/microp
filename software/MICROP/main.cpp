
#include <array>
#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "./include/camera.hpp"
#include "./include/driver.hpp"
#include "./include/global.h"
#include "./include/shared_structures.hpp"

int main() {
  std::shared_ptr<Position> shared_position = std::make_shared<Position>();
  std::shared_ptr<Observations> shared_observation =
      std::make_shared<Observations>();

  std::array<float, number_of_driver_pins> x_pins = {
      // 21, 19, 15, 13, 3, 5, 7, 11
      13, 12, 3, 2, 8, 9, 7, 0};
  std::array<float, number_of_driver_pins> y_pins = {
      // 22, 18, 16, 12, 24, 26, 32, 36
      6, 5, 4, 1, 10, 11, 26, 27};
  std::array<float, 2> latch_pins = {// 38, 40
                                     28, 29};

  Driver driver(shared_position, x_pins, y_pins, latch_pins);
  Camera camera(shared_observation, 155);

  auto driver_thread = driver.spawn();
  auto camera_thread = camera.spawn();
}