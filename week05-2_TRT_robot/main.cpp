#include <GL/glut.h>
/// week05-2
///�e�X�j������B���u

float X=0,Y=0; //
float angle = 0; ///
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///�M�I��
    glColor3f(0,1,0); /// green body
    glPushMatrix();  /// �ƥ��x�}
        //glTranslatef( 0.8,0, 0); ///  ����󥿤��ߪ��������k�貾��
        //glRotatef(angle,0,0,1); ///���઺����angle ==> ��ʯ���
        glutSolidCube(0.5);
    ///-----------------------------------------------------

        glPushMatrix();
            glTranslatef(0.25,0.25,0);  ///(3)�N�������m��n�񪺦�m
            glRotatef(angle,0,0,1);  /// (2)��ʬݦ��G�O�_�ŦX�w�Q
            glTranslatef(0.25,0.25,0); ///(1)�N��������ߩ�m������
           /// glTranslatef( 0.5,0.5, 0);   ///  step03-3������
            glColor3f(1,0,0); ///red arms
            glutSolidCube(0.5);
        glPopMatrix();
    glPopMatrix();  ///�٭�x�}

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
