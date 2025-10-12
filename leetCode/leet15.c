#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main() {
    int nums[] = {0,0,0};
    int numsSize = 3;
    int returnSize = 0;
    int* returnColumnSizes = NULL;

    int** resultado = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < (returnColumnSizes ? returnColumnSizes[i] : 0); j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    
    if (resultado) {
        for (int i = 0; i < returnSize; i++)
            free(resultado[i]);
        free(resultado);
    }
    free(returnColumnSizes);

    return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    
    int k = 0, j = 0, i = 0,c = 0;
    int** retorno = (int**)malloc(sizeof(int*) * 1);
    //int existeString = 0;
    int strin = 0;
    *returnColumnSizes = (int*)malloc(3 * sizeof(int)); 
    

     for (i = 0; i < numsSize; i++) {
         for (j = i + 1; j < numsSize && j != i; j++) {
             for (k = j + 1; k < numsSize && k != j; k++) {
                 if (nums[i] + nums[j] + nums[k] == 0) {
                     c++;          
                     *returnSize = c;
                     retorno = (int**)realloc(retorno, c * sizeof(int*)); // aloca o numero de trios
                     retorno[c - 1] = (int*)malloc(3 * sizeof(int)); // aloca o tamanho de cada trio
                     retorno[c - 1][0] = nums[i];      //adiciona
                     retorno[c - 1][1] = nums[j];     //
                     retorno[c - 1][2] = nums[k];  
                     break;
                     }
             }
            
         }
     }
       if (c > 0) {
            *returnColumnSizes = malloc(c * sizeof(int));
            for (i = 0; i < c; i++)
                (*returnColumnSizes)[i] = 3;
        }
    
    
    //bool testeComp = false;

    if (*returnSize > 1) {
        for (strin = 0; strin < *returnSize; strin++) {
            if (retorno[strin] == NULL) continue;

            for (int proximo = strin + 1; proximo < *returnSize; proximo++) {
                if (retorno[proximo] == NULL) continue;

                int iguais = 0;
                for (int a = 0; a < 3; a++) {
                    for (int b = 0; b < 3; b++) {
                        if (retorno[strin] == NULL || retorno[proximo] == NULL)
                            break;
                            
                        if (retorno[strin][a] == retorno[proximo][b]) {
                            iguais++;
                            break;
                        }
                    }
                }

                if (iguais == 3) { 
                    free(retorno[proximo]);  
                    retorno[proximo] = NULL;  
                }
            }
        }

        
        int novoTamanho = 0;


        for (i = 0; i < *returnSize; i++) {  //reordena a matriz
            if (retorno[i] != NULL)
                retorno[novoTamanho++] = retorno[i];
        }

        *returnSize = novoTamanho;
        *returnColumnSizes = realloc(*returnColumnSizes, novoTamanho * sizeof(int));
    }

    return retorno;
}

 
    


//   if(*returnSize > 1){
//        for (strin = 0; strin < (unsigned long int)*returnSize; strin++){
//        existeString = 0;
//        for (int caracter = 0; caracter < 3 && strin < sizeof(retorno); caracter++){
//            for (int caracter2 = 0; caracter2 < 3; caracter2++){
//                if(retorno[strin][caracter] == retorno[strin+1][caracter2]){
//                    existeString++;
//                    excluiString = strin + 1;
//                }else{
//                    testeCompara = true;

                //
                //
//                }
//        }
//        if(existeString == 3){
//            free(retorno[excluiString]);
//        }
//    }

//

