#include "Rgb.h"

using namespace fractal;

namespace fractal {

    RGB::RGB(double red, double green, double blue): r(red), g(green), b(blue) {

    }

    RGB operator-(const RGB &lhs, const RGB &rhs) {
        return RGB(lhs.r - rhs.r, lhs.g - rhs.g, lhs.b - rhs.b);
    }

}