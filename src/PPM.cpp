//
// Created by jaden on 8/31/2022.
//

#include "PPM.h"
#include "Color.h"
#include <iostream>
#include <fstream>

// Defines a PPM
PPM::PPM(std::vector<std::vector<Color>> ppm, int width, int height) {
    this->ppm = ppm;
    this->width = width;
    this->height = height;
}

// Redefines a ppm
void PPM::setPPM(std::vector<std::vector<Color>> ppm, int width, int height) {
    this->ppm = ppm;
    this->width = width;
    this->height = height;
}

// returns the width of the PPM
int PPM::getWidth() {
    return width;
}

// returns the height of the PPM
int PPM::getHeight() {
    return height;
}

// returns a color object at a coordinate
Color PPM::getColor(int widthIndex, int heightIndex) {
    if (widthIndex > width || heightIndex > height) {
        throw std::invalid_argument(
                "The pixel indexes must be in between " + std::to_string(width) + "and " + std::to_string(height));
    }
    return ppm[widthIndex][heightIndex];
}

// Creates a PPM file of given name with the stored color values;
void PPM::save(std::string name) {
    std::ofstream img(name + ".ppm");
    img << "P3" << std::endl;
    img << width << " " << height << std::endl;
    img << "255" << std::endl;
    for (int i = 0; i < width; i++) {
        img << std::endl;
        for (int j = 0; j < height; j++) {
            img << ppm[i][j].getRed() << " " << ppm[i][j].getGreen() << " " << ppm[i][j].getBlue() << "\t";
        }
    }
    img.close();
}


// reads in a ppm of a specific format.
PPM PPM::load(std::string fileLocation) {
    std::ifstream img;
    img.open(fileLocation);
    if (!img.is_open()) { throw std::runtime_error("Could not find file at " + fileLocation); }
    std::string text;
    img >> text;
    std::string type = text;
    img >> text;
    int width = std::stoi(text);
    img >> text;
    int height = std::stoi(text);
    img >> text;
    int range = std::stoi(text);

    std::vector<std::vector<Color>> ppm(width, std::vector<Color>(height, 0));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            img >> text;
            int r = std::stoi(text);
            img >> text;
            int g = std::stoi(text);
            img >> text;
            int b = std::stoi(text);

            Color c = Color(r, g, b);

            ppm[i][j] = c;
        }
    }
    return PPM(ppm, width, height);

}

PPM::~PPM() {
    ppm.clear();
    width = 0;
    height = 0;
}