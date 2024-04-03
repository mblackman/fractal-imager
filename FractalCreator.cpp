#include <math.h>
#include <tuple>

#include "Zoom.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "FractalCreator.h"
#include "Rgb.h"
using namespace std;
using namespace fractal;

namespace fractal {

void FractalCreator::run(string name) {
    calculateIteration();
    calculateRangeTotals();
    drawFractal();
    writeBitmap(name);
}

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
            int iterations = m_fractal[y * m_width + x] ;
            int range = getRange(iterations);
            int rangeTotal = m_rangeTotals[range];
            int rangeStart = m_rangeEnds[range];
            RGB &startColor = m_rangeColors[range];
            RGB &endColor = m_rangeColors[range + 1];
            RGB colorDiff = endColor - startColor;

            uint8_t red = 0;
            uint8_t green = 0;
            uint8_t blue = 0;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                double totalPixels = 0;
                for (int i = rangeStart; i <= iterations; i++) {
                    totalPixels += m_histogram[i];
                }
                
                red = startColor.r + colorDiff.r * (double)totalPixels/rangeTotal;
                green = startColor.g + colorDiff.g * (double)totalPixels/rangeTotal;
                blue = startColor.b + colorDiff.b * (double)totalPixels/rangeTotal;
            }

            m_bitmap.setPixel(x, y, red, green, blue);
        }
    }
}

void FractalCreator::addZoom(const Zoom &zoom) {
    m_zoomList.add(zoom);
}

void FractalCreator::addColorRange(double rangeEnd, const RGB &color) {
    m_rangeEnds.push_back(rangeEnd * Mandelbrot::MAX_ITERATIONS);
    m_rangeColors.push_back(color);

    if (m_bGotFirstRange) {
        m_rangeTotals.push_back(0);
    }

    m_bGotFirstRange = true;
}

void FractalCreator::calculateRangeTotals() {

    int rangeIndex = 0;

    for (int i=0; i<Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = m_histogram[i];

        if (i >= m_rangeEnds[rangeIndex + 1]) {
            rangeIndex++;
        }

        m_rangeTotals[rangeIndex] += pixels;
    }
}

int FractalCreator::getRange(int iterations) const {
    int range = 0;

    for (int i=1; i<m_rangeEnds.size(); i++) {

        range = i;

        if (m_rangeEnds[i] > iterations) {
            break;
        }
    }

    range--;

    assert(range > -1);
    assert(range < m_rangeEnds.size());

    return range;
}

void FractalCreator::writeBitmap(string name) {
    m_bitmap.write(name);
}

}