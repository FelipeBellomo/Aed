#include <stdio.h>
#include <stdlib.h>

void percorreValor(int* b);

int main(){
    int a[4] = {1,2,3,4};

    percorreValor(a);

}

void percorreValor(int* b){
   
    for(int i = 0; i < 4; i++){
        printf("%d",*b);
        b++;
    }

}