#ifndef OBSERVATIONS_H
#define OBSERVATIONS_H

#include <vector>
#include <mutex>
#include <algorithm>
#include <iostream>
/*

Implementation notes:
1. 
It is unclear if it is more efficient to perform comparisons on every add or 
    on a getter call
Intuitively, the second; however, the timing may affect this
so as an alternative code:
add_observation(newObs){
    this->observations = this_>obvserations || newObs;
}
get_observation(){return this->observations;}

2. do we need to delete if std::Vector is member ?
*/

class Observations{
    public:
        Observations(){
            this->list_of_observations = {};
            this->list_of_observations.reserve(sizeof(bool)*10); //reduce allocation time (hopefully)
        }; // constructor
        // ~ Observations(){
        //     delete this->list_of_observations;
        // }; // destructor
        Observations(Observations& newObs){
            for(auto i = this->list_of_observations.begin(); i != this->list_of_observations.end(); i++)
                newObs.list_of_observations.push_back(*i);
        }; // copy constructor
        Observations(Observations&& newObs){
            newObs.list_of_observations = this->list_of_observations;
        }; // move constructor

        void add_observation(bool observation){
            std::lock_guard<std::mutex> guard(this->access_mutex);
            this->list_of_observations.push_back(observation);
        }

        bool get_observation(){
            std::lock_guard<std::mutex> guard(this->access_mutex);
            bool ret = this->collapse_observations();
            this->list_of_observations.clear();
            return ret;
        }

        std::vector<bool> get_list_of_observations(){
            // for debugging purposes and output
            return this->list_of_observations;
        }

        friend std::ostream& operator<<(std::ostream& os, Observations& observations) {
            auto list_of_observations = observations.get_list_of_observations();
            os << "Observations: [";
            for(auto i = list_of_observations.begin(); i != list_of_observations.end(); i++)
                os << *i << ", ";
            os << "]" << "-> " << observations.collapse_observations() << "|";

            return os;
        }

    private:
        inline bool collapse_observations() {
          if(this->list_of_observations.size() == 0){
            return false;
          }
            return !std::none_of(this->list_of_observations.begin(), this->list_of_observations.end(), [](bool v){return v;});
        }
        std::vector<bool> list_of_observations;
        std::mutex access_mutex;
};

#endif

#ifndef POSITION
#define POSITION

#include <vector>
#include <mutex>
#include <iostream>

class Position{
    public:
        Position(){
            position.reserve(sizeof(float)*2);
        };
        Position(Position& newPos){
            for(auto i = this->position.begin(); i != this->position.end(); i++)
                newPos.position.push_back(*i);
        };
        Position(Position&& newPos){
            newPos.position = this->position;
        };

        void set_position(std::vector<float> new_position){
            std::lock_guard<std::mutex> guard(this->access_mutex);
            this->position[0] = new_position[0];
            this->position[1] = new_position[1];
            this->updated_position = true;
        }
        std::vector<float> get_position(){
            std::lock_guard<std::mutex> guard(this->access_mutex);
            this->updated_position = false;
            return {this->position[0], this->position[1]};
        }

        bool is_updated(){
            std::lock_guard<std::mutex> guard(this->access_mutex);
            return this->updated_position;
        }

        friend std::ostream& operator<<(std::ostream& os, Position& position) {
            auto current_position = position.get_position();
            os << "Position: [";
            for(auto i = current_position.begin(); i != current_position.end(); i++)
                os << *i << ", ";
            os << "]";
            return os;
        }

    private:
        std::vector<float> position;
        std::mutex access_mutex;
        bool updated_position = false;
};
typedef Position Position;

#endif