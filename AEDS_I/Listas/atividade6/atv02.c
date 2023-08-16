#include <stdio.h>
#include <string.h>

int countChar(char *str, char c) {
    int count = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}

int main() {
    char str[100], c;
    printf("Digite uma string: ");
    scanf("%s", str);
    printf("Digite um caractere: ");
    scanf(" %c", &c);
    int num = countChar(str, c);
    printf("O caractere '%c' aparece %d vezes na string '%s'\n", c, num, str);
    return 0;
}
