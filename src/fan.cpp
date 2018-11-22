
#include "fan.h"

void Fan::drawFan()
{
    glTranslatef(0, 5, -5.0);
    glScalef(5, 5, 5);
    //glRotatef(90, 1, 0, 0);
    //Cube
    glPushMatrix();
    glColor3f(1, 1, 1);
    glScalef(1, 1.2, 1);
    glScalef(.5, .4, .5);
    glTranslatef(0, -2.0, 0);
    glScalef(1.0f, 0.7f, 1.0f);
    glTranslatef(0, -0.5, 0);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(rotationAngle, 0.0f, 1.0f, 0.0f);

    glPushMatrix();
    glTranslatef(0, -1.05, 0);
    glScalef(0.15, .15, .15);
    glTranslatef(0.0f, -2.2f, 0.0f);
    glBegin(GL_QUAD_STRIP);
    for (int j = 0; j <= 360; j += DEF_D) {
        glColor3f(0.302, 0.149, 0.0);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(0.6, 0.302, 0.0);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glColor3f(.3, .3, .3);
    glRotatef(90, 1, 0, 0);
    glTranslatef(0, 0, 1.55);
    glScalef(.25, .25, .25);
    glutSolidTorus(.1, .72, 25, 25);
    glPopMatrix();

    glPushMatrix();

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
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
        glColor3f(.3, .3, .3);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(.7, .7, .7);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
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
        glColor3f(.3, .3, .3);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(.7, .7, .7);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(180, 0, 1, 0);

    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
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
        glColor3f(.3, .3, .3);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(.7, .7, .7);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPushMatrix();
    glRotatef(270, 0, 1, 0);
    glPushMatrix();
    glColor3f(0.0, 0.0, 0.4);
    glTranslatef(-1, -1.55, 0);
    glScalef(2.5, .1, .75);
    glutSolidCube(.5);
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
        glColor3f(.3, .3, .3);
        glVertex3f(cos(j), +1, sin(j));
        glColor3f(.7, .7, .7);
        glVertex3f(cos(j), -1, sin(j));
    }
    glEnd();
    glPopMatrix();

    glPopMatrix();

    glPopMatrix();
}

void Fan::rotateFan()
{
    rotationAngle += 1.5f;
}