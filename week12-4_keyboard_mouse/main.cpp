
#include <stdio.h>
#include <GL/glut.h>

float teapotx = 0, teapoty = 0;
FILE * fout = NULL;
FILE * fin = NULL;

void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotx, teapoty, 0);
        glutSolidTeapot(0.3);
    glPopMatrix();
    glutSwapBuffers();

}

void mouse(int button, int state, int x, int y){

    if(state==GLUT_DOWN){
        teapotx = (x-150)/150.0;
        teapoty = (150-y)/150.0;
        if(fout == NULL) fout = fopen("file4.txt", "w");
        fprintf(fout, "%f %f/n", teapotx, teapoty);
    }
    display();
}

void keyboard(unsigned char key, int x, int y){

    if(fin == NULL){
            fclose(fout);
        fin = fopen("file4.txt", "r");
    }
    fscanf(fin, "%f %f/n", &teapotx, &teapoty);
    display();
}

int main(int argc, char** argv){

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
