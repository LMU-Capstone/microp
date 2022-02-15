#ifndef PATTERN_H
#define PATTERN_H

#include <vector>
#include "global.hpp"

struct Pattern
{
    public:
        void set_pattern(std::vector<float> new_pattern){
            this->pattern.clear();
            this->pattern = new_pattern;
            this->iter = this->pattern.begin();
        }
        bool is_done(){
            return this->iter ==  this->pattern.end();
        }
        tuple get_next_vector(){
            if(!this->is_done()){
                tuple ret = {*this->iter++, *this->iter++};
                return ret;
            } else{
                tuple ret = {-1.0,-1.0};
                return ret;
            }
        }
    private:
        std::vector<float> pattern;
        std::vector<float>::iterator iter;


};
typedef struct Pattern Pattern;

#endif