#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 1;
    float b = 2.0;
    char c = 'A';

    int* d = &a;
    float* e = &b;
    char* f = &c;

    printf("%d\n%.2f\n%c\n",a,b,c);

    *d = 2;
    *e = 3.0;
    *f = 'B';

    printf("%d\n%.2f\n%c\n",a,b,c);

}