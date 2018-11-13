#ifndef SHELF_H
#define SHELF_H

#include <GL/glut.h>
#include <GL/freeglut_ext.h>

class Shelf{

    public:
		void drawSnowMan() {

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

		void drawHouse() {

			// house
			glPushMatrix();
			glutSolidCube(2);                 // building

			glTranslatef(0, 1, 0);
			glPushMatrix();                   // roof
			glRotatef(-90, 1, 0, 0);
			glutSolidCone(1.5, 1, 16, 8);
			glPopMatrix();

			glTranslatef(.75, .5, -.75);
			glPushMatrix();                   // chimney
			glScalef(1, 3, 1);
			glutSolidCube(.25);
			glPopMatrix();
			glPopMatrix();

			glTranslatef(0, -.65, 2);

			// car
			glColor3f(1.0f, 0.0f, 00.0f);
			glPushMatrix();
			glPushMatrix();                   // body
			glScalef(2, .5, 1);
			glutSolidCube(.5);
			glPopMatrix();
			glTranslatef(0, 0, .25);
			glPushMatrix();
			glTranslatef(-.4, -.2, 0);
			glutSolidTorus(.05, .1, 8, 8);       // wheel
			glTranslatef(.8, 0, 0);
			glutSolidTorus(.05, .1, 8, 8);       // wheel
			glPopMatrix();
			glTranslatef(0, 0, -.5);
			glPushMatrix();
			glTranslatef(-.4, -.2, 0);
			glutSolidTorus(.05, .1, 8, 8);       // wheel
			glTranslatef(.8, 0, 0);
			glutSolidTorus(.05, .1, 8, 8);       // wheel
			glPopMatrix();
			glPopMatrix();

			glPopMatrix();
		}

		void drawCubBoard()
		{
			//glTranslatef(0, 0, -14);
			glPushMatrix();

			glBegin(GL_QUADS);


			glColor3f(0, 0, 1);
			glVertex3f(-4.0f, 0.0f, -4.0f);
			glVertex3f(0.0f, 0.0f, -4.0f);

			glVertex3f(0.0f, 4.0f, -4.0f);
			glVertex3f(-4.0f, 4.0f, -4.0f);

			//glVertex3f(-1.8f, 1.2f, -0.6f);
			//glVertex3f(1.8f, 1.2f, -0.6f);
			//glVertex3f(1.8f, 3.5f, -0.6f);
			//glVertex3f(-1.8f, 3.5f, -0.6f);

			//chair upper side
			glColor3f(0, 1, 0);
			glVertex3f(-4.0f, 0.0f, -4.0f);
			glVertex3f(-4.0f, 0.0f, -0.0f);
			glVertex3f(-4.0f, 4.0f, -0.0f);
			glVertex3f(-4.0f, 4.0f, -4.0f);

			glVertex3f(0.0f, 0.0f, -4.00f);
			glVertex3f(0.0f, 0.0f, -0.0f);
			glVertex3f(0.0f, 4.0f, -0.0f);
			glVertex3f(0.0f, 4.0f, -4.0f);

			//chiar upper top 
			glColor3f(0, 1, 0);
			glVertex3f(-4.0f, 4.0f, -4.00f);
			glVertex3f(-4.0f, 4.0f, -0.0f);
			glVertex3f(0.0f, 4.0f, -0.0f);
			glVertex3f(0.0f, 4.0f, -4.0f);

			glVertex3f(-4.0f, 0.0f, -4.00f);
			glVertex3f(-4.0f, 0.0f, -0.0f);
			glVertex3f(0.0f, 0.0f, -0.0f);
			glVertex3f(0.0f, 0.0f, -4.0f);

			glEnd();

			glPopMatrix();
		}

		void drawShelf() {
			drawCubBoard();

			glPushMatrix();

			glTranslatef(4, -4, 0);
			drawCubBoard();
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0f, 1.0f, 1.0f);
			glTranslatef(-2, 0, -0.5);
			drawSnowMan();
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0f, 0.0f, 0.0f);
			glTranslatef(-3, 0, -3);
			drawSnowMan();
			glPopMatrix();

			glPushMatrix();
			glColor3f(1.0f, 1.0f, 0.0f);
			glTranslatef(-1, 0, -3);
			drawSnowMan();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(2.5, -3, -1.2);
			glRotatef(-90, 0, 1, 0);
			drawHouse();
			glPopMatrix();
		}


};

#endif
