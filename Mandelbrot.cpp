#include <complex>
#include "Mandelbrot.h"

using namespace std;
using namespace fractal;

namespace fractal {

int Mandelbrot::getIterations(double x, double y) {
    complex<double> z = 0;
    complex<double> c(x, y);
    int iteration = 0;

    while (abs(z) <= 2 && iteration < MAX_ITERATIONS) {
        z = z*z + c;
        iteration++;
    }

    return iteration;
}

}