#ifndef SCANNER_H
#define SCANNER_H

#include <functional>

#include "../include/global.hpp"
#include "../include/Estimator.hpp"

class Scanner{
    public: 
        Scanner(Observations* sensor_output, Position* driver_input, Estimator* velocity_estimator, std::function<float()> get_time, Parameters* parameters){
            this->sensor_output = sensor_output;
            this->driver_input = driver_input;
            this->velocity_estimator = velocity_estimator;
            this->global_get_time_function = get_time;
            this->parameters = parameters;
        }
        float get_time(){return this->global_get_time_function();};
        void run(){while(true) this->tick();}
        void tick();
        void search(std::vector<float>, std::vector<float>);
        void update_estimate(){
            std::vector<float> instantaneous_velocity = this->velocity_estimator->get_estimated_velocity();
            float new_time = this->get_time();
            this->est_x += instantaneous_velocity[0] * (new_time - this->current_time);
            this->est_y += instantaneous_velocity[1] * (new_time - this->current_time);
        }

    private:
        Observations* sensor_output;
        Position* driver_input;
        Estimator* velocity_estimator;
        Parameters* parameters;
        float current_x, current_y,
                est_x, est_y, 
                current_time;
        int points_searched = 0;
        std::function<float()> global_get_time_function;
};

#endif