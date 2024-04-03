#include <iostream>
#include <math.h>
#include <tuple>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "FractalCreator.h"

using namespace std;
using namespace fractal;

namespace fractal {

FractalCreator::FractalCreator(int width, int height): 
    m_width(width), m_height(height), m_fractal(new int[width*height]{0}), 
    m_zoomList(width, height), m_bitmap(width, height) {

}

void FractalCreator::calculateIteration() {
    for (int y=0; y<m_height; y++) {
        for (int x=0; x<m_width; x++) {
            auto zoom = m_zoomList.doZoom(x, y);

            int iterations = Mandelbrot::getIterations(get<0>(zoom), get<1>(zoom));
            m_fractal[y * m_width + x] = iterations;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                m_histogram[iterations]++;
            }
        }
    }
}

void FractalCreator::drawFractal() {
    int total = 0;
    for (int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += m_histogram[i];
    }

    for (int y=0; y<m_height; y++) {
        for (int x=0; x<m_width; x++) {
            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;
            int iterations = m_fractal[y * m_width + x] ;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                double hue = 0;
                for (int i = 0; i <= iterations; i++) {
                    hue += ((double)m_histogram[i]) / total;
                }
                
                green = pow(255, hue);
            }

            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::addZoom(const Zoom &zoom) {
    m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(string name) {
    m_bitmap.write(name);
}

}