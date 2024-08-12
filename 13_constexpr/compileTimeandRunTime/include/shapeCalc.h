
#ifndef SHAPECALC_H
#define SHAPECALC_H

constexpr double PI{1.41};

int getSidesofSquare();

// designed to be executed at compile time and the definition is available across all TU. Implicitly inline
constexpr double circleCircumference(double radius){

    // From C++20
    // if (std::is_constant_evaluated()){
        
    // }
    return 2 * PI * radius;
}

//designed to be executed at run time and defintiion is needed all TU. It is also implicitly inline and fwd declaration is not allowed
constexpr double squareArea(double side){
    // getSidesofSquare();
    return side * 4;
}



#endif