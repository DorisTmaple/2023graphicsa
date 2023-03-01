#include <GL/glut.h>
#include <stdio.h>

void display()
{
    ///glutSolidTeapot(0.3); ///劃出實心茶壺；大小0.3
    /// glBegin(GL_LINE_LOOP); /// 空心線圖
    glBegin(GL_POLYGON);

        glVertex2f(-0.232, 0.128);
        glVertex2f(-0.240, 0.108);
        glVertex2f(-0.264, 0.100);
        glVertex2f(-0.296, 0.100);
        glVertex2f(-0.340, 0.100);
        glVertex2f(-0.384, 0.100);
        glVertex2f(-0.420, 0.100);
        glVertex2f(-0.448, 0.064);
        glVertex2f(-0.452, 0.012);
        glVertex2f(-0.440, -0.024);
        glVertex2f(-0.388, -0.080);
        glVertex2f(-0.308, -0.116);
        glVertex2f(-0.296, -0.140);
        glVertex2f(-0.212, -0.228);
        glVertex2f(-0.124, -0.228);
        glVertex2f(-0.052, -0.228);
        glVertex2f(0.068, -0.240);
        glVertex2f(0.172, -0.240);
        glVertex2f(0.228, -0.220);
        glVertex2f(0.276, -0.136);
        glVertex2f(0.344, -0.100);
        glVertex2f(0.376, -0.080);
        glVertex2f(0.332, -0.004);
        glVertex2f(0.328, 0.048);
        glVertex2f(0.296, 0.044);
        glVertex2f(0.292, -0.012);
        glVertex2f(0.256, 0.060);
        glVertex2f(0.228, 0.108);
        glVertex2f(0.216, 0.140);
    glEnd();
    glutSwapBuffers(); ///請GLUT畫面swap送到顯示的地方
}

void mouse(int button, int state, int x, int y)
{/// step 02-1  請mouse函式幫忙
    ///printf("%d,%d,%d,%d\n", button,state,x,y);
    float X = (x-250)/250.0; /// 根據視窗大小作調整(預設視窗300)
    float Y = -(y-250)/250.0;
    if(state==GLUT_DOWN){ ///step03-1 取得點擊座標
        printf("        glVertex2f(%.3f, %.3f);\n",X ,Y);
    }
}


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);///開啟GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    ///設定顯示模式
    glutInitWindowSize(500,500);  /// 設定視窗大小 500*500
    glutCreateWindow("week03");///開視窗
    glutDisplayFunc(display);///要顯示的對應函示"display()"
    glutMouseFunc(mouse);  /// step 02-1  請mouse函式幫忙
   glutMainLoop();/// 壓最後
}
