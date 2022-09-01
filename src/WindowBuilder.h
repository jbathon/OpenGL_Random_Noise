#ifndef OPENGL_RANDOM_NOISE_WINDOWBUILDER_H
#define OPENGL_RANDOM_NOISE_WINDOWBUILDER_H

#include "PPM.h"

void init();

void display();

PPM genNoise(int width, int height);

PPM getNoise();


#endif //OPENGL_RANDOM_NOISE_WINDOWBUILDER_H
