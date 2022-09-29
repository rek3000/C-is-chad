#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int val;
  struct node * next;
} node_t;

void print_list(node_t * head)
{
  node_t * current = head;
  while (current != NULL) {
    printf("%d\n", current->val); 
    current = current->next;
  }
}

void pushStart(node_t ** head, int val)
{
  node_t * new_node;
  new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}

void pushEnd(node_t * head, int val)
{
  node_t * current = head;
  while (current->next != NULL) {
    current = current->next; 
  }

  current->next = (node_t *) malloc(sizeof(node_t));
  current->next->val = val;
  current->next->next = NULL;

}

int main (int argc, char *argv[])
{
  node_t * head = NULL; 
  head = (node_t *) malloc(sizeof(node_t));

  /* head->val = 1;
  head->next = (node_t *) malloc(sizeof(node_t));
  head->next->val = 2;
  head->next->next = NULL; */
  pushEnd(head, 1);
  pushEnd(head, 2);
  pushEnd(head, 3);

  print_list(head);
  if (head == NULL) {
    return 0; 
  }

  return 0;
}
