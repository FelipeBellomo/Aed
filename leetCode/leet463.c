#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize);


int main() {
    int gridSize = 4;
    int* gridColSize = (int*)malloc(sizeof(int) * gridSize);
    int** grid = (int**)malloc(sizeof(int*) * gridSize);

    for (int i = 0; i < gridSize; i++) {
        gridColSize[i] = 4;
        grid[i] = (int*)malloc(sizeof(int) * gridColSize[i]);
    }

    
    int valores[4][4] = {
        {0,1,0,0},
        {1,1,1,0},
        {0,1,0,0},
        {1,1,0,0}
    };

    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            grid[i][j] = valores[i][j];
        }
    }

    int perimetro = islandPerimeter(grid, gridSize, gridColSize);

    printf("%d\n", perimetro);
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int i = 0, j = 0;
    int cube = 0, perimeter = 0,sub = 0;

    for (i = 0; i < gridSize; i++){
        for (j = 0; j < *gridColSize; j++){
            if(grid[i][j] == 1)
                cube++;
        }

    }
    
    perimeter = cube * 4;

    //Verificar cubo vizinho ao lado
    for (i = 0; i < gridSize; i++){
        for (j = 0; j < *gridColSize && (j + 1) < *gridColSize; j++){
                if(grid[i][j] == 1 && grid[i][j + 1] == 1)
                    sub = sub + 2;
             
        }
    }   

    //Verificar cubo vizinho embaixo
    for (i = 0; i < gridSize && (i + 1) < gridSize; i++){
        for (int k = 0; k < *gridColSize; k++){
            if(grid[i][k] == 1 && grid[i + 1][k] == 1)
                sub = sub + 2;
        }   
    }
    
    if(sub > 0)
        perimeter = perimeter - sub;

    return perimeter;
    

}