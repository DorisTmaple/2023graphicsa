#include <GL/glut.h>

float angle = 0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot(0.3);
//    glScaled(0.2,0.2,0.2);
//        /// glTranslatef(teapotx, teapoty, 0);
//        /// glutSolidTeapot(0.3);
//        if(body == NULL){
//            head = glmReadOBJ("Model/head.obj");
//            body = glmReadOBJ("Model/wholebody.obj");
//            uparmR = glmReadOBJ("Model/uparmR.obj");
//            lowarmR = glmReadOBJ("Model/armhandR.obj");
//            ///glmUnitize(body);
//        }
//        if(show[0]) glmDraw(head, GLM_MATERIAL);
//        if(show[1]) glmDraw(body, GLM_MATERIAL);
//        glPushMatrix();
//            glTranslatef(teapotx, teapoty, 0);
//            if(show[2]) glmDraw(uparmR, GLM_MATERIAL);
//        glPopMatrix();
//        if(show[3]) glmDraw(lowarmR, GLM_MATERIAL);
    glPopMatrix();
    glutSwapBuffers();

}

void timer(int t){
    glutTimerFunc(500, timer, t+1); /// 設定下一個轉動timer
    angle += 90;
    glutPostRedisplay(); /// 重畫畫面

}

void keyboard(unsigned char key, int x, int y){
    glutTimerFunc(0, timer, 0); /// 設定timer函式

//    if(fin == NULL){
//            fclose(fout);
//        fin = fopen("file4.txt", "r");
//    }
//    fscanf(fin, "%f %f/n", &teapotx, &teapoty);
//    display();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week14");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    //glutTimerFunc(2000, timer, 0); /// 設定timer函式
//    glutMouseFunc(mouse);
//    glutMotionFunc(motion);
//    glutKeyboardFunc(keyboard);

    glutMainLoop();
}

