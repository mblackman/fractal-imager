#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <tuple>
#include <vector>
#include "Zoom.h"

using namespace std;
using namespace fractal;

namespace fractal {

class ZoomList {
private:
    double m_xCenter{0};
    double m_yCenter{0};
    double m_scale{1};
    int m_width{0};
    int m_height{0};
    vector<Zoom> zooms;

public:
    ZoomList(int width, int height);
    void add(const Zoom &zoom);
    tuple<double, double> doZoom(int x, int y);
};

}

#endif // !ZOOMLIST_H_