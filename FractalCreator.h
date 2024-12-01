#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include <vector>
#include <memory>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"
#include "Rgb.h"

using namespace std;

namespace fractal {

class FractalCreator {
private:
    int m_width{0};
    int m_height{0};
    unique_ptr<int[]> m_histogram{new int[Mandelbrot::MAX_ITERATIONS]{0}};
    unique_ptr<int[]> m_fractal{nullptr};
    ZoomList m_zoomList;
    Bitmap m_bitmap;
    vector<int> m_rangeEnds;
    vector<RGB> m_rangeColors;
    vector<int> m_rangeTotals;
    bool m_bGotFirstRange{false};

public:
    FractalCreator(int width, int height);
    void addZoom(const Zoom & zoom);
    void addColorRange(double rangeEnd, const RGB &color);
    void run(string name);

private:
    void calculateIteration();
    void drawFractal();
    void writeBitmap(string name);
    void calculateRangeTotals();
    int getRange(int iterations) const;     
};

}

#endif // !FRACTALCREATOR_H_