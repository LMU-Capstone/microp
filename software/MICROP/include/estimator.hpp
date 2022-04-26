#ifndef ESTIMATOR_H
#define ESTIMATOR_H

#include <vector>
#include <stdexcept>
#include <memory>
#include "global.hpp"

class Estimator{
    public:
        Estimator(std::shared_ptr<Parameters> parameters){
            if(parameters->velocity_bias > 1 || parameters->velocity_bias < 0) throw std::invalid_argument("Bias must be between 0 and 1");
            
            this->velocity_bias = parameters->velocity_bias;
            this->max_stored_velocities = parameters->max_stored_velocities;
            this->estimated_velocity = {0.0, 0.0};
            this->estimated_position = {0.0, 0.0};
        };

        void estimate_hit(float x, float y, float t);
        void estimate_miss();
        void update_estimated_position(float dt);
        float get_velocity_bias(){return this->velocity_bias;}

        std::vector<float> get_estimated_velocity(){return {this->estimated_velocity[0], this->estimated_velocity[1]};};
        std::vector<float> get_estimated_position(){return {this->estimated_position[0], this->estimated_position[1]};};
    private:
        void reduce_velocity_confidence();
        void update_estimated_velocity();
        
        std::vector<std::vector<float>> past_velocities;
        std::vector<float> estimated_velocity, estimated_position;
        float velocity_bias;
        int max_stored_velocities;
};

#endif