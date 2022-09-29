#include <stdio.h>
#include <stdlib.h>

typedef struct node
  {
    int val;
    struct node * next;
  } node_t;

void printlist(node_t * head)
{
  node_t * current = head;

  while (current != NULL)
    {
      printf("%d - ", current->val);
      current = current->next;
    }
  printf("\n");
}

node_t * createNode(int value)
{
  node_t * result = malloc(sizeof(node_t));
  result->val = value;
  result->next = NULL;
  return result;
}

node_t * insert_at_head(node_t **head, node_t *node_to_insert)
{
  node_to_insert->next = *head;
  *head = node_to_insert;
  return node_to_insert;
}

int main (int argc, char *argv[])
{
  node_t * head = NULL;
  node_t * temp;

  for (int i = 0; i < 10; i++) {
    temp = createNode(i);
    insert_at_head(&head,temp);
  }

  printlist(head);
  return 0;
}
