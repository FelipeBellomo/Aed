#include <stdio.h>
#include <stdlib.h>

void mudaValor(int* c,int*d);

int main(){
    int a =0,b=0;

    printf("Defina valores\n");
    scanf("%d %d",&a,&b);

    mudaValor(&a,&b);

    printf("%d %d\n",a,b);


}

void mudaValor(int* c,int*d){
    int t = *c;
    *c = *d;
    *d = t;

}