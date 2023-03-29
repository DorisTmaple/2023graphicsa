#include <opencv/highgui.h>

int main()
{
    IplImage * img = cvLoadImage("Image.jpg");
    cvShowImage("week07", img);
    cvWaitKey(0);
}






