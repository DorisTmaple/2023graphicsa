#include <GL/glut.h>

float X=0,Y=0; //
float angle = 0; ///step02-1

void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///�M�I��

    glPushMatrix();  ///�ƥ��x�}
        glColor3f(1,1,0);
        glTranslatef( 0.6, 0, 0); ///step03-2 �����ʦb����
        glRotatef(angle,0,1,0); /// step02-1 ���઺����angle
        glutSolidTeapot(0.3);
    glPopMatrix();  ///�٭�x�}

    glPushMatrix();  ///�ƥ��x�}
        glColor3f(1,0,0); /// ��
        glRotatef(angle,0,1,0); /// step02-1 ���઺����angle
        glTranslatef( 0.6, 0, 0); ///step03-2 ������b����
        glutSolidTeapot(0.3);
    glPopMatrix();  ///�٭�x�}

    glutSwapBuffers(); ///��GLUT�e��swap�e����ܪ��a��

    angle++; /// step02-1 �⨤��++

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///�}��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///�]�w��ܼҦ�
    glutCreateWindow("week04");///�}����
    glutDisplayFunc(display);///�n��ܪ��������"display()"
    glutIdleFunc(display);
    //glutMouseFunc(mouse);  /// step 02-1  ��mouse�禡����
   glutMainLoop();/// ���̫�
}
