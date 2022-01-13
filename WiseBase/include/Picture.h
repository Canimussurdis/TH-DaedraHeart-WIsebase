#ifndef PICTURE_H
#define PICTURE_H

#include "BaseFileReader.h"
#include <fstream>

class Picture : public BaseFileReader {
public:
    BaseFileReader* addPicture(const std::string& filename);

    void deletePicture(const std::string& filename);
};

#endif // PICTURE_H
