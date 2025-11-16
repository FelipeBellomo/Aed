#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define maloc_inicio (sizeof(size_t)*2 + sizeof(int) + sizeof(char) * 50 + sizeof(char) * 50 + sizeof(int))

void ADD(void** pBuffer);
void DEL(void** pBuffer);
void LIST(void** pBuffer);
void SEARCH(void** pBuffer);

int main() {
        
    void *pBuffer = NULL; 
    pBuffer = malloc(maloc_inicio);

    if (!pBuffer)
        printf("Erro segmentação\n");

    *(size_t*)pBuffer = maloc_inicio;                               // total
    *((size_t*)((char*)pBuffer + sizeof(size_t))) = 0;              // controlador de tamanho para os laços
    *((int*)((char*)pBuffer + sizeof(size_t)*2)) = 0;               // menu
    *((char*)pBuffer + sizeof(size_t)*2 + sizeof(int)) = '\0';      //byte name temp
    *((char*)pBuffer + sizeof(size_t)*2 + sizeof(int) + 50) = '\0'; //byte email temp
    *((char*)pBuffer + sizeof(size_t)*2 + sizeof(int) + 100) = 0;   // byte da idade

    do {
        printf("-- MENU:\n");
        printf("\t1. Adicionar Pessoa\n");
        printf("\t2. Remover Pessoa\n");
        printf("\t3. Buscar Pessoa\n");
        printf("\t4. Listar Todos\n");
        printf("\t5. Sair\n");
        scanf("%d", ((int*)((char*)pBuffer + sizeof(size_t)*2))); // envia a escolha do menu para seu byte

        switch (*((int*)((char*)pBuffer + sizeof(size_t)*2))) {
        case 1:
            ADD(&pBuffer);
            
            break;
        case 2:
            DEL(&pBuffer);
            break;
        case 3:
            SEARCH(&pBuffer);
            break;
        case 4:
            LIST(&pBuffer);
            break;
        case 5:
            free(pBuffer);
            exit(1);
        }
    } while (1);
    return 0;
}


void ADD(void** pBuffer) {
    void* base = *pBuffer;
    void* temp = (char*)base + sizeof(size_t); 
    char* name = (char*)base + sizeof(size_t)*2 + sizeof(int);
    char* email = name + 50;
    int* idade = (int*)(email + 50);

    printf("Digite o nome:\n");
    scanf("%49s", name);
    while(getchar() != '\n');

    printf("Digite o email:\n");
    scanf("%49s", email);
    while(getchar() != '\n');

    printf("Digite a idade:\n");
    scanf("%d", idade);
    while(getchar() != '\n');

    *(size_t*)temp = (strlen(name) + 1) + (strlen(email) + 1) + sizeof(int); // utilizo o bloco de tamanho temporário para facilitar a conta
    *(size_t*)base += *(size_t*)temp; //somo no bloco de tamanaho total, com o tamanho total do novo usuario

    *pBuffer = realloc(*pBuffer, *(size_t*)base);// Realoca diretamente com base no total atual + novos dados

    if (!*pBuffer) {
        printf("realloc falhou\n");
        exit(1);
    }// teste para falha

    base = *pBuffer;
    temp = (char*)base + sizeof(size_t);
    name = (char*)base + sizeof(size_t)*2 + sizeof(int);
    email = name + 50;
    idade = (int*)(email + 50);

    char* destino = (char*)base + *(size_t*)base - *(size_t*)temp;// Grava nova pessoa diretamente no fim do buffer

    strcpy(destino, name);
    destino += strlen(destino) + 1;// após escrever, aponta para o fim de nome\0

    strcpy(destino, email);
    destino += strlen(destino) + 1;// após escrever, aponta para o fim de email\0

    *((int*)destino) = *idade;// após escrever, aponta para a idade


    printf("\n----------------------------------------------");
    printf("\nNome: %s\nEmail: %s\nIdade: %d\n", name, email, *idade);
    printf("----------------------------------------------\n");


}

