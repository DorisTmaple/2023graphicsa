#include <GL/glut.h>

float X=0,Y=0; //
float angle = 0; ///
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///�M�I��
    glColor3f(0,1,0); /// green
    glPushMatrix();  /// �ƥ��x�}
        glTranslatef( 0.8,0, 0); ///  ����󥿤��ߪ��������k�貾��
        glRotatef(angle,0,0,1); ///���઺����angle ==> ��ʯ���
        glutSolidTeapot(0.3); ///���X��߯����F�j�p0.3
    glPopMatrix();  ///�٭�x�}

    glColor3f(1,0,0); ///red
    glPushMatrix();
        glRotatef(angle,0,0,1); /// ��ʯ���
        glTranslatef( 0.8, 0, 0);///  �N�H���P���׶i�沾�ʨñ���
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers(); ///��GLUT�e��swap�e����ܪ��a��

    angle++; ///  �⨤��++

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
