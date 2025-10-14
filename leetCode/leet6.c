#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* convert(char* s, int numRows);

int main() {
    char s[] = {"PAYPALISHIRING"};
    int numRows = 3;

    char* zigzag = convert(s,numRows);
    printf("%s",zigzag);

    return 0;
}

char* convert(char* s, int numRows) {
    char** retorno =(char**)malloc(sizeof(char*) * numRows);
    int colunm = 0, linha = 0,caracter = 0;
    int comprimento = strlen(s);
    char resposta[comprimento];
    
    retorno[linha]=(char*)malloc(sizeof(char) * 1); 
    
    while (comprimento > 0){
        
        
        
        if(linha == (numRows - 1)){
            for(; linha >= 0; linha--, colunm++){
                retorno[linha]=(char*)malloc(sizeof(char) * colunm); 
                retorno[linha][colunm] = s[caracter];
                caracter++;
                comprimento--;
            }
        }else{
            //retorno[linha]=(char*)malloc(sizeof(char) * colunm);    //malloc de colunas
            retorno[linha][colunm] = s[caracter];
            linha++;
            caracter++;
            comprimento--;
            
        }
        if(linha < 0)
            linha = 0;
        
        if(linha < 3)
            printf("%s",retorno[1]);
        
    }
    
    int count = 0;
    for (int i = 0; i < numRows; i++){
        for (int j = 0; j < colunm && (j + 1) < colunm; j++){
            if(retorno[i][j] != '\0'){
                retorno[i][j] = resposta[count];
                count++;
            }
        }
        
    }
    
    return &resposta[0]; 
    
}
   // for(int linha = 0; linha < numRows; linha++){
   //     retorno[linha]=(char*)malloc(sizeof(char) * colunm);    //malloc de colunas
//
   //     retorno[linha][colunm] = s[linha];
   //     comprimento--;
//
   //     if((linha + 1) == numRows){
   //         colunm++;
   //         break;
   //     }
   // }