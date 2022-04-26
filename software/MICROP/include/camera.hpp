#ifndef CAMERA_H
#define CAMERA_H

#include <raspicam/raspicam.h>

#include <chrono>
#include <ctime>
#include <fstream>
#include <iostream>
#include <thread>

#include "../include/global.h"
#include "../include/shared_structures.hpp"

class Camera {
 public:
  Camera(std::shared_ptr<Observations> shared_observations,
         float observation_threshold)
      : observation_threshold{observation_threshold},
        shared_observations{shared_observations} {
    std::cout << "Please wait while camera initializes" << std::endl;
    std::this_thread::sleep_for(
        std::chrono::seconds(3));  // I swear, it needs three seconds to init
  }

  void run() {
    this->start();
    if (!this->camera.open()) {
      std::cerr << "Error opening camera!" << std::endl;
      this->kill();
      return;
    }

    unsigned char *data = new unsigned char[this->camera.getImageTypeSize(
        raspicam::RASPICAM_FORMAT_RGB)];

    while (this->running) {
      this->camera.retrieve(data, raspicam::RASPICAM_FORMAT_RGB);
      // this->shared_observations->add_observation(this->average(data) >
      //                                            this->observation_threshold);
      if(this->average(data) > this->observation_threshold){
        std::cout << "LASER SEEN\n";
      } else {
        std::cout << "NO LASER\n";
      }
    }

    delete data;
  }

  float average(unsigned char *data) {
    // get average
    float scalar1 = 1.0 / 20000.0;
    float scalar2 = 1.0 - scalar1;
    bool first_sample = true;
    float average = 0.0;
    for (int i = 2;
         i < this->camera.getImageTypeSize(raspicam::RASPICAM_FORMAT_RGB);
         i += 3) {
      float newSample = data[i];
      if (first_sample) {
        // everybody forgets the initial condition *sigh*
        average = newSample;
        first_sample = false;
      } else {
        average = (newSample * scalar1) + (average * scalar2);
      }
    }

    return average;
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
  std::thread spawn() { return std::thread(&Camera::run, this); }

 private:
  std::mutex check_running_mutex;
  std::raspicam::RaspiCam camera;
  std::shared_ptr<Observations> shared_observations;
  float observation_threshold;
  bool running = true;
};

#endif