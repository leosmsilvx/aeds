#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct product {
  int code;
  char name[50];
  float price;
  int qtdeEstoque;   
  struct product *next;
};

bool find_cheapest_product(struct product *head, struct product **product) {
  if (head == NULL) {
    return false;
  }

  struct product *min_product = head;
  float min_price = head->price;

  struct product *ptr = head;
  while (ptr != NULL) {
    if (ptr->price < min_price) {
      min_product = ptr;
      min_price = ptr->price;
    }

    ptr = ptr->next;
  }

  *product = min_product;
  return true;
}

int main() {
  struct product products[] = {
      {1, "Caderno", 10.00, 10},
      {2, "Lápis", 2.00, 20},
      {3, "Borracha", 1.50, 30},
      {4, "Caneta", 5.00, 40},
      {5, "Livro", 30.00, 50},
  };

  struct product *cheapest_product;
  bool success = find_cheapest_product(products, &cheapest_product);

  if (success) {
    printf("O produto de menor preço e: %s, com preço de R$ %.2f\n",
           cheapest_product->name, cheapest_product->price);
  } else {
    printf("Nao foi possivel encontrar o produto de menor preco\n");
  }

  return 0;
}
