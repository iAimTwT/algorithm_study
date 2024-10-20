#include <stdio.h>
#include <stdlib.h>

int main(){
    char p[]={'1','2','3'},*q = p;
    int n = sizeof(*q);
    printf("%c",p);
    system("pause");
    return 0;
}