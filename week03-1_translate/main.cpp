#include <GL/glut.h>

float X=0,Y=0; /// step02-2 利用global變數，在函示之間傳值
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///清背景
    glPushMatrix();  ///step01-2 備份矩陣
        glTranslatef( X, Y, 0); ///  讓位於正中心的茶壺往右方移動

        glutSolidTeapot(0.3); ///劃出實心茶壺；大小0.3
    glPopMatrix();  ///還原矩陣

    glutSwapBuffers(); ///請GLUT畫面swap送到顯示的地方

}
///#include<stdio.h>/// step 02-1
void mouse(int button, int state, int x, int y)
{/// step 02-1  請mouse函式幫忙
    ///printf("%d,%d,%d,%d\n", button,state,x,y);
    X = (x-150)/150.0;
    Y = -(y-150)/150.0;
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///開啟GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///設定顯示模式
    glutCreateWindow("week03");///開視窗
    glutDisplayFunc(display);///要顯示的對應函示"display()"
    glutMouseFunc(mouse);  /// step 02-1  請mouse函式幫忙
   glutMainLoop();/// 壓最後
}
