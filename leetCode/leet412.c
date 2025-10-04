#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** fizzBuzz(int n, int* returnSize);


int main() {
    int n = 15;
    int returnSize = 0;

    char** retur = fizzBuzz(n,&returnSize);

    for (int j = 0; j < returnSize; j++)
    {
        printf("%s\n ",retur[j]);
    }
    return 0;
}

char** fizzBuzz(int n, int* returnSize) {
    char** ret =(char**)malloc(sizeof(char*) * n);
    *returnSize = n;

    for (int i = 1; i <= n; i++){
        
        
        if (( i % 3) == 0){
            ret[i-1] = (char*)malloc(5);
            strcpy(ret[i-1], "Fizz");

        }

         if ((i % 5) == 0){
            ret[i-1] = (char*)malloc(5);
            strcpy(ret[i-1], "Buzz");
         }
            
        
        if ((i % 3 == 0) && (i % 5 == 0)){
            ret[i-1] = (char*)malloc(9);
            strcpy(ret[i-1], "FizzBuzz");
        }
             
            
        if ((i % 3 != 0) && (i % 5 != 0)){
            ret[i-1] = (char*)malloc(12);
            sprintf(ret[i-1],"%d",i);
        }

    }
    return ret;
    
    
}