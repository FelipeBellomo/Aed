#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main() {
    int digits[] = {9,8,9};
    int digitsSize = 3;
    int returnSize = 0;

    int* sum = plusOne(digits, digitsSize, &returnSize);

    for (int i = 0; i < returnSize; i++)
    {
        printf("%d",sum[i]);
    }
    
    return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* soma =(int*)malloc(sizeof(int) * digitsSize);
    int carry = 0;
    int extend = 0;

    if((digits[digitsSize - 1] + 1) == 10){

        for (int i = digitsSize - 1; i >= 0; i--){

            if(i == 0 && digits[i] + 1 == 10){

                digitsSize++;
                soma = (int*)realloc(soma,sizeof(int) * digitsSize);
                soma[0] = 1;
                extend = 1;
                for(int v1 = 1; v1 < digitsSize; v1++){
                    soma[v1] = 0;                    
                }
                break;
            }
            if((digits[i] + 1) == 10){
                carry = 1;
                digits[i] = 0;
                continue;
            }else{
                digits[i] += carry;
                carry = 0;
                break;

            }
            

        }
    }else digits[digitsSize - 1] += 1;

    if(extend == 0){

        for (int i = 0; i < digitsSize; i++){
            soma[i] = digits[i];
        }       
    }

    *returnSize = digitsSize;
    
    return soma;
    
}