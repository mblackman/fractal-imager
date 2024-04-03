#ifndef RGB_H_
#define RGB_H_

#include <cstdint>

using namespace std;

namespace fractal {

class RGB {
public:
    double r{0};
    double g{0};
    double b{0};
    RGB(double red, double green, double blue);
};

RGB operator-(const RGB &lhs, const RGB &rhs);

}

#endif // !RGB_H_