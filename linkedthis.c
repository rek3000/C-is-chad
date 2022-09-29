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
// ADD AN ITEM TO THE START OF LIST
void pushStart(node_t ** head, int val)
{
  node_t * new_node;
  new_node = (node_t *) malloc(sizeof(node_t));

  new_node->val = val;
  new_node->next = *head;
  *head = new_node;
}
// ADD AN ITEM TO THE END OF LIST
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
// REMOVE THE FIRST ITEM IN LIST
int popStart(node_t ** head)
{
  int retval = -1;
  node_t * next_node = NULL;

  if (*head == NULL) 
  {
    return -1; 
  }

  next_node = (*head)->next;
  retval = (*head)->val;
  free(*head);
  *head = next_node;

  return retval;
}
// REMOVE THE LAST ITEM IN LIST
int popEnd(node_t * head)
{
  int retval = 0;

  if (head->next == NULL) 
  {
    retval = head->val; 
    free(head);
    return retval;
  }

  node_t * current = head;
  while (current->next->next != NULL)
    {
      current = current->next; 
    }

  retval = current->next->val;
  free(current->next);
  current->next = NULL;
  return retval;
}

int removeByIndex(node_t ** head, int n) {
  int i = 0;
  int retval = -1;
  node_t * current = *head;
  node_t * temp_node = NULL;

  if (n == 0) {
    return popStart(head);
  }

  for (i = 0; i < n-1; i++) {
    if (current->next == NULL) {
      return -1;
    }
    current = current->next;
  }

  if (current->next == NULL) {
    return -1;
  }

  temp_node = current->next;
  retval = temp_node->val;
  current->next = temp_node->next;
  free(temp_node);

  return retval;
}

int main (int argc, char *argv[])
{
  node_t * head = NULL; 
  head = (node_t *) malloc(sizeof(node_t));
  head->val = 0;

  pushEnd(head, 1);
  pushEnd(head, 2);
  pushEnd(head, 3);
  pushStart(&head, 22);
  print_list(head);
  printf("\n");

  popStart(&head);
  popEnd(head);
  print_list(head);

  removeByIndex(&head, 2);
  print_list(head);
  head->next = NULL;
  if (head == NULL) {
    free(head);
    return 0;
  }
  free(head);
}
