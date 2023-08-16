#include <stdio.h>

int main() {
    int usuario, senha;

    printf("Digite o numero do usuario: ");
    scanf("%d", &usuario);

    printf("Digite a senha do usuario: ");
    scanf("%d", &senha);

    if ((usuario == 675483 && senha == 67453) || (usuario == 145627 && senha == 89234) || (usuario == 98782 && senha == 89132)) {
        printf("Usuario e senha validos\n");
    } else {
        printf("Usuario invalido\n");
    }

    return 0;
}
