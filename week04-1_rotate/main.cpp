#include <GL/glut.h>

float X=0,Y=0; //
float angle = 0; ///step02-1

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///�M�I��
    glPushMatrix();  ///step01-2 �ƥ��x�}
        //glTranslatef( X, Y, 0); ///  ����󥿤��ߪ��������k�貾��
        glRotatef(angle,0,1,0); /// step02-1 ���઺����angle
        glutSolidTeapot(0.3); ///���X��߯����F�j�p0.3
    glPopMatrix();  ///�٭�x�}

    glutSwapBuffers(); ///��GLUT�e��swap�e����ܪ��a��

    angle++; /// step02-1 �⨤��++

}
//#include<stdio.h>/// step 02-1
//void mouse(int button, int state, int x, int y)
//{/// step 02-1  ��mouse�禡����
  //  ///printf("%d,%d,%d,%d\n", button,state,x,y);
   // X = (x-150)/150.0;
    //Y = -(y-150)/150.0;
//}


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
