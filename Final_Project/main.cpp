#include <GL/glut.h>
#include <stdio.h>
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include "glm.h"
#include "CMP3_MCI.h"

CMP3_MCI myMP3;

GLMmodel * head = NULL;
GLMmodel * body = NULL;

GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
GLMmodel * handR = NULL; ///0603新增

GLMmodel * uplegR = NULL; ///0603新增
GLMmodel * lowlegR = NULL; ///0603新增
GLMmodel * footR = NULL; ///0603新增

GLMmodel * uparmL = NULL; ///0604新增，左半邊
GLMmodel * lowarmL = NULL; ///0604新增，左半邊
GLMmodel * handL = NULL; ///0604新增，左半邊

GLMmodel * uplegL = NULL; ///0604新增，左半邊
GLMmodel * lowlegL = NULL; ///0604新增，左半邊
GLMmodel * footL = NULL; ///0604新增，左半邊

int show[14] = {1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1,}; ///0603新增至7個欄位，0604新增至14個欄位
int ID = 0; /// 0->頭、1->身、2->上手臂、3->下手臂

FILE * fout = NULL;///week15-2 儲存關節位置
FILE * fin = NULL;///week15-2 讀取關節位置
float teapotx = 0, teapoty = 0;
float angle[20] = {}; /// week15 修改為只旋轉特定關節/部位
float angle2[20] = {};
float OldAngle[20]={}, NewAngle[20]={};
float OldAngle2[20]={}, NewAngle2[20]={};

void timer(int t){
    glutTimerFunc(5, timer, t+1 );
    if(t%50==0){///新的凱使，要讀動作
        if(fin == NULL) fin = fopen("motion.txt", "r");
        for(int i=0; i<20; i++){
            OldAngle[i] = NewAngle[i];
            OldAngle2[i] = NewAngle2[i];
            fscanf(fin, "%f", &NewAngle[i]);
            fscanf(fin, "%f", &NewAngle2[i]);
        }
    }
    float alpha = (t%50) / 50.0;
    for(int i=0; i<20; i++){
        angle[i] = alpha * NewAngle[i] + (1-alpha) * OldAngle[i];
        angle2[i] = alpha * NewAngle2[i] + (1-alpha) * OldAngle2[i];
    }
    glutPostRedisplay();
}

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

void keyboard(unsigned char key, int x, int y){
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='4') ID = 4;    ///0603新增
    if(key=='5') ID = 5;    ///0603新增
    if(key=='6') ID = 6;    ///0603新增
    if(key=='7') ID = 7;    ///0603新增
    if(key=='z') ID = 8;    ///0604新增，左半邊
    if(key=='x') ID = 9;    ///0604新增，左半邊
    if(key=='c') ID = 10;    ///0604新增，左半邊
    if(key=='v') ID = 11;    ///0604新增，左半邊
    if(key=='b') ID = 12;    ///0604新增，左半邊
    if(key=='n') ID = 13;    ///0604新增，左半邊
    if(key=='s'){
        if(fout == NULL) fout = fopen("motion.txt", "w"); ///week15-2 儲存關節位置
        for(int i=0; i<20 ;i++){
            fprintf(fout, "%.2f ", angle[i]);
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("儲存一個動作／寫了一行\n");
    }else if(key=='r'){
        if(fin == NULL) fin = fopen("motion.txt", "r");  ///week15-2 讀取關節位置
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i]);
            fscanf(fin, "%f", &angle2[i]);
        }
        glutPostRedisplay();
    }
    if(key=='p'){ ///play 三選一: save, read, play (重開)
        glutTimerFunc(0, timer, 0);
    }

}


void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScaled(0.16,0.16,0.16);
        glRotatef(180, 0, 1, 0);
