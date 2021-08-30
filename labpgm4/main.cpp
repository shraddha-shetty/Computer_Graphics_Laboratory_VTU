/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/gl.h>
#include <GL/glut.h>
//#endif
#include<GL/glu.h>
#include<windows.h>
#include<stdio.h>
#include <stdlib.h>
#endif
GLfloat vertices[]={-1.0,-1.0,-1.0,
                    1.0,-1.0,-1.0,
                    1.0,1.0,-1.0,
                    -1.0,1.0,-1.0,
                    -1.0,-1.0,1.0,
                    1.0,-1.0,1.0,
                    1.0,1.0,1.0,
                    -1.0,1.0,1.0
};
GLfloat normals[]={-1.0,-1.0,-1.0,
                    1.0,-1.0,-1.0,
                    1.0,1.0,-1.0,
                    -1.0,1.0,-1.0,
                    -1.0,-1.0,1.0,
                    1.0,-1.0,1.0,
                    1.0,1.0,1.0,
                    -1.0,1.0,1.0
};
GLfloat colors[]={0.0,0.0,0.0,
                  1.0,0.0,0.0,
                  1.0,1.0,0.0,
                  0.0,1.0,0.0,
                  0.0,0.0,1.0,
                  1.0,0.0,1.0,
                  1.0,1.0,1.0,
                  0.0,1.0,1.0
                  };
GLbyte cubeindices[]={0,3,2,1,2,3,7,6,0,4,7,3,1,2,6,5,4,5,6,7,0,1,5,4};
static GLint axix=2;
static GLfloat theta[]={0.0,0.0,0.0};
static double viever[]={0.0,0.0,5.0};
void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(viever[0],viever[1],viever[2],0.0,0.0,0.0,0.0,1.0,0.0);
    glRotatef(theta[0],1.0,0.0,0.0);
    glRotatef(theta[1],0.0,1.0,0.0);
    glRotatef(theta[2],0.0,0.0,1.0);
    glDrawElements(GL_QUADS,24,GL_UNSIGNED_BYTE,cubeindices);
    glFlush();
    glutSwapBuffers();
}
void mouse(int btn,int state,int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
        axix=0;
    if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
        axix=1;
    if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
        axix=2;
        theta[axix]+=2.0;
        if(theta[axix]<360.0)
            theta[axix]-=360;
        glutPostRedisplay();
}
void keys(unsigned char key,int x,int y)
{
    if (key=='x') viever[0]-=1.0;
    if (key=='X') viever[0]+=1.0;
    if (key=='y') viever[1]-=1.0;
    if (key=='Y') viever[1]+=1.0;
    if (key=='z') viever[2]-=1.0;
    if (key=='Z') viever[2]+=1.0;
    glutPostRedisplay();
}
void myReshape(int w,int h)
{
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(w<=h)
        glFrustum(-2.0,2.0,-2.0*(GLfloat)h/(GLfloat)w,2.0*(GLfloat)h/(GLfloat)w,2.0,20.0);
    else
        glFrustum(-2.0,2.0,-2.0*(GLfloat)w/(GLfloat)h,2.0*(GLfloat)w/(GLfloat)h,2.0,20.0);
      glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char**argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("color cube");
    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutKeyboardFunc(keys);
    glutMouseFunc(mouse);
    glEnable(GL_DEPTH_TEST);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,vertices);
    glColorPointer(3,GL_FLOAT,0,colors);
    glNormalPointer(GL_FLOAT,0,normals);
    glColor3f(1.0,1.0,1.0);
    glutMainLoop();
}
