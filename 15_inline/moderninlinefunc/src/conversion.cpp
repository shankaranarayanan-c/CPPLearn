#include "mathvalue.hpp"

int getCMForaMetre();

inline int convertMetreToCM(int metre){
    return metre * getCMForaMetre();
}