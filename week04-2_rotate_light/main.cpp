#include <GL/glut.h>

float X=0,Y=0; //
float angle = 0; ///step02-1

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };


void display()
{

    glClearColor(1,1,1,1); /// step02-3 �ΨӲM�I�����C��R,G,B,A ((A�bGLUT_RGB�̥Τ���
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///�M�I��
    glPushMatrix();  ///�ƥ��x�}
        glColor3f(1,1,0); /// step02-3 �[�J��m
        glRotatef(angle,0,1,0); /// step02-1 ���઺����angle
        glutSolidTeapot(0.3); ///���X��߯����F�j�p0.3
    glPopMatrix();  ///�٭�x�}

    glutSwapBuffers(); ///��GLUT�e��swap�e����ܪ��a��

    angle++; /// step02-1 �⨤��++

}

void mylight(){

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///�}��GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);  ///�]�w��ܼҦ�

    glutCreateWindow("week04");///�}����
    glutDisplayFunc(display);///�n��ܪ��������"display()"
    glutIdleFunc(display);

    mylight();

    //glutMouseFunc(mouse);  /// step 02-1  ��mouse�禡����
   glutMainLoop();/// ���̫�
}
