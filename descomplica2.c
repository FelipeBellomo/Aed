#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 0, b = 0;

    if(&a > &b)
        printf("a maior");
    else printf("b maior");

    printf("%p %p",&a,&b);
}