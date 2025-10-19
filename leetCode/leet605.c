#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n);

int main() {
    int flowerbed[] = {1};
    int flowerbedSize = 1;
    int n = 0;

    bool report = canPlaceFlowers(flowerbed, flowerbedSize , n);

    for (int i = 0; i < 5; i++)
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
        return true;

    
    if(flowerbedSize == 1){
        if(flowerbed[0] == 0)
            return true;
        else return false;
    }



    for(int i = 0; i < flowerbedSize; i++){
        
        if(flowerbed[i] == 1){
            continue;
        }else{
            if(i == 0){
                if(flowerbedSize == 1 || flowerbed[i + 1] == 0){
                    flowerbed[i] = 1;               
                    n--;
                }
            }else if(i == flowerbedSize - 1){
                if(flowerbed[i - 1] == 0){
                    flowerbed[i] = 1;
                    n--;
                }
            }else if(flowerbed[i + 1] == 0 && flowerbed[i - 1] != 1){
                flowerbed[i] = 1;
                n--;
            }
        }

        if(n == 0)
            return true;
    }
    return false;
}
