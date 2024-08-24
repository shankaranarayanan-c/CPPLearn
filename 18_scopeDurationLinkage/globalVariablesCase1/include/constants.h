#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace math{                                     // compile time constant
    constexpr double pi{3.141};                     // const expr has local linkage by default so if each source file gets a copy will not cause ODR violation
}                                                   // Each TU gets its own copy and if any change is done in header all the source files includes are rebuilt

#endif