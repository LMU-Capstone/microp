#ifndef SCANNER_H
#define SCANNER_H

#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>

#include "../include/global.h"
#include "../include/shared_structures.hpp"

class Scanner {
 public:
  Scanner(std::shared_ptr<Observations> shared_observation,
          std::shared_ptr<Position> shared_position)
      : shared_observation{shared_observation},
        shared_position{shared_position} {}

  void run() {
    this->start();

    while (this->running) {
      // TODO
    }
  }

  void kill() {
    std::lock_guard<std::mutex> guard(this->check_running_mutex);
    this->running = false;
  }
  void start() {
    std::lock_guard<std::mutex> guard(this->check_running_mutex);
    this->running = true;
  }
  bool is_running() {
    std::lock_guard<std::mutex> guard(this->check_running_mutex);
    return this->running;
  }
  std::thread spawn() { return std::thread(&Scanner::run, this); }

 private:
  std::mutex check_running_mutex;
  bool running = true;
  std::shared_ptr<Observations> shared_observation;
  std::shared_ptr<Position> shared_position;
};

#endif