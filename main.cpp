#include <iostream>
#include <cstdint>
#include <memory>
#include "Bitmap.h"
#include "Mandelbrot.h"

using namespace std;
using namespace fractal;

int main() {
    int const WIDTH = 800;
    int const HEIGHT = 600;
    
    Bitmap bitmap{WIDTH, HEIGHT};

    unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});

    for (int y=0; y<HEIGHT; y++) {
        for (int x=0; x<WIDTH; x++) {
            double xFractal = (x - WIDTH / 2 - 200) * 2.0 / HEIGHT;
            double yFractal = (y - HEIGHT / 2) * 2.0 / HEIGHT;

            int iterations = Mandelbrot::getIterations(xFractal, yFractal);
            
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                histogram[iterations]++;
            }

            uint8_t color = (uint8_t)((iterations / (double)Mandelbrot::MAX_ITERATIONS) * 256);

            color = color * color * color;

            bitmap.setPixel(x, y, color, color, color);
        }
    }

    bitmap.write("test.bmp");

    int count = 0;
    for (int i=0; i<=Mandelbrot::MAX_ITERATIONS; i++) {
        cout << histogram[i] << " " << flush;
        count += histogram[i];
    }

    cout << endl << count << "; " << WIDTH*HEIGHT << endl;

    return 0;
}