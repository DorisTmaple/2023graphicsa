#include <GL/glut.h>

float X=0,Y=0; //
float angle = 0; ///
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///清背景
    glColor3f(0,1,0); /// green
    glPushMatrix();  /// 備份矩陣
        glTranslatef( 0.8,0, 0); ///  讓位於正中心的茶壺往右方移動
        glRotatef(angle,0,0,1); ///旋轉的角度angle ==> 轉動茶壺
        glutSolidTeapot(0.3); ///劃出實心茶壺；大小0.3
    glPopMatrix();  ///還原矩陣

    glColor3f(1,0,0); ///red
    glPushMatrix();
        glRotatef(angle,0,0,1); /// 轉動茶壺
        glTranslatef( 0.8, 0, 0);///  將隨不同角度進行移動並旋轉
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers(); ///請GLUT畫面swap送到顯示的地方

    angle++; ///  把角度++

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
