#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"

using namespace fractal;
using namespace std;

namespace fractal {

Bitmap::Bitmap(int width, int height): 
    m_width(width), m_height(height), m_pixels(new uint8_t[width * height * 3]{}) {

}

bool Bitmap::write(string filename) {

    BitmapFileHeader bitmapFileHeader;
    BitmapInfoHeader bitmapInfoHeader;
    ofstream file;

    bitmapFileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width*m_height*3;
    bitmapFileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    bitmapInfoHeader.width = m_width;
    bitmapInfoHeader.height = m_height;

    file.open(filename, ios::out|ios::binary);

    if (!file) {
        return false;
    }

    file.write((char *) &bitmapFileHeader, sizeof(bitmapFileHeader));
    file.write((char *) &bitmapInfoHeader, sizeof(bitmapInfoHeader));
    file.write((char *) m_pixels.get(), m_width *m_height*3);

    file.close();

    if (!file) {
        return false;
    }

    return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t *pPixel = m_pixels.get();

    pPixel += y * 3 * m_width + x * 3;
    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

Bitmap::~Bitmap() {

}

}