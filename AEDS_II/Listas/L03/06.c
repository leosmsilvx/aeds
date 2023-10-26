#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

int count_even_numbers(int *list, int length) {
  if (list == NULL || length <= 0) {
    return 0;
  }

  int count = 0;
  for (int i = 0; i < length; i++) {
    if (list[i] % 2 == 0) {
      count++;
    }
  }

  return count;
}

int main() {
  int list[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int length = sizeof(list) / sizeof(list[0]);

  int count = count_even_numbers(list, length);

  printf("Pares na lista e %d\n", count);

  return 0;
}
