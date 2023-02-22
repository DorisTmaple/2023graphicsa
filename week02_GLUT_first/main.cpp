#include <GL/glut.h>
///week02-1
void display()
{
    ///glColor3f(0.4,0.2,0.2);/// step 01-2增加色彩－藍色(0.1,0.4,0.6)、淡紅色(0.4,0.2,0.2)
    ///glutSolidTeapot(0.6); ///劃出實心茶壺；大小0.6
    glBegin(GL_POLYGON); /// step 02-1  glBegin()開始畫；GL_POLYGON為多邊形的函數
        glColor3f(1,0,0);     glVertex2f(0,1);  ///紅色的頂點Vertex
        glColor3f(0,1,0);     glVertex2f(-1,-1);  ///綠色的頂點Vertex
        glColor3f(0,0,1);     glVertex2f(1,-1);  ///藍色的頂點Vertex
    glEnd();/// step 02-1

    glColor3f(1,1,0);/// step 01-2 增加色彩－黃色
    glutSolidTeapot(0.3); ///step 01-1劃出實心茶壺；大小0.3
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
