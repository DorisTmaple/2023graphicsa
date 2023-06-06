#include <GL/glut.h>
#include <stdio.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * Meowth = NULL;
GLMmodel * Keroro = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;

GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
GLMmodel * handR = NULL; ///0603�s�W

GLMmodel * uplagR = NULL; ///0603�s�W
GLMmodel * lowlagR = NULL; ///0603�s�W
GLMmodel * footR = NULL; ///0603�s�W

GLMmodel * uparmL = NULL; ///0604�s�W�A���b��
GLMmodel * lowarmL = NULL; ///0604�s�W�A���b��
GLMmodel * handL = NULL; ///0604�s�W�A���b��

GLMmodel * uplagL = NULL; ///0604�s�W�A���b��
GLMmodel * lowlagL = NULL; ///0604�s�W�A���b��
GLMmodel * footL = NULL; ///0604�s�W�A���b��

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

float teapotX=0, teapotY=0, angle=0, angle2=0, oldX=0, oldY=0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}

void motion(int x, int y) {
    ///teapotX = (x-150) / 150.0;
    ///teapotY = (150-y) / 150.0;
    teapotX += (x - oldX)/10.0; ///�����P
    teapotY += (oldY - y)/10.0; ///�����P
    angle += x - oldX;
    oldX = x;
    angle2 += y - oldY;
    oldY = y;
    printf("glTranslatef(%.3f , %.3f , 0 );\n", teapotX, teapotY);
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glColor3f(1,1,1);
        ///glRotatef(angle, 0, 1, 0);
        glScalef(0.08,0.08,0.08);
        glmDraw(body, GLM_MATERIAL | GLM_TEXTURE);

        glPushMatrix();
            glTranslatef(0.000 , +2.200 , 0 );
            glRotatef(angle, 0, 1, 0);
            glRotatef(angle2, 1, 0, 0);
            glTranslatef(0.000 , -2.200 , 0 );
//            glTranslatef(teapotX, teapotY, 0);
            glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
        glPopMatrix();





     glColor3f(0,0,1);
    glutSolidTeapot( 0.01 );

    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("final practice");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);

//    Keroro = glmReadOBJ("model/whole.obj");///������
//    Meowth = glmReadOBJ("model/meowth_2.obj");///������
    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj");
    //myTexture("model/KERORO_FACE.png");
    //glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
