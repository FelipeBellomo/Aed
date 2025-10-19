#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);



int main() {
    int numRows = 5;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** result = generate(numRows, &returnSize, &returnColumnSizes);

        for (int i = 0; i < returnSize; i++) {
            for (int j = 0; j < returnColumnSizes[i]; j++) {
                printf("%d ", result[i][j]);
            }
            printf("\n");
    }

    
    if (result) {
        for (int i = 0; i < returnSize; i++)
            free(result[i]);
        free(result);
    }
    free(returnColumnSizes);

    return 0;

    return 0;
}

int** generate(int numRows, int* returnSize, int** returnColumnSizes) {    
    *returnSize = numRows;
    int str = 0;
    int** pascal =(int**)malloc(sizeof(int*) * numRows);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numRows);

    pascal[0] = (int*)malloc(sizeof(int) * 1); 
    (*returnColumnSizes)[0] = 1;

    if(numRows < 0)
        return NULL;
    
    pascal[0][0] = 1;

    for (str = 1 ; str < numRows; str++){
        int index = 0;
    
        //malloca o numero de itens em cada string
        (*returnColumnSizes)[str] = str + 1;
        pascal[str] = (int*)malloc(sizeof(int) * (str + 1));

        //insere 1 no inicio e no final
        pascal[str][0] = 1;
        pascal[str][str] = 1;

        for (int soma = 1; soma < str && index < numRows -2 ; soma++){
            pascal[str][soma] = pascal[str - 1][index] + pascal[str - 1][index + 1];          
            index++;
        }
        

    }
    
    return pascal;
    
}

//pascal[0]
//pascal[0][0]
//*pascal[0]
//(*pascal)[0]