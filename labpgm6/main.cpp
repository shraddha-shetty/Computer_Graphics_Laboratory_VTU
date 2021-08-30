#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void teapot (GLfloat x,GLfloat y,GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glutSolidTeapot(0.1);
    glPopMatrix();
}
void tabletop(GLfloat x,GLfloat y,GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(0.6,0.02,0.5);
    glutSolidCube(1.0);
    glPopMatrix();
}
void tableleg(GLfloat x,GLfloat y,GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(0.02,0.3,0.02);
    glutSolidCube(1.0);
    glPopMatrix();
}
void wall(GLfloat x,GLfloat y,GLfloat z)
{
    glPushMatrix();
    glTranslatef(x,y,z);
    glScalef(1.0,1.0,0.02);
    glutSolidCube(1.0);
    glPopMatrix();
}
void light()
{
    GLfloat mat_ambient[]={1.0,1.0,1.0,1.0};
    GLfloat mat_diffuse[]={0.5,0.5,0.5,1.0};
    GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
    GLfloat mat_shininess[]={50.0f};
    glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient);
    glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
    glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
    glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
    GLfloat light_position[]={2.0,6.0,3.0,1.0};
    GLfloat lightintensity[]={0.7,0.7,0.7,1.0};
    glLightfv(GL_LIGHT0,GL_POSITION,light_position);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,lightintensity);
}
void display()
{
    GLfloat teapotP=-0.07,tabletopP=-0.15,tablelegP=0.2,wallP=0.5;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(-2.0,2.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
    light();
    teapot(0.0,teapotP,0.0);
    tabletop(0.0,tabletopP,0.0);
    tableleg(tablelegP,-0.3,tablelegP);
    tableleg(-tablelegP,-0.3,tablelegP);
    tableleg(-tablelegP,-0.3,-tablelegP);
    tableleg(tablelegP,-0.3,-tablelegP);
    wall(0.0,0.0,-wallP);
    glRotatef(90.0,1.0,0.0,0.0);
    wall(0.0,0.0,wallP);
    glRotatef(90.0,0.0,1.0,0.0);
    wall(0.0,0.0,wallP);
    glFlush();
}
void myinit()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0,1.0,-1.0,1.0,-1.0,10.0);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("teapot on a table");
    myinit();
    glutDisplayFunc(display);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_SMOOTH);
    glEnable(GL_NORMALIZE);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
