#include <iostream>
#include <math.h>

#include <GL/glut.h>
#include <GL/freeglut_ext.h>
#include "chair.h"

#define WINDOW_WIDTH 1000
#define WINDOW_HEIGHT 1000

using namespace std;

// angle of rotation for the camera direction
float angle = 0.0, yAngle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, ly = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 5.0f;

//for mouse movements
float halfWidth = (float)(WINDOW_WIDTH/2.0);
float halfHeight = (float)(WINDOW_HEIGHT/2.0);
float mouseX = 0.0f, mouseY = 0.0f;

void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw Body
	glTranslatef(0.0f, 0.75f, 0.0f);
	glutSolidSphere(0.75f, 20, 20);

	// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f, 20, 20);

	// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f, 0.0f, 0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f, 10, 10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f, 10, 10);
	glPopMatrix();

	// Draw Nose
	glColor3f(1.0f, 0.5f, 0.5f);
	glutSolidCone(0.08f, 0.5f, 10, 2);
}


void renderScene(void) {

	// Clear Color and Depth Buffers

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f + ly, z + lz,
		0.0f, 1.0f, 0.0f);

	// Draw floor
	glColor3f(0.7f, 0.7f, 0.7f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

    //wall
    glColor3f(0.7f, 0.7f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glEnd();

	//wall
    glColor3f(0.7f, 0.7f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glEnd();

	//wall with door
    glColor3f(0.7f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 0.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glVertex3f(-7.0f, 7.0f, 10.0f);
	glVertex3f(-7.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.7f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-4.0f, 0.0f, 10.0f);
	glVertex3f(-4.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	glColor3f(0.7f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-7.0f, 7.0f, 10.0f);
	glVertex3f(-7.0f, 5.0f, 10.0f);
	glVertex3f(-4.0f, 5.0f, 10.0f);
	glVertex3f(-4.0f, 7.0f, 10.0f);
	glEnd();

	//wall
    glColor3f(0.7f, 0.7f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(10.0f, 0.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(10.0f, 0.0f, 10.0f);
	glEnd();

	//ceiling
	glColor3f(0.0f, 0.7f, 0.0f);
	glBegin(GL_QUADS);
	glVertex3f(-10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, -10.0f);
	glVertex3f(10.0f, 7.0f, 10.0f);
	glVertex3f(-10.0f, 7.0f, 10.0f);
	glEnd();

	// // Draw 36 SnowMen
	// for (int i = -3; i < 3; i++)
	// 	for (int j = -3; j < 3; j++) {
	// 		glPushMatrix();
	// 		glTranslatef(i*10.0, 0, j * 10.0);
	// 		drawSnowMan();
	// 		glPopMatrix();
	// 	}

	// Draw prof's chair
	Chair profChair;
	glPushMatrix();
	glTranslatef( 0.0f, 0.8f, -8.0f);
	glScalef(0.25f, 0.25f, 0.25f);
	profChair.drawChair();
	glPopMatrix();

	// Draw student chairs
	Chair studentChair[4][4];
	for (int i = -2; i < 3; i++){
		for (int j = 0; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0, 0, j * 10.0);
			glScalef(0.25f, 0.25f, 0.25f);
			studentChair[i][j].drawChair();
			glPopMatrix();
		}
	}

	if(abs(mouseX) > 0.3){
		angle -= (0.004f * mouseX);
		lx = sin(angle);
		lz = -cos(angle);
	}
	if(abs(mouseY) > 0.3){
		yAngle += (0.002f * mouseY);
		ly = sin(yAngle);
	}

	glutSwapBuffers();
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
	case GLUT_KEY_LEFT:
		x += sin(angle - M_PI/2.0) * fraction;
		z += -cos(angle - M_PI/2.0) * fraction;
		break;
	case GLUT_KEY_RIGHT:
		x += sin(M_PI/2.0 + angle) * fraction;
		z += -cos(M_PI/2.0 + angle) * fraction;
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

void processNormalKeys(unsigned char key, int xx, int yy) {
    float fraction = 0.1f;
    if(key == 'w'){
        x += lx * fraction;
		z += lz * fraction;
    } else if(key == 'a'){
        x += sin(angle - M_PI/2.0) * fraction;
		z += -cos(angle - M_PI/2.0) * fraction;
    } else if(key == 's'){
        x -= lx * fraction;
		z -= lz * fraction;
    } else if(key == 'd'){
        x += sin(M_PI/2.0 + angle) * fraction;
		z += -cos(M_PI/2.0 + angle) * fraction;
    }
	if (key == 27)
		exit(0);
}

void processMouseMovement(int xx, int yy){

	mouseX = (float)(halfWidth - xx)/halfWidth;
	mouseY = (float)(halfHeight - yy)/halfHeight;
	angle -= (0.005f * mouseX);
	lx = sin(angle);
	lz = -cos(angle);

	if(abs(yAngle) < (M_PI/2)){
		yAngle += (0.005f * mouseY);
	}
	ly = sin(yAngle);

}

void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Classroom");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);
    glutPassiveMotionFunc(processMouseMovement);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}