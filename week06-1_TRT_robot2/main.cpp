#include <GL/glut.h>
/// week06-1

float X=0,Y=0; //
float angle = 0; ///
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///清背景
    //glColor3f(0,1,0); /// green body
    glutSolidSphere(0.02,30,30); ///利用圓球找出正中央
    glPushMatrix();  /// 備份矩陣

        glTranslatef(0.25,0.25,0);  ///(3)將茶壺放置到要放的位置
        glRotatef(angle,0,0,1);  /// (2)轉動看成果是否符合預想
        glTranslatef(0.46,-0.05,0); ///(1)將茶壺中心放置正中央
        glutSolidTeapot(0.3);
    glPopMatrix();  ///還原矩陣

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
