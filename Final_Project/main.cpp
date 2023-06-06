#include <GL/glut.h>
#include <stdio.h>
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
#include "glm.h"
#include "CMP3_MCI.h"

CMP3_MCI myMP3;

GLMmodel * head = NULL;
GLMmodel * body = NULL;

GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
GLMmodel * handR = NULL; ///0603�s�W

GLMmodel * uplegR = NULL; ///0603�s�W
GLMmodel * lowlegR = NULL; ///0603�s�W
GLMmodel * footR = NULL; ///0603�s�W

GLMmodel * uparmL = NULL; ///0604�s�W�A���b��
GLMmodel * lowarmL = NULL; ///0604�s�W�A���b��
GLMmodel * handL = NULL; ///0604�s�W�A���b��

GLMmodel * uplegL = NULL; ///0604�s�W�A���b��
GLMmodel * lowlegL = NULL; ///0604�s�W�A���b��
GLMmodel * footL = NULL; ///0604�s�W�A���b��

int show[14] = {1,1, 1,1,1, 1,1,1, 1,1,1, 1,1,1,}; ///0603�s�W��7�����A0604�s�W��14�����
int ID = 0; /// 0->�Y�B1->���B2->�W���u�B3->�U���u

FILE * fout = NULL;///week15-2 �x�s���`��m
FILE * fin = NULL;///week15-2 Ū�����`��m
float teapotx = 0, teapoty = 0;
float angle[20] = {}; /// week15 �קאּ�u����S�w���`/����
float angle2[20] = {};
float OldAngle[20]={}, NewAngle[20]={};
float OldAngle2[20]={}, NewAngle2[20]={};

