

#include "../include/Estimator.hpp"

void Estimator::estimate_hit(float x, float y, float t){
    // estimator was correct! push a new position to past_valid positions
    std::vector<float> v = {(this->estimated_position[0] - x)/t, (this->estimated_position[1] - y)/t};
    // std::cout << "hello from estimator " << std::endl;
    this->past_velocities.push_back(v);

    this->update_estimated_velocity();
    this->reduce_velocity_confidence(); // do this second here since our velocity confidence should be moderately higher

}

void Estimator::estimate_miss(){
    // just reduce confidence in the current velocity
    this->reduce_velocity_confidence();
    this->update_estimated_velocity();
}

void Estimator::reduce_velocity_confidence(){
    // for each velocity, reduce its magntitude to reduce its effect on the end average velocity
    for(auto i = this->past_velocities.begin(); i < this->past_velocities.end(); i++){
        for(auto j = (*i).begin(); j < (*i).end(); j++){
            (*j)*(this->get_velocity_bias());
        }
    }
}

void Estimator::update_estimated_position(float dt){
    this->estimated_position[0] += dt*this->estimated_velocity[0];
    this->estimated_position[1] += dt*this->estimated_velocity[1];

}

void Estimator::update_estimated_velocity(){
    float sum_x, sum_y;
    int count;
    for(auto i = this->past_velocities.begin(); i < this->past_velocities.end(); i++){
        sum_x += (*i)[0];
        sum_y += (*i)[1];
        count ++;
    }
    for(auto i = (count-this->max_stored_velocities); i > 0; i--){
        this->past_velocities.pop_back();
    }
    std::vector<float> v = {sum_x/count, sum_y/count };
    this->estimated_velocity = v;
}




