#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void printArray(int *array, int sizeArray){
    printf("[");
    for(int i = 0; i < sizeArray; i++){
        printf("%d", array[i]);
        if(i != sizeArray-1){
            printf(",");
        }
    }
    printf("]\n");
}

int* productExceptSelf(int *nums, int numsSize, int *returnSize){
    *returnSize = numsSize;
    int *numerosMultiplicados = (int *) malloc(numsSize*sizeof(int)); 
    for(int i = 0; i < numsSize; i++){
        int multiplicacao = 1;
        for(int j = 0; j < numsSize; j++){
            if(j != i){
                multiplicacao *= nums[j];
            } 
        }
        numerosMultiplicados[i] = multiplicacao;
    }
    return numerosMultiplicados;
}

int main(){
    int nums[5] = {-1,1,0,-3,3};
    int returnSize;
    productExceptSelf(nums, 5, &returnSize);
    return 0;
}