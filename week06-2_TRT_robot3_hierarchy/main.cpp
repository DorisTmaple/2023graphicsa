#include <GL/glut.h>
/// week06-2 ���06-1
///�ܦh���P���s�����p�A���u�|�۱a��b����

float X=0,Y=0; //
float angle = 0; ///
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///�M�I��
    //glColor3f(0,1,0); /// green body
    //glutSolidSphere(0.02,30,30); ///�Q�ζ�y��X������

    glutSolidTeapot(0.3); /// step 02-1 ��@����

    glPushMatrix();  /// stpe02-1 as right arm
        //glTranslatef(0.25,0.25,0);  ///(3)�N������m��n�񪺦�m
        glTranslatef(0.49,0.13,0);   /// step02-1 new move
        glRotatef(angle,0,0,1);  /// (2)��ʬݦ��G�O�_�ŦX�w�Q
        glTranslatef(0.46,-0.05,0); ///(1)�N�������ߩ�m������
        glutSolidTeapot(0.3);

        glPushMatrix(); /// step02-2 as right elbow(��y)
            glTranslatef(0.49,0.13,0);   /// step02-1 new move
            glRotatef(angle,0,0,1);  /// (2)��ʬݦ��G�O�_�ŦX�w�Q
            glTranslatef(0.46,-0.05,0); ///(1)�N�������ߩ�m������
            glutSolidTeapot(0.3);
        glPopMatrix();

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
