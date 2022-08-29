#include <GL/freeglut.h>
#include "WindowBuilder.h"

int main(int argc, char** argv)
{

    //Initialise GLUT with command-line parameters.
    glutInit(&argc, argv);

    //Set Display Mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    //Set the window size
    glutInitWindowSize(300,300);

    //Set the window position
    glutInitWindowPosition(100,100);

    //Create the window
    glutCreateWindow("Random Noise");

    // Creating image to display and saving file
    imageBuilder();
    saveToPPM(300,300);

    //Call init (initialise GLUT
    init();

    //Call "display" function
    glutDisplayFunc(display);

    //Enter the GLUT event loop
    glutMainLoop();

    return 0;
}
