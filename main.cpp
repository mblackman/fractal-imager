#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace fractal;

int main() {
    Bitmap bitmap{400, 400};

    for (int i = 100; i<=300; i++) {
        for (int j = 100; j <=300; j++) {
            bitmap.setPixel(i, j, i % 255, j % 255, (i + j) % 255);
        }
    }

    bitmap.write("test.bmp");

    return 0;
}