void DEL(void** pBuffer){
    void* base = *pBuffer;
    char* emailTemp = (char*)base + sizeof(size_t)*2 + sizeof(int);

    printf("Digite o email para remover:\n");
    scanf("%49s", emailTemp);

    char* p = (char*)*pBuffer + maloc_inicio; // aponto para o inicio da lista de usuarios

    
    while ((size_t)(p - (char*)*pBuffer) < *(size_t*)*pBuffer) { 

        char* email = p + strlen(p) + 1; // email do registro atual

        if(strcmp(emailTemp, email) == 0) { // procura usuário 
            
            char* next = email + strlen(email) + 1 + sizeof(int);// calcula início do próximo registro

            
            memmove(p, next, *(size_t*)*pBuffer - (next - (char*)*pBuffer));// desloca todo o restante do buffer sobre o registro deletado

            
            *(size_t*)*pBuffer -= (next - p); // atualiza tamanho total

            *pBuffer = realloc(*pBuffer,*(size_t*)*pBuffer);

            emailTemp[0] = '\0'; // limpa temporário

            
            printf("\n--------------------");
            printf("\nUsuário removido.\n");
            printf("---------------------\n");
            
            return;
        }// laço para comparar os emails, até percorrer a lista toda (p = total)

        
        p += strlen(p) + 1; // pula nome
        p += strlen(p) + 1; // pula email
        p += sizeof(int);    // pula idade
    }// percorre o buffer para encontrar o registro pelo email

    printf("\n---------------------");
    printf("\nUsuário não encontrado.\n");
    printf("---------------------\n");
}

void LIST(void** pBuffer) {
    if (*(size_t*)*pBuffer == maloc_inicio) {
        printf("\n--------------------------");
        printf("\nNenhuma pessoa cadastrada.\n");
        printf("--------------------------\n");
        return;
    }// teste para lista vazia

    printf("\n--- LISTA DE PESSOAS ---\n");

    // ponteiro inicial logo após o cabeçalho fixo
    char* p = (char*)*pBuffer + maloc_inicio;

    // percorre até o total de bytes usados
    while ((size_t)(p - (char*)*pBuffer) < *(size_t*)*pBuffer) {

        printf("Nome: %s\n", p);    // vai para o nome
        p += strlen(p) + 1;         //pula para o email

        printf("Email: %s\n", p);   //imprime o email
        p += strlen(p) + 1;         // pula para a idade

        printf("Idade: %d\n", *((int*)p));// imprime idade
        p += sizeof(int);                 // pula para prox usuário  

        printf("-------------------------\n");
    } //laço para comparar os emails, até percorrer a lista toda (p = total)
}

void SEARCH(void** pBuffer){
    void* base = *pBuffer;
    char* email = (char*)base + sizeof(size_t)*2 + sizeof(int);

    printf("Digite o email para procurar:\n");
    scanf("%49s",email);

    char* p = (char*)*pBuffer + maloc_inicio;   //aponto para o inicio da lista de usuarios

    while ((size_t)(p - (char*)*pBuffer) < *(size_t*)*pBuffer) {

        p += strlen(p) + 1;                 //pula o nome dos usuários

        if(strcmp(email,p) == 0) {     
            printf("\n---------------------");     
            printf("\nUsuário encontrado:\n");
            printf("Email: %s\n", p);
            printf("---------------------\n");

            email = '\0';                   //limpa o email temp
            break;
        }// compara as strings

        p += strlen(p) + 1;                 //pula email 
        p += sizeof(int);                   //pula idade para ir para o prox usuário

    }// laço para comparar os emails, até percorrer a lista toda (p = total)

    if((size_t)(p - (char*)*pBuffer) == *(size_t*)*pBuffer){
        printf("\n-----------------------");
        printf("\nUsuário não encontrado.\n");
        printf("-----------------------\n");

    }

}

/*
memmove - (destino, origem, qtd de bytes)

memmove - (p(inicio do usuario a deletar), next(inicio do usuario que vai para a posição do outro usuario),  *(size_t*)*pBuffer - (next - (char*)*pBuffer) )
                                                                                                                 bytes total - distância até o início de usuário que ira ir para esquerda
                                                                                                                 ou seja, qtd de bytes a mover    
                                                                                                                 
                                                                                                                 a subtração retorna  quantos bytes next esta distante do inicio do buffer

*/