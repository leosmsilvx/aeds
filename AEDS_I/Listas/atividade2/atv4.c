#include <stdio.h>

int main() {
    float x, fx, gx, hx;
    printf("Digite um valor para x: ");
    scanf("%f", &x);

    hx = x * x + 3 * x - 20;
    if (hx <= 5) {
        gx = 5;
    } else {
        gx = hx;
    }

    if (gx > 10) {
        fx = x + 2 * x * x;
    } else {
        fx = 10;
    }

    printf("f(x) = %f\n", fx);

    return 0;
}
