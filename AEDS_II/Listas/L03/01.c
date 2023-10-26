#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

struct node {
  int data;
  struct node *next;
};

struct node *concat(struct node *head1, struct node *head2) {
  struct node *new_head = malloc(sizeof(struct node));
  new_head->data = -1;
  new_head->next = head1;

  struct node *ptr = new_head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  ptr->next = head2;

  return new_head;
}

int main() {
  struct node *head1 = malloc(sizeof(struct node));
  head1->data = 1;
  head1->next = malloc(sizeof(struct node));
  head1->next->data = 2;
  head1->next->next = NULL;

  struct node *head2 = malloc(sizeof(struct node));
  head2->data = 3;
  head2->next = malloc(sizeof(struct node));
  head2->next->data = 4;
  head2->next->next = NULL;

  struct node *head3 = concat(head1, head2);

  while (head3 != NULL) {
    printf("%d\n", head3->data);
    head3 = head3->next;
  }

  return 0;
}