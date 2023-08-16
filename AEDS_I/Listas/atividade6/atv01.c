#include <stdio.h>
#include <string.h>

#define MAX 100

int main() {
    char str1[MAX], str2[MAX], concat[MAX*2];
    int len1, len2;

    printf("Digite a primeira string: ");
    scanf("%s", str1);

    printf("Digite a segunda string: ");
    scanf("%s", str2);

    len1 = strlen(str1);
    len2 = strlen(str2);

    if (strcmp(str1, str2) == 0) {
        printf("Strings iguais\n");
    } else {
        if (len1 > len2) {
            printf("A primeira string e maior\n");
        } else {
            printf("A segunda string e maior\n");
        }

        strcpy(concat, str1);
        strcat(concat, str2);

        printf("Concatenacao das strings: %s\n", concat);
    }

    return 0;
}
