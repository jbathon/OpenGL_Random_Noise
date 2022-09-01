#include <GL/freeglut.h>
#include <random>
#include <iostream>
#include <fstream>
#include "WindowBuilder.h"
#include "Color.h"
#include "PPM.h"


PPM genNoise(int width, int height) {
    std::vector<std::vector<Color>> ppm(width, std::vector<Color>(height, 0));
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            ppm[i][j] = Color();
        }
    }

    return PPM(ppm, width, height);
}

PPM noise = genNoise(300, 300);

PPM getNoise() {
    return noise;
}

// initializes the glut window
void init() {

    // Setting the default color of the window
    glClearColor(0, 0, 0, 0.0);

    // Setting window defaults
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, glutGet(GLUT_WINDOW_WIDTH), 0.0, glutGet(GLUT_WINDOW_HEIGHT), -1.0, 1.0);

};

// Tells the window what to display
void display() {

    // Sets pixels to default values
    glClear(GL_COLOR_BUFFER_BIT);

    // Begins drawing on the window
    glBegin(GL_POINTS);

    // Changes Pixel color based on the RBG values in our noise PPM
    for (int i = 0; i < noise.getWidth(); i++) {

        for (int j = 0; j < noise.getHeight(); j++) {

            glColor3ub(
                    noise.getColor(i, j).getRed(),
                    noise.getColor(i, j).getGreen(),
                    noise.getColor(i, j).getBlue()
            );
            glVertex2i(i, j);

        }
    }
    // Ends drawing on the window
    glEnd();
    glFlush();
}


