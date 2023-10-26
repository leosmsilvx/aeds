#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct node {
  int data;
  struct node *next;
};

bool remove_n_first_elements(struct node **head, int n) {
  if (n > list_length(*head)) {
    return false;
  }

  struct node *ptr = *head;
  while (n > 0) {
    ptr = ptr->next;
    n--;
  }

  *head = ptr;
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

  bool success = remove_n_first_elements(&head, 2);

  if (success) {
    printf("Os primeiros dois elementos foram removidos\n");
  } else {
    printf("Nao foi possivel remover os elementos\n");
  }

  while (head != NULL) {
    printf("%d\n", head->data);
    head = head->next;
  }

  return 0;
}
