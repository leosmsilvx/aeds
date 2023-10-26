#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct node {
  int data;
  struct node *next;
};

bool find_max_element(struct node *head, int *position, int *value) {
  if (head == NULL) {
    return false;
  }

  struct node *ptr = head;
  int max_value = ptr->data;
  int max_position = 0;

  while (ptr != NULL) {
    if (ptr->data > max_value) {
      max_value = ptr->data;
      max_position = ptr - head;
    }

    ptr = ptr->next;
  }

  *position = max_position;
  *value = max_value;

  return true;
}

int main() {
  struct node *head = malloc(sizeof(struct node));
  head->data = 1;
  head->next = malloc(sizeof(struct node));
  head->next->data = 2;
  head->next->next = malloc(sizeof(struct node));
  head->next->next->data = 3;
  head->next->next->next = NULL;

  int position, value;
  bool success = find_max_element(head, &position, &value);

  if (success) {
    printf("O maior elemento da lista esta na posicao %d e tem o valor %d\n",
           position, value);
  } else {
    printf("Nao foi possivel encontrar o maior elemento da lista\n");
  }

  return 0;
}
