#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

// This aligns the fields with 2 byte boundaries. This prevents packing and padding.
#pragma pack(2)

struct BitmapFileHeader {
    char header[2]{'B', 'M'};
    int32_t fileSize; // int32_t ensures this is a 32-bit int across platforms.
    int32_t reserved{0};
    int32_t dataOffset;
};

#endif