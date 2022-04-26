

#include "../include/scanner.hpp"

void Scanner::tick() {
  /*
  Update our location
  */

  // if we are on-target, we want to simply update with our estimate velocity
  // if we are missing, we want to initiate a search while continuing to update
  // with our estimated velocity
  //      search is handled elsewhere

  if (this->sensor_output->get_observation()) {
    std::cout << "hello from scanner " << std::endl;

    this->velocity_estimator->estimate_hit(this->current_x, this->current_y,
                                           this->current_time);
    float dt = this->get_time() - this->current_time;
    this->velocity_estimator->update_estimated_position(dt);

    // update position, estimation is good so use it again
    // stage updates
    auto est_position = this->velocity_estimator->get_estimated_position();
    this->current_x = est_position[0];
    this->current_y = est_position[1];

    this->points_searched = 0;  // no longer searching, we found a solution so
                                // reset the search param

  } else {
    // miss!
    this->velocity_estimator->estimate_miss();
    float dt = this->get_time() - this->current_time;
    this->velocity_estimator->update_estimated_position(dt);

    // update position, estimation is BAD so start a search
    this->search(this->velocity_estimator->get_estimated_position(),
                 this->velocity_estimator->get_estimated_velocity());
  }

  // push updates
  std::cout << "hello from scanner " << std::endl;
  std::cout << "estimated position: "
            << this->velocity_estimator->get_estimated_position()[0] << ", "
            << this->velocity_estimator->get_estimated_position()[1]
            << std::endl;
  (*(this->driver_input)).update_position(this->current_x, this->current_y);
  this->current_time = this->get_time();
}

void Scanner::search(std::vector<float> est_position,
                     std::vector<float> est_velocity) {
  // not on target, need to update
  // searches outwards in hexagons, moving outwards in 'circle' steps

  uint32_t circle_number = (this->points_searched + 5) % 6;
  float radius = 1.5 * circle_number * (this->parameters->beam_width);
  float theta = PI / 3.0 * this->points_searched;

  // just trust the math on this one
  // did some matrices and pre-calculated the equations and plugged in
  this->current_x =
      (est_position[0] + radius * est_velocity[0] / fast_mag(est_velocity)) *
      radius * fast_cos(theta);
  this->current_y =
      (est_position[1] + radius * est_velocity[1] / fast_mag(est_velocity)) *
      radius * fast_sin(theta);

  this->points_searched += 1;
}