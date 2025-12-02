    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize);

    int main() {
        int temperaturesSize = 8;
        int temperatures[8] = {73,74,75,71,69,72,76,73};
        int returnSize = 0;

        int* retorno = dailyTemperatures(temperatures, temperaturesSize,&returnSize);

        for (int i = 0; i < returnSize; i++) {
            printf("%d",retorno[i]);
        }
        
        return 0;
    }

int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int* asw = (int*) calloc(temperaturesSize, sizeof(int));  // já inicia com zeros
    int* stack = (int*) malloc(sizeof(int) * temperaturesSize);

    int top = -1;
    *returnSize = temperaturesSize;

    for (int i = 0; i < temperaturesSize; i++) {

        while (top != -1 && temperatures[i] > temperatures[stack[top]]) {
            int idx = stack[top--];   
            asw[idx] = i - idx;         
        }

        stack[++top] = i;  
    }

    free(stack);
    return asw;
}

/*
posição 0 = top[0] -> i

*/