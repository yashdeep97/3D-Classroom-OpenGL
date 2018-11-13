#ifndef FAN_H
#define FAN_H

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

class fan {

public:
	
	void drawFan()
	{
		glTranslatef(0, 5, -5.0);
		glScalef(5, 5, 5);
		//glRotatef(90, 1, 0, 0);

		glPushMatrix();
		glColor3f(1, 1, 1);
		glScalef(1, 1.2, 1);
		glScalef(.5, .4, .5);
		glTranslatef(0, -.5, 0);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -1.05, 0);
		glScalef(0.15, .555, .15);
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= 360; j += DEF_D) {
			glColor3f(1.0, 1.0, 0.0);
			glVertex3f(cos(j), +1, sin(j));
			glColor3f(0.0, 1.0, 0.0);
			glVertex3f(cos(j), -1, sin(j));
		}
		glEnd();
		glPopMatrix();

		glPushMatrix();
		glColor3f(1, 1, 1);
		glRotatef(90, 1, 0, 0);
		glTranslatef(0, 0, 1.55);
		glScalef(.25, .25, .25);
		glutSolidTorus(.1, .72, 25, 25);
		glPopMatrix();

		glPushMatrix();

		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(-1, -1.55, 0);
		glScalef(2.5, .2, .75);
		glutWireCube(.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -1.55, 0);
		glScalef(0.05, .11, .05);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, -5);
		glScalef(1, 1, 2.4);
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= 360; j += DEF_D) {
			glColor3f(1.0, 0, 0);
			glVertex3f(cos(j), +1, sin(j));
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cos(j), -1, sin(j));
		}
		glEnd();
		glPopMatrix();

		glPopMatrix();

		glPushMatrix();
		glRotatef(90, 0, 1, 0);
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(-1, -1.55, 0);
		glScalef(2.5, .2, .75);
		glutWireCube(.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -1.55, 0);
		glScalef(0.05, .11, .05);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, -5);
		glScalef(1, 1, 2.4);
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= 360; j += DEF_D) {
			glColor3f(1.0, 0, 0);
			glVertex3f(cos(j), +1, sin(j));
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cos(j), -1, sin(j));
		}
		glEnd();
		glPopMatrix();

		glPopMatrix();

		glPushMatrix();
		glRotatef(180, 0, 1, 0);

		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(-1, -1.55, 0);
		glScalef(2.5, .2, .75);
		glutWireCube(.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -1.55, 0);
		glScalef(0.05, .11, .05);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, -5);
		glScalef(1, 1, 2.4);
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= 360; j += DEF_D) {
			glColor3f(1.0, 0, 0);
			glVertex3f(cos(j), +1, sin(j));
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cos(j), -1, sin(j));
		}
		glEnd();
		glPopMatrix();

		glPopMatrix();

		glPushMatrix();
		glRotatef(270, 0, 1, 0);
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(-1, -1.55, 0);
		glScalef(2.5, .2, .75);
		glutWireCube(.5);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(0, -1.55, 0);
		glScalef(0.05, .11, .05);
		glRotatef(90, 1, 0, 0);
		glRotatef(90, 0, 1, 0);
		glTranslatef(0, 0, -5);
		glScalef(1, 1, 2.4);
		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= 360; j += DEF_D) {
			glColor3f(1.0, 0, 0);
			glVertex3f(cos(j), +1, sin(j));
			glColor3f(0.0, 0.0, 1.0);
			glVertex3f(cos(j), -1, sin(j));
		}
		glEnd();
		glPopMatrix();

		glPopMatrix();
	}

};

#endif
