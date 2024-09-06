#ifndef MATHVALUE_H
#define MATHVALUE_H

#include<iostream>

inline int getCMForaMetre(){                //though each source file receives a copy of this function the linker sees inline and consoldates to 1 funtion
    return 100;                             //this satisfies the ODR.
}

#endif