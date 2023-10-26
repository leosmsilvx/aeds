#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct node {
  int data;
  struct node *next;
};

bool swap_elements(struct node **head, int position1, int position2) {
  if (head == NULL || position1 < 0 || position1 >= list_length(*head) ||
      position2 < 0 || position2 >= list_length(*head)) {
    return false;
  }

  struct node *ptr1 = *head;
  for (int i = 0; i < position1; i++) {
    ptr1 = ptr1->next;
  }

  struct node *ptr2 = *head;
  for (int i = 0; i < position2; i++) {
    ptr2 = ptr2->next;
  }

  int temp = ptr1->data;
  ptr1->data = ptr2->data;
  ptr2->data = temp;

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

  bool success = swap_elements(&head, 0, 2);

  if (success) {
    printf("Os elementos foram trocados com sucesso\n");
  } else {
    printf("Nao foi possivel trocar os elementos\n");
  }

  while (head != NULL) {
    printf("%d\n", head->data);
    head = head->next;
  }

  return 0;
}
