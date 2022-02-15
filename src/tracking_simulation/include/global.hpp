#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>

struct tuple {
    tuple(float new_a, float new_b){
        this->a = new_a;
        this->b = new_b;
    }
    float a, b;     
    friend std::ostream& operator<<(std::ostream& os, const tuple& t) {
        os << "(" << t.a << ", " << t.b << ")";
		return os;
	}
};
typedef struct tuple tuple;

#endif