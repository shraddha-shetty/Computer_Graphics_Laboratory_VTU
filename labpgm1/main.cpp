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


#include<windows.h>
#include<GL/glu.h>
#include <GL/glut.h>
#include<stdio.h>
#include <stdlib.h>
int x,y;
int rFlag=0;

void draw_pixel(float x1,float y1)
{
    glColor3f(0.0,0.0,1.0);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2f(x1,y1);
    glEnd();
}
void triangle()
{
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(100,100);
    glVertex2f(250,400);
    glVertex2f(400,100);
    glEnd();
}
float th=0.0;
float trX=0.0,trY=0.0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    if(rFlag==1)
    {
        trX=0.0;
        trY=0.0;
        th+=0.1;
        draw_pixel(0.0,0.0);
    }
    if(rFlag==2)
    {
        trX=x;
        trY=y;
        th+=0.1;
        draw_pixel(x,y);
    }
    if(rFlag==3)
    {
        trX=0.0;
        trY=0.0;
        th+=0.0;
        draw_pixel(0.0,0.0);
    }
    glPushMatrix();
    glTranslatef(trX,trY,0.0);
    glRotatef(th,0.0,0.0,1.0);
    glTranslatef(-trX,-trY,0.0);
    triangle();
    glPopMatrix();
    glutPostRedisplay();
    glutSwapBuffers();
}
void myInit()
{

    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500.0,500.0,-500.0,500.0);
    glMatrixMode(GL_MODELVIEW);
}
void rotateMenu(int option)
{
    if(option==1)
        rFlag=1;
    if(option==2)
        rFlag=2;
    if(option==3)
        rFlag=3;
}
int main(int argc,char ** argv)
{
    printf("enter fixed points(x,y) for rotation:\n");
    scanf("%d%d",&x,&y);
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("create and rotate triangle");
    myInit();
    glutDisplayFunc(display);
    glutCreateMenu(rotateMenu);
    glutAddMenuEntry("enter around origin",1);
    glutAddMenuEntry("rotate around fixed",2);
    glutAddMenuEntry("stop rotation",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutMainLoop();
}
