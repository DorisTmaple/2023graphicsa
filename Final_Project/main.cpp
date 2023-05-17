#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * uparmR = NULL;
GLMmodel * lowarmR = NULL;
int show[4] = {0,1,1,1};
int ID = 3; /// 0->頭、1->身、2->上手臂、3->下手臂
void keyboard(unsigned char key, int x, int y){
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
//    if(key=='0') show[0] = !show[0];
//    if(key=='1') show[1] = !show[1];
//    if(key=='2') show[2] = !show[2];
//    if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}

float teapotx = 0, teapoty = 0, angle = 0;
FILE * fout = NULL;
FILE * fin = NULL;

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
    glScaled(0.2,0.2,0.2);
        /// glTranslatef(teapotx, teapoty, 0);
        /// glutSolidTeapot(0.3);
        if(body == NULL){
            head = glmReadOBJ("Model/head.obj");
            body = glmReadOBJ("Model/wholebody.obj");
            uparmR = glmReadOBJ("Model/uparmR.obj");
            lowarmR = glmReadOBJ("Model/armhandR.obj");
            ///glmUnitize(body);
        }
        if(ID == 0) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[0]) glmDraw(head, GLM_MATERIAL);

        if(ID == 1) glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[1]) glmDraw(body, GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(-1.166666, 0.466667, 0);
            glRotatef(angle,0,0,1);
            glTranslatef(1.166666, -0.466667, 0);

            if(ID == 2) glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);

            glPushMatrix();
                glTranslatef(-1.933332, +0.133333, 0);
                glRotatef(angle,0,0,1);
                glTranslatef(1.933332, -0.133333, 0);

                if(ID == 3) glColor3f(1,0,0);
                else glColor3f(1,1,1);
                if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);
            glPopMatrix();
        glPopMatrix();

    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();

}
int oldX = 0; int oldY = 0;
void motion(int x , int y){
    teapotx += (x - oldX)/150.0;
    teapoty -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    angle = x;
    printf("glTranslatef(%f, %f, 0);\n", teapotx, teapoty);
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){

    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
        angle = x;
        ///teapotx = (x-150)/150.0;
        ///teapoty = (150-y)/150.0;
        //if(fout == NULL) fout = fopen("file4.txt", "w");
        //fprintf(fout, "%f %f/n", teapotx, teapoty);
    }
    display();
}

//void keyboard(unsigned char key, int x, int y){
//
//    if(fin == NULL){
//            fclose(fout);
//        fin = fopen("file4.txt", "r");
//    }
//    fscanf(fin, "%f %f/n", &teapotx, &teapoty);
//    display();
//}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
