//
// Created by jaden on 8/31/2022.
//

#include "Color.h"
#include <random>

void Color::getRandomColor() {
    int red = rand()%255;
    int blue = rand()%255;
    int green = rand()%255;
    int alpha = rand()%255;
    int rgba[] = {red,blue,green,alpha};

    this->rgba = rgba;
}

void Color::getRandomColor(int alpha) {
    int red = rand()%255;
    int blue = rand()%255;
    int green = rand()%255;
    int rgba[] = {red,blue,green,alpha};

    this->rgba = rgba;
}

Color::Color() {
    getRandomColor();
}

Color::Color(int alpha) {
    getRandomColor(alpha);
}

Color::Color(int red, int green, int blue) {
    int temp[] = {red,blue,green,1};
    rgba =  temp;
}

Color::Color(int red, int green, int blue, int alpha) {
    int temp[] = {red,blue,green,alpha};
    rgba = temp;
}

Color::Color(int* rgba) {
    this->rgba = rgba;
}

void Color::set(int red, int green, int blue) {
    int temp[] = {red,blue,green,1};
    rgba = temp;
}

void Color::set(int red, int green, int blue, int alpha) {
    int temp[] = {red,blue,green,alpha};
    rgba = temp;
}

void Color::set(int *rgba) {
    this->rgba = rgba;
}

int Color::getRed() {
    return rgba[0];
}

int Color::getGreen() {
    return rgba[1];
}

int Color::getBlue() {
    return rgba[2];
}

int Color::getAlpha() {
    return rgba[3];
}

int* Color::getRGBA() {
    return rgba;
}



