#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "ZoomList.h"
#include "Bitmap.h"

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

public:
    FractalCreator(int width, int height);

    void calculateIteration();
    void drawFractal();
    void addZoom(const Zoom & zoom);
    void writeBitmap(string name);
};

}

#endif // !FRACTALCREATOR_H_