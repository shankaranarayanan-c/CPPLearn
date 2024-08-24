#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace math{                                             // inline variables are extern linkage by default
    inline constexpr double pi{3.141};                      // constexpr function are inline by default but constexp variables are not inline
}                                                           // compiler may optimize as compile time constants and replace the var with value

#endif