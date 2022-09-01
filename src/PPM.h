//
// Created by jaden on 8/31/2022.
//

#ifndef OPENGL_BRESENHAM_LINE_ALGORITHM_PPM_H
#define OPENGL_BRESENHAM_LINE_ALGORITHM_PPM_H

#include "Color.h"
#include <string>
#include <vector>

class PPM {
private:
    int width;
    int height;
    std::vector<std::vector<Color>> ppm;

public:
    PPM();

    PPM(std::vector<std::vector<Color>> ppm, int width, int height);

    void setPPM(std::vector<std::vector<Color>> ppm, int width, int height);

    int getWidth();

    int getHeight();

    void save(std::string name);

    Color getColor(int widthIndex, int heightIndex);

    static PPM load(std::string fileLocation);

    ~PPM();

};

#endif //OPENGL_BRESENHAM_LINE_ALGORITHM_PPM_H
