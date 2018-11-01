#include <iostream>
#include <stdlib.h>
#include <GLFW/glfw3.h>

using namespace std;

#define SCREEN_WIDTH 1000
#define SCREEN_HEIGHT 1000

void framebuffer_size_callback(GLFWwindow* window, int width, int height); 
// void processInput(GLFWwindow *window);
void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
void drawCube( GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength );

GLfloat rotationX = 0.0f;
GLfloat rotationY = 0.0f;

int main(void)
{
    GLFWwindow* window;


    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Cube", NULL, NULL);
    if (window == NULL)
    {
		cout<<"Failed to create window"<<endl;
        glfwTerminate();
        return -1;
    }
    glfwSetKeyCallback( window, keyCallback );
    glfwSetInputMode( window, GLFW_STICKY_KEYS, 1 );

    glfwMakeContextCurrent(window);
    glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    // New coordinate system
    glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1000); //clipping planes near and far
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

	// glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    while (!glfwWindowShouldClose(window))
    {
        glClear( GL_COLOR_BUFFER_BIT );
        glPushMatrix( );
        glTranslatef( SCREEN_WIDTH/2, SCREEN_HEIGHT/2, -500 );
        glRotatef( rotationX, 1, 0, 0 );
        glRotatef( rotationY, 0, 1, 0 );
        glTranslatef( -SCREEN_WIDTH/2, -SCREEN_HEIGHT/2, 500 );
        
        drawCube(SCREEN_WIDTH/2, SCREEN_HEIGHT/2, -500, 200);

        glPopMatrix();

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}

// Re-adjust Viewport size when window is resized
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// cout<<height<<" "<<width<<endl;
    glViewport(0, 0, width, height);
} 

// void processInput(GLFWwindow *window)
// {
//     if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
    GLfloat rotationSpeed = 10;
    if(action == GLFW_PRESS || action == GLFW_REPEAT){
        switch(key){
            case GLFW_KEY_UP:
                rotationX -= rotationSpeed;
                break;
            case GLFW_KEY_DOWN:
                rotationX += rotationSpeed;
                break;
            case GLFW_KEY_LEFT:
                rotationY -= rotationSpeed;
                break;
            case GLFW_KEY_RIGHT:
                rotationY += rotationSpeed;
                break;
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, true);
                break;
        }
    }
}

void drawCube( GLfloat centerPosX, GLfloat centerPosY, GLfloat centerPosZ, GLfloat edgeLength ){
    
    GLfloat halfSideLength = edgeLength * 0.5;
    GLfloat vertices[] = {
        //front face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        //back face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,

        //left face
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        //right face
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,

        //top face
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY + halfSideLength, centerPosZ + halfSideLength,

        //bottom face
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
        centerPosX + halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ - halfSideLength,
        centerPosX - halfSideLength, centerPosY - halfSideLength, centerPosZ + halfSideLength,
    };

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //wire frame mode
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);
}
