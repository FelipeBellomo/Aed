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
            *((int *)pBuffer + 1) += 1;//contador da qtd de pessoas
            add(&pBuffer);
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
    void* tempBuffer = realloc(*pBuffer, maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 1) + 1));
    void** qtdPeople = *((int *)(*pBuffer) + 1);

    if (!tempBuffer) {
        printf("Erro segmentação\n");
        exit(1);
    }

    *pBuffer = tempBuffer;// aqui realoco conforme for add pessoas, sempre multiplicando pelo byte de qtd de pessoas

    printf("Digite o nome:\n");
    scanf("%49s",(char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*qtdPeople));  //calcula o tamanho de bytes necessarios para pular e escrever corretamente, multiplicando o tamanho padrao de cada pessoa, pela qtd

    printf("Digite a idade:\n");
    scanf("%d",(int *)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 1)) + (sizeof(char) * 50))); // aqui escreve no campo reservado para a idade, pulando a alocação do nome 

    printf("Digite o email:\n");
    scanf("%49s", (char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 1)) + (sizeof(char) * 50) + sizeof(int));// aqui escreve no campo reservado para o email, pulando a alocação da idade 
}

void removed(void **pBuffer) {
    printf("ok\n");
}

void search(void **pBuffer) {

    *((int*)(*pBuffer) + 2) = 1; // prevenção para garantir o controle de laço como 1
    char* str = (char*)((char *)*pBuffer +  sizeof(int) * 3);// copio para o ponteiro str o endereco do byte de pesquisa , afim de facilitar a visualização

    printf("Digite o email para buscar:\n");
    scanf("%49s", str); //  atribuo a string no bloco de pesquisa 

    while(*((int *)(*pBuffer)+ 2) <= *((int *)(*pBuffer) + 1)){  // laço padrão comparando qtd de pessoas com o contador de laço
        if(strcmp((char*)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50 + sizeof(int)), (char*)str) == 0){// aqui comparo o espaço cada espaço de memória que contenha email com a referencia atribuida acima
            printf("Achei\n");
            break;
            }
                  
        *((int *)(*pBuffer)+ 2) += 1; //incremetento para continuar o laço

    }   

    ((char *)(*pBuffer))[sizeof(int) * 3] = '\0'; //byte para armazenar nome para dar search
    

    printf("Email nao cadastrado\n");
}

void list(void **pBuffer){

    *((int *)(*pBuffer)+ 2) = 1; //  defino o byte de controle de laço como 0

    while(*((int *)(*pBuffer)+ 2) <= *((int *)(*pBuffer) + 1)){     //laço comparando o byte 1 com o 2, para printar em ordem
        
        printf("Nome: %s\n", (char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)));
        printf("Idade: %d\n",  *((int *)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50)));
        printf("Email: %s\n", (char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50 + sizeof(int));
        
        *((int *)(*pBuffer)+ 2) += 1;// contador do laço

    }

    
    printf("ok\n");
}

/*
(char*)(*pBuffer) -> casting para char para poder andar byte a byte em todo acesso da memória


maloc_inicio -> contem os 4 bytes de controle, menu, qtd pessoas, controle de laço e nome para pesquisa

(*((int*)(*pBuffer)+2)) -> byte de controle qtd de pessoas

tam_pessoas * (*((int*)(*pBuffer)+2)) -> multiplica o tamanha em bytes de cada pessoa, pela quantidade de pessoas cadastradas
                                        essa qtd se encontra no terceiro byte de todo bloco, por isso (*((int*)(*pBuffer)+2))

*((int *)((char *)(*pBuffer) + maloc_inicio + tam_pessoas * (*((int *)(*pBuffer) + 2)) + 50)) -> essa linha contem *((int*)(char*)(*pBuffer))
                                                                                                                    para fazer o casting de int em cima do de char,
                                                                                                                    e o * por fora referencia o valor numerico dessa
                                                                                                                    parte da memoria
                                                                                                            

*/