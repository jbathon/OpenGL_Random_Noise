#include <GL/freeglut.h>
#include <random>
#include <iostream>
#include <fstream>
#include "WindowBuilder.h"

// An image array that represent a x cord, y cord and RGB values
int image[300][300][3];

// Adds random RBG values to our array
void imageBuilder() {

    for (int i = 0; i < 300; i++) {
        for (int j = 0; j < 300; j++) {

            image[i][j][0] = rand()%255;
            image[i][j][1] = rand()%255;
            image[i][j][2] = rand()%255;
        }
    }
}

// Creates a PPM file of the noise we created
void saveToPPM(int width, int height) {
    std::ofstream imgFile("noise.ppm");
    imgFile << "P3" << std::endl;
    imgFile << width << " " << height << std::endl;
    imgFile << "255" << std::endl;
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            imgFile << image[i][j][0] << " " << image[i][j][1] << " " << image[i][j][2] << std::endl;
        }
    }
    imgFile.close();
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

    // Changes Pixel color based on the RBG values in our image array
    for (int i = 0; i < 300; i++) {

        for (int j = 0; j < 300; j++) {


            glColor3ub(image[i][j][0], image[i][j][1], image[i][j][2]);
            glVertex2i(i, j);

        }
    }
    // Ends drawing on the window
    glEnd();
    glFlush();
}


