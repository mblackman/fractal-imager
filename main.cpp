#include <iostream>
#include "Bitmap.h"

using namespace std;
using namespace fractal;

int main() {
    Bitmap bitmap{400, 400};

    bitmap.write("test.bin");
    
    return 0;
}