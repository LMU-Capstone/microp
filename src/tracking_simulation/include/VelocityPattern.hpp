#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include <algorithm>
#include "../include/global.hpp"

struct VelocityPattern
{
    public:
        VelocityPattern();
        VelocityPattern(std::vector<std::vector<float>> new_pattern){this->set_pattern(new_pattern);}

        void set_pattern(std::vector<std::vector<float>> new_pattern){
            
            for(auto i = pattern.begin(); i != pattern.end(); i++){
                if((*i).size() != 3) throw std::invalid_argument("Pattern invalid");
            }

            for(auto i = new_pattern.begin(); i != new_pattern.end(); i++){
                this->pattern.push_back({(*i)[0], (*i)[1], (*i)[2]}); // bug-fix: deep copy to avoid scope issues
            }

            this->sort_pattern();

            if(!this->validate_pattern(this->pattern)) throw std::logic_error("Unknown error: Pattern invalid");

            this->last_velocity = this->pattern.begin();
        }
        
        bool validate_pattern(std::vector<std::vector<float>> pattern){
            float last_time = -1;
            for(auto i = pattern.begin(); i != pattern.end(); i++){
                if((*i).size() != 3) return false;
                if((*i)[2] < last_time) return false;
                last_time = (*i)[2];
            }
            return true;
        }

        void sort_pattern(){
            //https://stackoverflow.com/questions/31370380/c-method-to-order-a-matrix-by-elements-in-a-column-the-same-of-sortrows-in-ma
            std::sort(this->pattern.begin(), this->pattern.end(),
                        [](const std::vector<float>& lhs, const std::vector<float>& rhs){
                            return lhs[2] < rhs[2];
                        });
        }


        float final_time(){
            return (*(this->pattern.end()-1))[2];
        }

        std::vector<float> get_current_velocity(float current_time){
            if(current_time < 0) throw std::invalid_argument("Time cannot be negative");
            
            // search from the last time to now (likely only going forward in time)
            for(auto it = this->last_velocity; it < this->pattern.end(); it++){
                if(current_time < (*it)[2] ){
                    this->last_velocity = it;
                    return {(*it)[0], (*it)[1]}; // return primitives for scoping issues
                }
            }
            //if not found, try searching from start to current position
            for(auto it = this->pattern.begin(); it < this->last_velocity; it++){
                if(current_time < (*it)[2] ){
                    this->last_velocity = it;
                    return {(*it)[0], (*it)[1]}; // return primitives for scoping issues
                }
            }

            throw std::invalid_argument("Time is outside of scope of the pattern");
            return {-1,-1};
        }

        std::vector<std::vector<float>> get_pattern(){return this->pattern;};

    friend std::ostream& operator<<(std::ostream& os, VelocityPattern& velocity_pattern) {
        auto pattern = velocity_pattern.get_pattern();
        os << "{" << std::endl;
        for(auto i = pattern.begin(); i != pattern.end(); i++){
            os << "\t< " << (*i)[0] << ", " << (*i)[1] << ", " << (*i)[2] << " >," << std::endl;
        }
        os << "}" << std::endl;
        
		return os;
	}

    private:
        std::vector<std::vector<float>> pattern;
        std::vector<std::vector<float>>::iterator last_velocity;


};
typedef struct Pattern Pattern;

#endif