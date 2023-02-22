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
    glColor3f(1,0,1);       myCricle(0.6,0,0); ///正中間
    ///glColor3f(244/255.0,209/255.0,33/255.0);
    glColor3f(1,0,0);       myCricle(0.3,0.5,0.5); ///右上
    glColor3f(0,1,0);       myCricle(0.3,-0.5,0.5); ///左上
    glColor3f(1,1,0);       myCricle(0.3,-0.5,-0.5); ///左下
    glColor3f(0,0,1);       myCricle(0.3,0.5,-0.5); ///右下

    glutSwapBuffers(); ///step 01-1請GLUT畫面swap送到顯示的地方
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///開啟GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///設定顯示模式
    glutCreateWindow("GLUT Shapes");///開視窗
    glutDisplayFunc(display);///要顯示的對應函示"display()"
   glutMainLoop();/// 壓最後
}