//        glTranslatef(teapotx, teapoty, 0);
        /// glutSolidTeapot(0.3);
        if(body == NULL){
            head = glmReadOBJ("Model/head.obj");
            body = glmReadOBJ("Model/body.obj");

            uparmR = glmReadOBJ("Model/up_arms_R.obj");
            lowarmR = glmReadOBJ("Model/low_arms_R.obj");
            handR = glmReadOBJ("Model/hand_R.obj");///0603新增

            uplegR = glmReadOBJ("Model/up_legs_R.obj");///0603新增
            lowlegR = glmReadOBJ("Model/low_legs_R.obj");///0603新增
            footR = glmReadOBJ("Model/foot_R.obj");///0603新增

            uparmL = glmReadOBJ("Model/up_arms_L.obj"); ///0604新增，左半邊
            lowarmL = glmReadOBJ("Model/low_arms_L.obj"); ///0604新增，左半邊
            handL = glmReadOBJ("Model/hand_L.obj"); ///0604新增，左半邊

            uplegL = glmReadOBJ("Model/up_legs_L.obj"); ///0604新增，左半邊
            lowlegL = glmReadOBJ("Model/low_legs_L.obj"); ///0604新增，左半邊
            footL = glmReadOBJ("Model/foot_L.obj"); ///0604新增，左半邊

            ///glmUnitize(body);
        }

        glPushMatrix();
            /* body */

            glRotatef(angle[0] ,0 ,1 ,0);
            glRotatef(angle2[0] ,0 ,1 ,0);
            if(ID == 0) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[0]) glmDraw(body, GLM_MATERIAL | GLM_TEXTURE);

            glPushMatrix();
                /* head */
                glTranslatef(-0.000000, +2.300000, 0);
                glRotatef(angle[1] ,0 ,1 ,0);
                glRotatef(angle2[1], 0, 1, 0);
                glTranslatef(0.000000, -2.300000, 0);

                if(ID == 1) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[1]) glmDraw(head, GLM_MATERIAL | GLM_TEXTURE);
            glPopMatrix();

        ///*------------------------------------右邊設定--------------------------------------------*/
            glPushMatrix();
                /* uparmR */
                glTranslatef(-0.700000, -0.060000, 0);
                glRotatef(angle[2] ,0 ,0 ,1);
                glRotatef(angle2[2], 1, 0, 0);
                glTranslatef(0.700000, 0.060000, 0);

                if(ID == 2) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[2]) glmDraw(uparmR, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    /* lowarmR */
                    glTranslatef(-1.593332, -0.086667, 0);
                    glRotatef(angle[3], 0, 0,1);/// week15 修改為只旋轉特定關節/部位
                    glRotatef(angle2[3], 1, 0, 0);
                    glTranslatef(1.593332, 0.086667, 0);

                    if(ID == 3) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[3]) glmDraw(lowarmR, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();///0603新增
                        /* handR */
                        glTranslatef(-2.479998, -0.073333, 0);
                        glRotatef(angle[4], 0, 0, 1);/// week15 修改為只旋轉特定關節/部位
                        glRotatef(angle2[4], 1, 0, 0);
                        glTranslatef(2.479998, 0.073333, 0);

                        if(ID == 4) glColor3f(1,0,0);
                        else glColor3f(1,1,1);
                        if(show[4]) glmDraw(handR, GLM_MATERIAL | GLM_TEXTURE);

                    glPopMatrix();///0603新增
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();///0603新增
                /* uplegR */
                glTranslatef(-0.500000, -2.500000, 0);
                glRotatef(angle[5], 0, 0, 1);/// week15 修改為只旋轉特定關節/部位
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef(0.500000, 2.500000, 0);

                if(ID == 5) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[5]) glmDraw(uplegR, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();///0603新增
                    /* lowlegR */
                    glTranslatef(-0.400000, -3.299999, 0);
                    glRotatef(angle[6], 0, 0, 1);/// week15 修改為只旋轉特定關節/部位
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef(0.400000, 3.299999, 0);

                    if(ID == 6) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[6]) glmDraw(lowlegR, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();///0603新增
                        /* footR */
                        glTranslatef(-0.300000, -4.400000, 0);
                        glRotatef(angle[7], 0, 1, 0);/// week15 修改為只旋轉特定關節/部位
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef(0.300000, 4.400000, 0);

                        if(ID == 7) glColor3f(1,0,0);
                        else glColor3f(1,1,1);
                        if(show[7]) glmDraw(footR, GLM_MATERIAL | GLM_TEXTURE);

                    glPopMatrix();///0603新增
                glPopMatrix();///0603新增
            glPopMatrix();///0603新增
        ///*------------------------------------右邊設定--------------------------------------------*/
        ///*------------------------------------左邊設定--------------------------------------------*////0604新增
            glPushMatrix();
                /* uparmL */
                glTranslatef(0.700000, -0.060000, 0);
                glRotatef(angle[8] ,0 ,0 ,1);
                glRotatef(angle2[8], 1, 0, 0);
                glTranslatef(-0.700000, 0.060000, 0);

                if(ID == 8) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[8]) glmDraw(uparmL, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    /* lowarmL */
                    glTranslatef(1.593332, -0.086667, 0);
                    glRotatef(angle[9], 0, 0, 1);/// week15 修改為只旋轉特定關節/部位
                    glRotatef(angle2[9], 1, 0, 0);
                    glTranslatef(-1.593332, 0.086667, 0);

                    if(ID == 9) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[9]) glmDraw(lowarmL, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        /* handL */
                        glTranslatef(2.479998, -0.073333, 0);
                        glRotatef(angle[10], 0, 0, 1);/// week15 修改為只旋轉特定關節/部位
                        glRotatef(angle2[10], 1, 0, 0);
                        glTranslatef(-2.479998, 0.073333, 0);

                        if(ID == 10) glColor3f(1,0,0);
                        else glColor3f(1,1,1);
                        if(show[10]) glmDraw(handL, GLM_MATERIAL | GLM_TEXTURE);

                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();
                /* uplagL */
                glTranslatef(+0.500000, -2.500000, 0);
                glRotatef(angle[11], 0, 0, 1);/// week15 修改為只旋轉特定關節/部位
                glRotatef(angle2[11], 1, 0, 0);
                glTranslatef(-0.500000, 2.500000, 0);

                if(ID == 11) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[11]) glmDraw(uplegL, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    /* lowlagL */
                    glTranslatef(0.400000, -3.299999, 0);
                    glRotatef(angle[12], 0, 0, 1);/// week15 修改為只旋轉特定關節/部位
                    glRotatef(angle2[12], 1, 0, 0);
                    glTranslatef(-0.400000, 3.299999, 0);

                    if(ID == 12) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[12]) glmDraw(lowlegL, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        /* footL */
                        glTranslatef(0.300000, -4.400000, 0);
                        glRotatef(angle[13], 0, 1, 0);/// week15 修改為只旋轉特定關節/部位
                        glRotatef(angle2[13], 1, 0, 0);
                        glTranslatef(-0.300000, 4.400000, 0);

                        if(ID == 13) glColor3f(1,0,0);
                        else glColor3f(1,1,1);
                        if(show[13]) glmDraw(footL, GLM_MATERIAL | GLM_TEXTURE);

                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
    ///*------------------------------------左邊設定--------------------------------------------*/    ///0604新增
        glPopMatrix();
//        glColor3f(0,1,0);
//        glutSolidTeapot(0.02);
    glPopMatrix();
    glutSwapBuffers();

}
int oldX = 0; int oldY = 0;
void motion(int x , int y){
///    teapotx += (x - oldX)/150.0;
///    teapoty -= (y - oldY)/150.0;
///    angle[ID] += (x - oldX);/// week15 修改為只旋轉特定關節/部位
///    oldX = x;
///    oldY = y;
    ///angle = x;
    teapotx += (x - oldX)/10.0; ///有不同
    teapoty += (oldY - y)/10.0; ///有不同
    angle[ID] += x - oldX;
    oldX = x;
    angle2[ID] += y - oldY;
    oldY = y;

    printf("glTranslatef(%f, %f, 0);\n", teapotx, teapoty);
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){

    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
        ///angle = x;
        ///teapotx = (x-150)/150.0;
        ///teapoty = (150-y)/150.0;
    }
    display();
}

int textture1 , textture2;
int main(int argc, char** argv){

    myMP3.Load("music_Polluk.mp3"); ///相對路徑 Related path
    myMP3.Play();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("final");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);
//    textture1 = myTexture("model/KERORO_FACE.png");
//    glBindTexture(GL_TEXTURE_2D, textture1);
    myTexture("model/KERORO_FACE.png");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
