// Carlos Felipe Pereira Bellomo - M2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main() {
    int flowerbed[] = {1,0,0,0,1,0,0};
    int flowerbedSize = 7;
    int n = 2;

    bool report = canPlaceFlowers(flowerbed, flowerbedSize , n);

    for (int i = 0; i < 7; i++)
    {
        printf("%d",flowerbed[i]);
    }

    if(report)
        printf("Plantou");
    else printf("Nao plantou");
    


    return 0;
}

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){

    if(n < 1)
        return true; // caso tenha um caso nem plantar

    
    if(flowerbedSize == 1){
        if(flowerbed[0] == 0)
            return true;
        else return false;
    }// caso tenha um vetor com apenas uma posição, testo  o 0 ou 1



    for(int i = 0; i < flowerbedSize; i++){
        
        if(flowerbed[i] == 1){
            continue;// ignoro as posições com valor 1
        }else{
            if(i == 0){
                if(flowerbedSize == 1 || flowerbed[i + 1] == 0){
                    flowerbed[i] = 1;               
                    n--;
                }// para o caso da primeira posição
            }else if(i == flowerbedSize - 1){
                if(flowerbed[i - 1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }// aqui a situação da ultima posição
            }else if(flowerbed[i + 1] == 0 && flowerbed[i - 1] != 1){
                flowerbed[i] = 1;
                n--;
            }// aqui testo para as posições do meio, sem as extremidades
        }

        if(n == 0)
            return true;
    }
    return false;
}