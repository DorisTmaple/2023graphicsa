///此為"寫"檔案
#include <stdio.h>

int main(){

    FILE * fout = fopen("file.txt", "w"); ///w表示write

    printf("Hello World\n");
    fprintf(fout,"Hello World在檔案裡\n");
}




