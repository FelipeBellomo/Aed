#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define tam_pessoas (50 * sizeof(char) + sizeof(int) + 50 * sizeof(char))
#define maloc_inicio (sizeof(int) * 3 + sizeof(char) * 50)

//pBuffer 0 = menu
//pBuffer 1 = qtd pessoas
//pBuffer 2 = controle de laço

void add(void **pBuffer);
void removed(void **pBuffer);
void search(void **pBuffer);
void list(void **pBuffer);

int main() {
    void *pBuffer = NULL; // byte do menu

    pBuffer = malloc(maloc_inicio);
    if (!pBuffer)
        printf("Erro segmentação\n");

    *((int *)pBuffer + 1) = 0;  // byte qtd pessoas
    *((int *)pBuffer + 2) = 0;  // byte controlador de laços
    ((char *)pBuffer)[sizeof(int) * 3] = '\0'; //byte para armazenar nome para dar search

    do {
        printf("-- MENU:\n");
        printf("\t1. Adicionar Pessoa\n");
        printf("\t2. Remover Pessoa\n");
        printf("\t3. Buscar Pessoa\n");
        printf("\t4. Listar Todos\n");
        printf("\t5. Sair\n");
        scanf("%d", (int *)pBuffer);

        switch (*(int *)pBuffer) {
        case 1:
            add(&pBuffer);
            *((int *)pBuffer + 1) += 1;
            break;
        case 2:
            removed(&pBuffer);
            break;
        case 3:
            search(&pBuffer);
            break;
        case 4:
            list(&pBuffer);
            break;
        case 5:
            free(pBuffer);
            exit(1);
        }
    } while (1);

    return 0;
}

void add(void **pBuffer) {
    *pBuffer = realloc(*pBuffer, maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 1)));

    if (!*pBuffer) {
        printf("Erro segmentação\n");
        exit(1);
    }

    printf("Digite o nome:\n");
    scanf("%49s",(char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 1)));  //calcula o tamanho de bytes necessarios para pular e escrever corretamente, multiplicando o tamanho padrao de cada pessoa, pela qtd

    printf("Digite a idade:\n");
    scanf("%d",(int *)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 1)) + (sizeof(char) * 50))); // aqui escreve no campo reservado para a idade, pulando a alocação do nome 

    printf("Digite o email:\n");
    scanf("%49s", (char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 1)) + (sizeof(char) * 50) + sizeof(int));// aqui escreve no campo reservado para o email, pulando a alocação da idade 
}

void removed(void **pBuffer) {
    printf("ok\n");
}

void search(void **pBuffer) {

    *((int*)(*pBuffer) + 2) = 0;

    printf("Digite o email para buscar:\n");
    scanf("%49s",((char *)(*pBuffer) + 3));

    void* str = strcpy(str, ((char *)(*pBuffer) + 3));

        while(*((int *)(*pBuffer)+ 2) < (*((int *)(*pBuffer) + 1))){ 
            if(strcmp((char*)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50 + sizeof(int)), (char*)str == 0))
                printf("Achei\n");

        
            *((int *)(*pBuffer)+ 2) += 1;
        }   

    ((char *)(*pBuffer))[sizeof(int) * 3] = '\0'; //byte para armazenar nome para dar search
    *((int*)(*pBuffer) + 2) = 0;

    printf("ok\n");
}
void list(void **pBuffer){

    *((int *)(*pBuffer)+ 2) = 0; //  defino o byte de controle de laço como 1, para efeito de multiplicação

    while(*((int *)(*pBuffer)+ 2) < *((int *)(*pBuffer) + 1)){     //laço comparando o byte 1 com o 2, para printar em ordem

        printf("Nome: %s\nIdade: %d\nEmail: %s\n\n",
            (char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)),    // mesma logica de implementação do scanf, porem para printar
            *((int *)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50)),
            (char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50 + sizeof(int));
        
        *((int *)(*pBuffer)+ 2) += 1;
    }

    *((int *)(*pBuffer)+ 2) = 0;
    printf("ok\n");
}

/*
(char*)(*pBuffer) -> casting para char para poder andar byte a byte em todo acesso da memória

sizeof(int) * 3 -> bytes de controle no inicio do bloco

maloc_inicio -> outro byte de controle, porem para nome de pesquisa

(*((int*)(*pBuffer)+2)) -> byte de controle qtd de pessoas

tam_pessoas * (*((int*)(*pBuffer)+2)) -> multiplica o tamanha em bytes de cada pessoa, pela quantidade de pessoas cadastradas
                                        essa qtd se encontra no terceiro byte de todo bloco, por isso (*((int*)(*pBuffer)+2))

*((int *)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50)) -> essa linha contem *((int*)(char*)(*pBuffer))
                                                                                                                    para fazer o casting de int em cima do de char,
                                                                                                                    e o * por fora referencia o valor numerico dessa
                                                                                                                    parte da memoria
                                                                                                            

*/