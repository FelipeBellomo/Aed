#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int candy(int* ratings, int ratingsSize);

int main() {
    int ratings[] = {2,2,2};
    int ratingsSize = 3;

    int sugar = candy(ratings, ratingsSize);

    printf("%d", sugar);

    return 0;
}

int candy(int* ratings, int ratingsSize) {
    int candys = 1; 
    int high = 0;
    int neigh = 0;

    for (int i = 0; i < ratingsSize && (i + 1) < ratingsSize; i++){
        if(ratings[i] == ratings[i + 1]){
            candys--;
        }
        candys++;

    }

    if(neigh == (ratingsSize - 1)){
        neigh /= 2;
    }
    
    candys = candys + high - neigh;

    return candys;
    
}