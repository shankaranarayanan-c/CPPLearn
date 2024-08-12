#include<string>

static double pi{3.141};
const int twice{2};
constexpr int thrice{3};

std::string gMessage="Hi";

static double calculateRadiusSquare(double radius);

double areaOfCircle(double radius){
    return pi * calculateRadiusSquare(radius);
}

static double calculateRadiusSquare(double radius){                             // static functions are visible only locally to TU
    return radius * radius;
}
