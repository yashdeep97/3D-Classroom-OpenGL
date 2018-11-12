#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

int prevX=0, prevY=0;

void display () {

    /* clear window */
    glClear(GL_COLOR_BUFFER_BIT);

    /* future matrix manipulations should affect the modelview matrix */
    glMatrixMode(GL_MODELVIEW);

    /* draw scene */
    glutWireTeapot(.5);

    /* flush drawing routines to the window */
    glFlush();

}

void reshape ( int width, int height ) {

    /* define the viewport transformation */
    glViewport(0,0,width,height);

}

void look (int x, int y){
    cout<<x<<" "<<y<<endl;
    GLdouble deltaX, deltaY;
    deltaX = x-prevX;
    deltaY = y-prevY;
    cout<<deltaX<<endl;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluLookAt(0.0,0.0,1.0,x%10,y%10,0.0,0.0,1.0,0.0);
    display();
    prevX = x;
    prevY = y;
    glutSwapBuffers();
}

int main ( int argc, char * argv[] ) {

    /* initialize GLUT, using any commandline parameters passed to the 
       program */
    glutInit(&argc,argv);

    /* setup the size, position, and display mode for new windows */
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutInitDisplayMode(GLUT_RGB);

    /* create and set up a window */
    glutCreateWindow("hello, teapot!");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    // glutPassiveMotionFunc(look);

    /* define the projection transformation */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2.0,2.0,-2.0,2.0,-2.0,2.0);

    /* define the viewing transformation */
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,1.0,0.0,0.0,0.0,0.0,1.0,0.0);

    /* tell GLUT to wait for events */
    glutMainLoop();
}