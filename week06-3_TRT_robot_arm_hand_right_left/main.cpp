#include <GL/glut.h>
/// week06-2 ���06-1
///���X�j�����j���u

float X=0,Y=0; //
float angle = 0; ///
void drawHand()
{
    glPushMatrix();
    glScaled(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///�M�I��
    //glColor3f(0,1,0); /// green body
    glPushMatrix(); ///�k�W���u
        glTranslatef(0.25,0,0);
        glRotatef(angle,0,0,1);  ///
        glTranslatef(0.25,0,0); ///
        ///step 03-1
        drawHand(); ///�k�W���u

            glPushMatrix(); ///�k�W��y
                glTranslatef(0.25,0,0);
                glRotatef(angle,0,0,1);  ///
                glTranslatef(0.25,0,0);
                drawHand();
            glPopMatrix(); ///�k�W��y

    glPopMatrix();


    glPushMatrix(); ///���W���u
        glTranslatef(-0.25,0,0);
        glRotatef(angle,0,0,1);  ///
        glTranslatef(-0.25,0,0); ///
        ///step 03-1
        drawHand(); ///���W���u

            glPushMatrix(); ///���W��y
                glTranslatef(-0.25,0,0);
                glRotatef(angle,0,0,1);  ///
                glTranslatef(-0.25,0,0);
                drawHand();
            glPopMatrix(); ///���W��y

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
