///此為"讀"檔案
#include <stdio.h>

int main(){

    FILE * fin = fopen("file.txt", "r"); ///r表示read

    char line[100];
    fscanf(fin,"%s",line);
    printf("從檔案裡讀到：%s\n",line);

    fscanf(fin,"%s",line);
    printf("從檔案裡讀到：%s\n",line);
}





