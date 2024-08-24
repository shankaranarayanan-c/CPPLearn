
extern const double g_pi{1.341};            // By default const has internal linkage and we can make them external by adding extern keyword
extern constexpr double g_exp{4.687};       // By default constexpr has internal linkage and we can make them external by adding extern keyword
int g_a{100};                               // By default non const non constexp variables have global linkage