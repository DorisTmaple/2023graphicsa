///����"Ū"�ɮ�
#include <stdio.h>

int main(){

    FILE * fin = fopen("file.txt", "r"); ///r���read

    char line[100];
    fscanf(fin,"%s",line);
    printf("�q�ɮ׸�Ū��G%s\n",line);

    fscanf(fin,"%s",line);
    printf("�q�ɮ׸�Ū��G%s\n",line);
}





