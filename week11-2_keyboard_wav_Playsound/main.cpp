#include <windows.h> /// 這個很重要，要放第一個
#include <GL/glut.h>



void display()
{
    glutSolidTeapot(0.3);
    glutSwapBuffers();
}

void keyboard(unsigned char key , int x , int y)
{
    if(key=='1') /// 播放音樂檔的方法1：輸入絕對路徑，在這裡"\\"表示一個"\"
        PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\do.wav",NULL,SND_ASYNC);
    if(key=='2')
        PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\re.wav",NULL,SND_ASYNC);
    if(key=='3')
        PlaySound("C:\\Users\\Administrator\\Desktop\\do_re_mi\\mi.wav",NULL,SND_ASYNC);
    ///if(key==27) exit(886);
}///按esc就會關閉

int main(int argc, char**argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week11");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    glutMainLoop();

}
