#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * mergeAlternately(char * word1, char * word2){
    int nw1, nw2;
    for(nw1 = 0; word1[nw1] != '\0'; nw1++);
    for(nw2 = 0; word2[nw2] != '\0'; nw2++);

    char * merged = (char *) malloc((nw1 + nw2 + 1) * sizeof(char));
    if(merged == NULL)
        return NULL;

    for(int i = 0, j = 0; i < nw1 + nw2; i++, j++){  
        if(i < nw1){
            merged[j] = word1[i];
        } else {
            j--;
        }

        if(i < nw2){
            j++;        
            merged[j] = word2[i];
        } 
        printf("-----------\n");

        if(j+1 == nw1 + nw2){
            merged[j+1] = '\0';
            break;
        }
        
    } 
    printf("%s", merged);
    return merged;
}

int main(){
    char w1[10], w2[10];
    strcpy(w1, "ab");
    strcpy(w2, "pq");
    mergeAlternately(w1, w2);

    return 0;
}