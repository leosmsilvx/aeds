#include <stdio.h>
#include <string.h>

#define MAX_STR_SIZE 100

int main() {
    char str[4][MAX_STR_SIZE], aux[MAX_STR_SIZE];
    int i, j;

    for (i = 0; i < 4; i++) {
        printf("Digite a %da string: ", i+1);
        fgets(str[i], MAX_STR_SIZE, stdin);
        str[i][strlen(str[i])-1] = '\0';
    }

    for (i = 0; i < 4; i++) {
        for (j = i+1; j < 4; j++) {
            if (strcmp(str[i], str[j]) > 0) {
                strcpy(aux, str[i]);
                strcpy(str[i], str[j]);
                strcpy(str[j], aux);
            }
        }
    }

    printf("As strings em ordem crescente sao:\n");
    for (i = 0; i < 4; i++) {
        printf("%s\n", str[i]);
    }

    return 0;
}
