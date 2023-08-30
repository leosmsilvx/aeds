#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char * inverteString(char *s){
    int tamanhoString = strlen(s) - 1;
    int inicio, final;
    char * textoInvertido = s;
    
    for (inicio = 0, final = tamanhoString; inicio < final; inicio++, final--) {
        char temp = textoInvertido[inicio];
        textoInvertido[inicio] = textoInvertido[final];
        textoInvertido[final] = temp;
    }

    return textoInvertido;
}

bool logicaEspaco(char *string, int i){
    char espaco = ' ';
    if(i == 0)
        return false;

    if(string[i] != espaco)
        return false;
    
    if(string[i - 1] == espaco)
        return false;

    return true;
}

char * reverseWords(char * s){
    char * textoInvertido = inverteString(s);    
    int tamanhotextoInvertido = strlen(textoInvertido) + 1;
    char espaco = ' ';

    char * palavrasInvertidas = (char *) malloc(tamanhotextoInvertido);
    palavrasInvertidas[0] = '\0';

    char temp[100] = "";
    for(int i = 0; i < tamanhotextoInvertido; i++){
        if(textoInvertido[i] == espaco || textoInvertido[i] == '\0'){
            strcat(palavrasInvertidas, inverteString(temp));    
            if(logicaEspaco(textoInvertido, i)){
                strcat(palavrasInvertidas, " ");
            }
            temp[0] = '\0';
        } else {
            strncat(temp, &textoInvertido[i], 1);
        }
    }

    char indexUltimoChar = strlen(palavrasInvertidas) - 1;
    if(palavrasInvertidas[indexUltimoChar] == ' '){
        palavrasInvertidas[indexUltimoChar] = '\0';
    }

    return palavrasInvertidas;
}


int main(){
    char s[20];
    strcpy(s, "a good   example");
    printf("-%s-", reverseWords(s));
    return 0;
}