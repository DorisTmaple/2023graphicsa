#include <GL/glut.h>
/// week06-2 改自06-1
///劃出大身體跟大手臂

float X=0,Y=0; //
float angle = 0; ///
void drawHand()
{
    glPushMatrix();
    glScaled(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  ///清背景
    //glColor3f(0,1,0); /// green body
    glPushMatrix(); ///右上手臂
        glTranslatef(0.25,0,0);
        glRotatef(angle,0,0,1);  ///
        glTranslatef(0.25,0,0); ///
        ///step 03-1
        drawHand(); ///右上手臂

            glPushMatrix(); ///右上手肘
                glTranslatef(0.25,0,0);
                glRotatef(angle,0,0,1);  ///
                glTranslatef(0.25,0,0);
                drawHand();
            glPopMatrix(); ///右上手肘

    glPopMatrix();


    glPushMatrix(); ///左上手臂
        glTranslatef(-0.25,0,0);
        glRotatef(angle,0,0,1);  ///
        glTranslatef(-0.25,0,0); ///
        ///step 03-1
        drawHand(); ///左上手臂

            glPushMatrix(); ///左上手肘
                glTranslatef(-0.25,0,0);
                glRotatef(angle,0,0,1);  ///
                glTranslatef(-0.25,0,0);
                drawHand();
            glPopMatrix(); ///左上手肘

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