void timer(int t){
    glutTimerFunc(5, timer, t+1 );
    if(t%50==0){///�s���ͨϡA�nŪ�ʧ@
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

void keyboard(unsigned char key, int x, int y){
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='4') ID = 4;    ///0603�s�W
    if(key=='5') ID = 5;    ///0603�s�W
    if(key=='6') ID = 6;    ///0603�s�W
    if(key=='7') ID = 7;    ///0603�s�W
    if(key=='z') ID = 8;    ///0604�s�W�A���b��
    if(key=='x') ID = 9;    ///0604�s�W�A���b��
    if(key=='c') ID = 10;    ///0604�s�W�A���b��
    if(key=='v') ID = 11;    ///0604�s�W�A���b��
    if(key=='b') ID = 12;    ///0604�s�W�A���b��
    if(key=='n') ID = 13;    ///0604�s�W�A���b��
    if(key=='s'){
        if(fout == NULL) fout = fopen("motion.txt", "w"); ///week15-2 �x�s���`��m
        for(int i=0; i<20 ;i++){
            fprintf(fout, "%.2f ", angle[i]);
            fprintf(fout, "%.2f ", angle2[i] );
        }
        fprintf(fout, "\n");
        printf("�x�s�@�Ӱʧ@���g�F�@��\n");
    }else if(key=='r'){
        if(fin == NULL) fin = fopen("motion.txt", "r");  ///week15-2 Ū�����`��m
        for(int i=0; i<20; i++){
            fscanf(fin, "%f", &angle[i]);
            fscanf(fin, "%f", &angle2[i]);
        }
        glutPostRedisplay();
    }
    if(key=='p'){ ///play �T��@: save, read, play (���})
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
            handR = glmReadOBJ("Model/hand_R.obj");///0603�s�W

            uplegR = glmReadOBJ("Model/up_legs_R.obj");///0603�s�W
            lowlegR = glmReadOBJ("Model/low_legs_R.obj");///0603�s�W
            footR = glmReadOBJ("Model/foot_R.obj");///0603�s�W

            uparmL = glmReadOBJ("Model/up_arms_L.obj"); ///0604�s�W�A���b��
            lowarmL = glmReadOBJ("Model/low_arms_L.obj"); ///0604�s�W�A���b��
            handL = glmReadOBJ("Model/hand_L.obj"); ///0604�s�W�A���b��

            uplegL = glmReadOBJ("Model/up_legs_L.obj"); ///0604�s�W�A���b��
            lowlegL = glmReadOBJ("Model/low_legs_L.obj"); ///0604�s�W�A���b��
            footL = glmReadOBJ("Model/foot_L.obj"); ///0604�s�W�A���b��

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

        ///*------------------------------------�k��]�w--------------------------------------------*/
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
                    glRotatef(angle[3], 0, 0,1);/// week15 �קאּ�u����S�w���`/����
                    glRotatef(angle2[3], 1, 0, 0);
                    glTranslatef(1.593332, 0.086667, 0);

                    if(ID == 3) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[3]) glmDraw(lowarmR, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();///0603�s�W
                        /* handR */
                        glTranslatef(-2.479998, -0.073333, 0);
                        glRotatef(angle[4], 0, 0, 1);/// week15 �קאּ�u����S�w���`/����
                        glRotatef(angle2[4], 1, 0, 0);
                        glTranslatef(2.479998, 0.073333, 0);

                        if(ID == 4) glColor3f(1,0,0);
                        else glColor3f(1,1,1);
                        if(show[4]) glmDraw(handR, GLM_MATERIAL | GLM_TEXTURE);

                    glPopMatrix();///0603�s�W
                glPopMatrix();
            glPopMatrix();
            glPushMatrix();///0603�s�W
                /* uplegR */
                glTranslatef(-0.500000, -2.500000, 0);
                glRotatef(angle[5], 0, 0, 1);/// week15 �קאּ�u����S�w���`/����
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef(0.500000, 2.500000, 0);

                if(ID == 5) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[5]) glmDraw(uplegR, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();///0603�s�W
                    /* lowlegR */
                    glTranslatef(-0.400000, -3.299999, 0);
                    glRotatef(angle[6], 0, 0, 1);/// week15 �קאּ�u����S�w���`/����
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef(0.400000, 3.299999, 0);

                    if(ID == 6) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[6]) glmDraw(lowlegR, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();///0603�s�W
                        /* footR */
                        glTranslatef(-0.300000, -4.400000, 0);
                        glRotatef(angle[7], 0, 1, 0);/// week15 �קאּ�u����S�w���`/����
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef(0.300000, 4.400000, 0);

                        if(ID == 7) glColor3f(1,0,0);
                        else glColor3f(1,1,1);
                        if(show[7]) glmDraw(footR, GLM_MATERIAL | GLM_TEXTURE);

                    glPopMatrix();///0603�s�W
                glPopMatrix();///0603�s�W
            glPopMatrix();///0603�s�W
        ///*------------------------------------�k��]�w--------------------------------------------*/
        ///*------------------------------------����]�w--------------------------------------------*////0604�s�W
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
                    glRotatef(angle[9], 0, 0, 1);/// week15 �קאּ�u����S�w���`/����
                    glRotatef(angle2[9], 1, 0, 0);
                    glTranslatef(-1.593332, 0.086667, 0);

                    if(ID == 9) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[9]) glmDraw(lowarmL, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        /* handL */
                        glTranslatef(2.479998, -0.073333, 0);
                        glRotatef(angle[10], 0, 0, 1);/// week15 �קאּ�u����S�w���`/����
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
                glRotatef(angle[11], 0, 0, 1);/// week15 �קאּ�u����S�w���`/����
                glRotatef(angle2[11], 1, 0, 0);
                glTranslatef(-0.500000, 2.500000, 0);

                if(ID == 11) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[11]) glmDraw(uplegL, GLM_MATERIAL | GLM_TEXTURE);

                glPushMatrix();
                    /* lowlagL */
                    glTranslatef(0.400000, -3.299999, 0);
                    glRotatef(angle[12], 0, 0, 1);/// week15 �קאּ�u����S�w���`/����
                    glRotatef(angle2[12], 1, 0, 0);
                    glTranslatef(-0.400000, 3.299999, 0);

                    if(ID == 12) glColor3f(1,0,0);
                    else glColor3f(1,1,1);
                    if(show[12]) glmDraw(lowlegL, GLM_MATERIAL | GLM_TEXTURE);

                    glPushMatrix();
                        /* footL */
                        glTranslatef(0.300000, -4.400000, 0);
                        glRotatef(angle[13], 0, 1, 0);/// week15 �קאּ�u����S�w���`/����
                        glRotatef(angle2[13], 1, 0, 0);
                        glTranslatef(-0.300000, 4.400000, 0);

                        if(ID == 13) glColor3f(1,0,0);
                        else glColor3f(1,1,1);
                        if(show[13]) glmDraw(footL, GLM_MATERIAL | GLM_TEXTURE);

                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();
    ///*------------------------------------����]�w--------------------------------------------*/    ///0604�s�W
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
///    angle[ID] += (x - oldX);/// week15 �קאּ�u����S�w���`/����
///    oldX = x;
///    oldY = y;
    ///angle = x;
    teapotx += (x - oldX)/10.0; ///�����P
    teapoty += (oldY - y)/10.0; ///�����P
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

    myMP3.Load("music_Polluk.mp3"); ///�۹���| Related path
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
