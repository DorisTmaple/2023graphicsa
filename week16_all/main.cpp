#include <GL/glut.h>

void display()

{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glColor3f(0,1,0);   ///加顏色

    glBegin(GL_POLYGON); ///畫圖型

        glVertex2f(0.5, 0.5);   ///四個頂點－－此為四方形

        glVertex2f(-0.5, 0.5);

        glVertex2f(-0.5, -0.5);

        glVertex2f(0.5, -0.5);

    glEnd();

    glColor3f(1,1,0);

    glutSolidTeapot( 0.3 );     ///畫茶壺

    glutSwapBuffers();

}

int main(int argc, char** argv)

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);

    glutCreateWindow("week16");

    glutDisplayFunc(display);

    glutMainLoop();

}
