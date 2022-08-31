//
// Created by jaden on 8/31/2022.
//

#include "PPM.h"
#include <iostream>
#include <fstream>

PPM::PPM(Color ** ppm) {
    this->ppm = ppm;
    width = sizeof(ppm)/sizeof(ppm[0]);
    height = sizeof(ppm[0])/sizeof(ppm[0][0]);
}

int PPM::getWidth() {
    return width;
}

int PPM::getHeight() {
    return height;
}

Color PPM::getColor(int widthIndex, int heightIndex) {
    if (widthIndex > width || heightIndex > height) {
        throw std::invalid_argument("The pixel indexes must be in between " + std::to_string(width) + "and " + std::to_string(height));
    }
    return ppm[widthIndex][heightIndex];
}

void PPM::save(std::string name) {
    std::ofstream img(name + ".ppm");
    img << "P3" << std::endl;
    img << width << " " << height << std::endl;
    img << "255" << std::endl;
    for (int i = 0; i < width; i++) {
        img << std::endl;
        for (int j = 0; j < height; j++) {
            img << ppm[i][j].getRed()  << " " << ppm[i][j].getGreen() << " " << ppm[i][j].getBlue() << "\t";
        }
    }
    img.close();
}

PPM PPM::load(std::string fileLocation) {
    std::ifstream img;
    img.open(fileLocation);
    if(!img.is_open()) { throw std::runtime_error("Could not find file at " + fileLocation);}
    std::string text;
    img >> text;
    str::string type = text;
    img >> text;
    int width = std::stoi(text);
    img >> text;
    int height = std::stoi(text);
    img >> text;
    int range = std::stoi(text);

    Color** ppm = new Color*[width];
    for (int i = 0; i < width; i++) {
        ppm[i] = new Color[height];
        for (int j = 0; j < height; j++) {
            img >> text;
            int r = std::stoi(text);
            img >> text;
            int g = std::stoi(text);
            img >> text;
            int b = std::stoi(text);

            Color c = new Color(r,g,b);

            ppm[i][j] = c;
        }
    }
    return PPM(ppm);

}