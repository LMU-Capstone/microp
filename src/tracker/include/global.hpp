#ifndef GLOBAL_H
#define GLOBAL_H

#include <vector>
#include <mutex>
#include <stdint.h>
#include <algorithm>

#define PI 3.14159

// Multithread vector for sensor->scanner
struct Observations{
    // Observations holds whether the sensor saw the other endpoint

    public:
        void add_observation(bool observation){
            // add a new observation
            std::lock_guard<std::mutex> guard(this->access_mutex);
            this->observations.push_back(observation);
        }

        bool get_observation(){
            // return true if any observations true
            std::lock_guard<std::mutex> guard(this->access_mutex);
            bool ret = !std::none_of(this->observations.begin(), this->observations.end(), [](bool v){return v;});
            this->observations.clear();
            return ret;
        }


    private:
        std::mutex access_mutex;
        std::vector<bool> observations;
};

// Multithread struct for scanner->driver
struct Position{
    public:
        void update_position(float new_x, float new_y){
            std::lock_guard<std::mutex> guard(this->access_mutex);
            this->x = new_x;
            this->y = new_y;
        }
        std::vector<float> get_position(){
            std::lock_guard<std::mutex> guard(this->access_mutex);
            return {this->x, this->y};
        }
    private:
        std::mutex access_mutex;
        float x, y;
};

struct Parameters{
    public:
        float get_beam_width(int x, int y, int z){
            return 1;
        }

};

    /* static will allow inlining */
static float usqrt4(float val) {
    float a, b;

    if (val < 2) return val; /* avoid div/0 */

    a = 1255;       /* starting point is relatively unimportant */

    b = val / a; a = (a+b) /2;
    b = val / a; a = (a+b) /2;
    b = val / a; a = (a+b) /2;
    b = val / a; a = (a+b) /2;

    return a;
}

static float fast_cos(float theta){
    if(theta > 2*PI){
        theta -= 2*PI;
    }
    if(theta < PI/3){
        return 1;
    } else if (theta < 2*PI/3){
        return 0.5;
    } else if (theta < PI ){
        return -0.5;
    } else if (theta < 4*PI/3){
        return -1;
    } else if (theta < 5*PI/3){
        return -0.5;
    } else if (theta < 2*PI){
        return 0.5;
    }
    return 1;
}

static float fast_sin(float theta){
    if(theta > 2*PI){
        theta -= 2*PI;
    }
    if(theta < PI/3){
        return 1;
    } else if (theta < 2*PI/3){
        return 0.5;
    } else if (theta < PI ){
        return 0.5;
    } else if (theta < 4*PI/3){
        return -1;
    } else if (theta < 5*PI/3){
        return -0.5;
    } else if (theta < 2*PI){
        return -0.5;
    }
    return theta;
}

static float fast_mag(std::vector<float> v){
    // https://www.embedded.com/digital-signal-processing-tricks-high-speed-vector-magnitude-approximation/
    // max + 3*min/8
    // !(b<a)?a:b finds the min of a/b
    return ( !(v[0]<v[1])?v[0]:v[1] ) + ( !(v[0]<v[1])?v[1]:v[0]  )/2;
}

#endif