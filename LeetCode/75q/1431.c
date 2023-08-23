#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isBiggerThanAny(int num, int* numbers, int numbersSize){
    bool isBigger = true;
    for(int i = 0; i < numbersSize; i++){
        if(num < numbers[i])
            isBigger = false;
    }
    return isBigger;
}

bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize){
    *returnSize = candiesSize;
    bool * result = (bool *) malloc(candiesSize * sizeof(bool));
    printf("[");
    for(int i = 0; i < candiesSize; i++){
        result[i] = isBiggerThanAny(candies[i] + extraCandies, candies, candiesSize);
        printf("%s", result[i] ? "true" : "false");
        if(i < candiesSize - 1){
            printf(",");
        }
    }
    printf("]");

    return result;
}


int main(){
    int candies[5] = {2,3,5,1,3};
    int extraCandies = 3;
    int returnSize = 5;
    kidsWithCandies(candies, 5, 3, &returnSize);
    return 0;
}