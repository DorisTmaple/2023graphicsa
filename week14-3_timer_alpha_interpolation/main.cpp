#include <GL/glut.h>

float angle = 0, newAngle = 0, oldAngle = 0;

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();

}

void timer(int t){
    if(t<100)    glutTimerFunc(50, timer, t+1); /// 設定下一個轉動timer
    float alpha = t/100.0 ; ///alpha介於0.00～1.00之間
    angle = newAngle*alpha + (1-alpha)*oldAngle;
    glutPostRedisplay(); /// 重畫畫面

}
void motion(int x , int y){
    angle = x;
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){

    if(state==GLUT_DOWN) oldAngle = x;///按下
    if(state==GLUT_UP) newAngle = x;///放開
    glutPostRedisplay();
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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
//    glutKeyboardFunc(keyboard);

    glutMainLoop();
}

