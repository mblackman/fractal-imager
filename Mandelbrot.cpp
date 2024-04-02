#include "Mandelbrot.h"

using namespace fractal;

namespace fractal {

int Mandelbrot::getIterations(double x, double y) {
    double pX = x;
    double pY = y;
    double xVal = 0;
    double yVal = 0;
    int iteration = 0;

    while (xVal * xVal + yVal * yVal <= 4 && iteration < MAX_ITERATIONS) {
        double xTemp = xVal * xVal - yVal * yVal + pX;
        yVal = 2 * xVal * yVal + pY;
        xVal = xTemp;
        iteration++;
    }

    return iteration;
}

}