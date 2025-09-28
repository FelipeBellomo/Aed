#include <stdio.h>
#include <stdlib.h>


int main() {
    int a = 1, *b, **c, ***d;
    printf("%d\n", a);

    b = &a;   
    c = &b;   
    d = &c;   

    *b = *b * 2;   
    printf("%d\n", *b);   
    **c = *b * 3;    
    printf("%d\n", **c); 
    ***d = **c * 2;   
    printf("%d\n", ***d);

    printf("%d %d %d %d\n", a, *b, **c, ***d);
    return 0;
}