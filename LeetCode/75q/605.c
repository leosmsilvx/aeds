#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool canPlaceFlowers(int* flowerbed, int flowerbedSize, int n){
    int cont = 0;
    for(int i = 0; i < flowerbedSize; i++){
        bool prevOccupied;
        bool nextOccupied;
        if(i == 0)
            prevOccupied = false;
        else 
            prevOccupied = flowerbed[i - 1] == 1;

        if(i == flowerbedSize - 1)
            nextOccupied = false;
        else
            nextOccupied = (i == flowerbedSize - 1) || flowerbed[i + 1] == 1;

        if(flowerbed[i] == 0 && !prevOccupied && !nextOccupied){
            flowerbed[i] = 1;
            cont++;
        }
    }
    printf("%s", cont >= n ? "true" : "false");
    return cont >= n;
}

int main(){
    int flowerbed[5] = {0, 0, 0, 0, 0};
    int toPlant = 3;
    canPlaceFlowers(flowerbed, 5, toPlant);
    return 0;
}