//
// Created by jaden on 8/31/2022.
//

#ifndef OPENGL_BRESENHAM_LINE_ALGORITHM_PPM_H
#define OPENGL_BRESENHAM_LINE_ALGORITHM_PPM_H

#include "Color.h"
#include <string>

class PPM {
    private:
        int width;
        int height;
        Color** ppm;

    public:
        PPM(Color** ppm);

        int getWidth();
        int getHeight();

        void save(std::string name);

        Color getColor(int widthIndex, int heightIndex);

        static PPM load(std::string fileLocation);

};

#endif //OPENGL_BRESENHAM_LINE_ALGORITHM_PPM_H
