#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void swap(char *s, int li, int ri){
    char auxiliary = s[li];
    s[li] = s[ri];
    s[ri] = auxiliary;
}

bool isVowel(char c){
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for(int i = 0; i < 10; i++){
        if(c == vowels[i]){
            return true;
        }
    }
    return false;
}

char * reverseVowels(char * s){
    int li, ri = strlen(s) - 1;
    for(li = 0; li < ri; li++, ri--){
        if(!isVowel(s[li])){
            ri++;
            continue;
        }
        if(!isVowel(s[ri])){
            li--;
            continue;
        }
        swap(s, li, ri);
    }
    printf("%s", s);
    return s;
}

int main(){
    char s[20];
    strcpy(s, "leetcode");
    reverseVowels(s);
    return 0;
}