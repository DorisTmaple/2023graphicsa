#include <GL/glut.h>
///week02-1
void display()
{
    ///glColor3f(0.4,0.2,0.2);/// step 01-2�W�[��m���Ŧ�(0.1,0.4,0.6)�B�H����(0.4,0.2,0.2)
    ///glutSolidTeapot(0.6); ///���X��߯����F�j�p0.6
    glBegin(GL_POLYGON); /// step 02-1  glBegin()�}�l�e�FGL_POLYGON���h��Ϊ����
        glColor3f(1,0,0);     glVertex2f(0,1);  ///���⪺���IVertex
        glColor3f(0,1,0);     glVertex2f(-1,-1);  ///��⪺���IVertex
        glColor3f(0,0,1);     glVertex2f(1,-1);  ///�Ŧ⪺���IVertex
    glEnd();/// step 02-1

    glColor3f(1,1,0);/// step 01-2 �W�[��m�ж���
    glutSolidTeapot(0.3); ///step 01-1���X��߯����F�j�p0.3
    glutSwapBuffers(); ///step 01-1��GLUT�e��swap�e����ܪ��a��

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///�}��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///�]�w��ܼҦ�
    glutCreateWindow("GLUT Shapes");///�}����
    glutDisplayFunc(display);///�n��ܪ��������"display()"
   glutMainLoop();/// ���̫�
}
