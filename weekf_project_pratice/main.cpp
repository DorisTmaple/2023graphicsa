#include <GL/glut.h>
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include "glm.h"
GLMmodel * Meowth = NULL;
GLMmodel * Keroro = NULL;
GLMmodel * head = NULL;
GLMmodel * body = NULL;

GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
GLMmodel * handR = NULL; ///0603新增

GLMmodel * uplagR = NULL; ///0603新增
GLMmodel * lowlagR = NULL; ///0603新增
GLMmodel * footR = NULL; ///0603新增

GLMmodel * uparmL = NULL; ///0604新增，左半邊
GLMmodel * lowarmL = NULL; ///0604新增，左半邊
GLMmodel * handL = NULL; ///0604新增，左半邊

GLMmodel * uplagL = NULL; ///0604新增，左半邊
GLMmodel * lowlagL = NULL; ///0604新增，左半邊
GLMmodel * footL = NULL; ///0604新增，左半邊

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
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
    teapotX += (x - oldX)/10.0; ///有不同
    teapotY += (oldY - y)/10.0; ///有不同
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

//    Keroro = glmReadOBJ("model/whole.obj");///完整體
//    Meowth = glmReadOBJ("model/meowth_2.obj");///完整體
    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj");
    //myTexture("model/KERORO_FACE.png");
    //glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
