#include <GL/glut.h>

float X=0,Y=0; //
float angle = 0; ///step02-1

void display()
{
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///清背景

    glPushMatrix();  ///備份矩陣
        glColor3f(1,1,0);
        glTranslatef( 0.6, 0, 0); ///step03-2 先移動在旋轉
        glRotatef(angle,0,1,0); /// step02-1 旋轉的角度angle
        glutSolidTeapot(0.3);
    glPopMatrix();  ///還原矩陣

    glPushMatrix();  ///備份矩陣
        glColor3f(1,0,0); /// 紅
        glRotatef(angle,0,1,0); /// step02-1 旋轉的角度angle
        glTranslatef( 0.6, 0, 0); ///step03-2 先旋轉在移動
        glutSolidTeapot(0.3);
    glPopMatrix();  ///還原矩陣

    glutSwapBuffers(); ///請GLUT畫面swap送到顯示的地方

    angle++; /// step02-1 把角度++

}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///開啟GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///設定顯示模式
    glutCreateWindow("week04");///開視窗
    glutDisplayFunc(display);///要顯示的對應函示"display()"
    glutIdleFunc(display);
    //glutMouseFunc(mouse);  /// step 02-1  請mouse函式幫忙
   glutMainLoop();/// 壓最後
}
