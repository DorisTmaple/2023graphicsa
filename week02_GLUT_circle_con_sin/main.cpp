#include <GL/glut.h>
#include <math.h>
///week02-3
//void myCricle(float r){
//    glBegin(GL_POLYGON);
//    for(float a=0; a<2*3.1415926; a+=0.01){
 //       glVertex2f( r*cos(a),r*sin(a) );
//    }
//    glEnd();

//}

void myCricle(float r, float x, float y){
glBegin(GL_POLYGON);
        for(float a=0; a< 2 *3.1415962; a+=0.01){
            glVertex2f( r*cos(a)+x ,r*sin(a)+y );
        }
   glEnd();
}

void display()
{
    glColor3f(1,0,1);       myCricle(0.6,0,0); ///������
    ///glColor3f(244/255.0,209/255.0,33/255.0);
    glColor3f(1,0,0);       myCricle(0.3,0.5,0.5); ///�k�W
    glColor3f(0,1,0);       myCricle(0.3,-0.5,0.5); ///���W
    glColor3f(1,1,0);       myCricle(0.3,-0.5,-0.5); ///���U
    glColor3f(0,0,1);       myCricle(0.3,0.5,-0.5); ///�k�U

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
