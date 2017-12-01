//
// Created by Jack Roach on 11/30/17.
//

#include "graphics.h"

GLdouble width, height;
int wd;
int UNIT = 50;

void init() {
    width = UNIT * 11;
    height = UNIT * 14;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.5f, 0.0f, 1.0f); // Black and opaque
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    /*
     * Draw here
     */

    //shape

    //Two Lane Road
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2i(0, UNIT);
    glVertex2i(0, UNIT*3);
    glVertex2i(width, UNIT*3);
    glVertex2i(width, UNIT);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT);
    glVertex2d(width,UNIT);
    glBegin(GL_LINES);
    glVertex2d(0,UNIT*3);
    glVertex2d(width,UNIT*3);
    glEnd();

    //Three Lane Road #1
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2i(0, UNIT*4);
    glVertex2i(0, UNIT*7);
    glVertex2i(width, UNIT*7);
    glVertex2i(width, UNIT*4);
    glEnd();

    //Three Lane Road #2
    glColor3f(0.6, 0.6, 0.6);
    glBegin(GL_QUADS);
    glVertex2i(0, UNIT*8);
    glVertex2i(0, UNIT*11);
    glVertex2i(width, UNIT*11);
    glVertex2i(width, UNIT*8);
    glEnd();

    glFlush();  // Render now
}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {


    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {



    glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int graphicsPlay(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(450, 100); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Fun with Drawing!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}