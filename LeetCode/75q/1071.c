#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * gcdOfStrings(char * str1, char * str2){
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int a = len1, b = len2;
    while (a != b){
        if(a > b){
            a -= b;
        } else {
            b -= a;
        }
    }

    if(len1 < len2 && strncmp(str1, str2 + (len2 - len1), len1) != 0)
        return "";
    if(len1 > len2 && strncmp(str1 + (len1 - len2), str2, len1) != 0)
        return "";
    if(strncmp(str1, str2, a) != 0)
        return "";

    int sum = a;
    while(len1 > sum + b){
        sum += b;
        if(strncmp(str1+sum, str2, b) != 0)
            return "";
    } 

    sum = b;
    while(len2 > sum + a){
        sum += a;
        if(strncmp(str1, str2+sum, a) != 0)
            return "";
    }
    str1[a] = '\0';
    printf("%s", str1);
    return str1;
}

int main(){
    char w1[10], w2[10];
    strcpy(w1, "EFGABC");
    strcpy(w2, "ABC");
    gcdOfStrings(w1, w2);

    return 0;
}