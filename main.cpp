#include <iostream>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace fractal;

int main() {
    int const WIDTH = 800;
    int const HEIGHT = 600;
    
    Bitmap bitmap{WIDTH, HEIGHT};

    double min = 999999;
    double max = -999999;

    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            double xFractal = (x - WIDTH / 2) * 2.0 / WIDTH;
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

            if (xFractal < min) {
                min = xFractal;
            }

            if (xFractal > max) {
                max = xFractal;
            }

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            uint8_t val = (iterations / (double)Mandelbrot::MAX_ITERATIONS) * 255;
            bitmap.setPixel(x, y, val, val, val);
        }
    }

    cout << min << ", " << max << endl;

    bitmap.write("test.bmp");

    return 0;
}