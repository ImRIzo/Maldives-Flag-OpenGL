#include<windows.h>
#include <GL/glut.h>
#include<math.h>
void init(){
    glClearColor(0,0,0,0);
    glOrtho(-30, 30, -25, 25, -10, 10);
}

void drawCircle(float x, float y, float radius){
    glPointSize(3);
    glBegin(GL_POLYGON);

    for(float i=0;i<=7;i+=.01)
        glVertex2f(x+radius*cos(i),y+radius*sin(i));
    glEnd();
    glFlush();
}

void draw(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.824, 0.063, 0.204);
    glBegin(GL_QUADS);
        glVertex2f(-25, 15);
        glVertex2f(25, 15);
        glVertex2f(25, -15);
        glVertex2f(-25, -15);
    glEnd();
    glFlush();

    glColor3f(0, 0.494, 0.227);
    glBegin(GL_QUADS);
        glVertex2f(-15, 8);
        glVertex2f(15, 8);
        glVertex2f(15, -8);
        glVertex2f(-15, -8);
    glEnd();
    glFlush();

    glColor3f(1, 1, 1);
    drawCircle(2,0,6);

    glColor3f(0, 0.494, 0.227);
    drawCircle(4,0,6);


    glutSwapBuffers();
}
int main(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Maldives");
    init();
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
