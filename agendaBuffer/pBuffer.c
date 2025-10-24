#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_pessoas (50 * sizeof(char) + sizeof(int) + 50 * sizeof(char))
//#define set (tam_pessoas * (*((int*)pBuffer + 1)))

void add(void** pBuffer);
void remove(void** pBuffer);
void search(void** pBuffer);
void list(void** pBuffer);

int main() {
    void* pBuffer = NULL;

    pBuffer = (int*)malloc(sizeof(int) * 2);

    do
    { 
        printf("-- MENU:\n");
        printf("\t 1. Adicionar Pessoa\n");
        printf("\t 2. Remover Pessoa\n");
        printf("\t 3. Buscar Pessoa\n");
        printf("\t 4. Listar Todos\n");	
        printf("\t 5. Sair\n");	
        scanf("%d",(int*)pBuffer);

        switch (*(int*)pBuffer)
        {
        case 1:
            add(pBuffer);
            *((int*)pBuffer + 1) += 1;
            break;
        case 2:
            remove(pBuffer);
            break;
        
        case 3:
            search(pBuffer);
            break;

        case 4:
            list(pBuffer);
            break;

         case 5:
            exit(0);       
        }
    } while (1);
    

    return 0;
}

void add(void** pBuffer){
    pBuffer = (void*)realloc(pBuffer, tam_pessoas * (*((int*)pBuffer + 1)));

    printf("Digite o nome:\n");
    scanf("%s", (char*)pBuffer + tam_pessoas * (*((int*)pBuffer + 1)));

    printf("Digite a idade:\n");
    scanf("%d",(int*)pBuffer + tam_pessoas * (*((int*)pBuffer + 1)) + (sizeof(char) * 50));

    printf("Digite o email:\n");
    scanf("%s", (char*)pBuffer + tam_pessoas * (*((int*)pBuffer + 1)) + (sizeof(char) * 50) + sizeof(int));

}

void remove(void** pBuffer){
    printf("ok");
}
void search(void** pBuffer){
    printf("ok");
}
void list(void** pBuffer){
    printf("ok");
}


