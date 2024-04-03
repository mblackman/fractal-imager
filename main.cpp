#include <iostream>
#include "FractalCreator.h"

using namespace std;
using namespace fractal;

int main() {
    FractalCreator fractalCreator(800, 600);

    int const WIDTH = 800;
    int const HEIGHT = 600;


    fractalCreator.addZoom(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    fractalCreator.addZoom(Zoom(295, HEIGHT - 202, 0.1));
    fractalCreator.addZoom(Zoom(350, HEIGHT - 370, 0.1));

    fractalCreator.calculateIteration();
    fractalCreator.drawFractal();
    fractalCreator.writeBitmap("test.bmp");

    return 0;
}