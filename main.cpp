#include <iostream>
#include "FractalCreator.h"
#include "Rgb.h"

using namespace std;
using namespace fractal;

int main() {

    int const WIDTH = 800;
    int const HEIGHT = 600;

    FractalCreator fractalCreator(WIDTH, HEIGHT);

    fractalCreator.addZoom(Zoom(WIDTH/2, HEIGHT/2, 4.0/WIDTH));
    fractalCreator.addZoom(Zoom(295, HEIGHT - 202, 0.1));
    fractalCreator.addZoom(Zoom(350, HEIGHT - 370, 0.1));

    fractalCreator.addColorRange(0, RGB(0, 0, 0));
    fractalCreator.addColorRange(0.3, RGB(255, 0, 0));
    fractalCreator.addColorRange(0.5, RGB(255, 255, 0));
    fractalCreator.addColorRange(1.0, RGB(255, 255, 255));

    fractalCreator.run("test.bmp");

    return 0;
}