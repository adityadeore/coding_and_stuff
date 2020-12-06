#include<stdlib.h>
#include<string.h>
#include<stdio.h>

/*
  Definition for singly-linked list.*/
struct ListNode 
{
  int val;
  struct ListNode *next;
};
 
struct Queue
{
  int size;
  struct ListNode *head;
  struct ListNode *tail;
};

void queue_enqueue(struct Queue *queue, void *elem)
{
  struct ListNode *node = NULL;
  node = malloc(sizeof(struct ListNode));

  node->elem = elem;
  if (queue->size == 0)
  {
    node->next = NULL;
    queue->head = node;
    queue->tail = node;
    queue->size++;
  }
  else
  {
    node->next = NULL;
    queue->tail->next = node;
    queue->tail = node;
    queue->size++;
  }

  return;
}

int queue_size(struct Queue *queue)
{
  return queue->size;
}

void printqueue(struct Queue *queue)
{
  int size;
  int i = 0;
  if (size == 0)
  {
    return;
  }
  size = queue->size;
  printf("Size is %d\n", size);
  struct ListNode *printnode;
  printnode = queue->head;

  for (i=0; i <size; i++)
  {
    printf("Elem = %d\n", (int)printnode->elem);
    printnode = printnode->next;
  }
}


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
  struct Queue *queue = NULL;

  queue = (struct Queue *)malloc(sizeof(struct Queue));
  /* check all nulls */
  if (l1 == NULL && l2 == NULL)
  {
    return NULL;
  }

  if (l1 != NULL && l2 == NULL)
  {
    return l1;
  }

  if (l1 == NULL && l2 != NULL)
  {
    return l2;
  }

  struct ListNode *l1current = NULL;
  struct ListNode *l2current = NULL;

  l1current = l1;
  l2current = l2;
  /*iterate until we reach end of shorter list */
  while (l1current != NULL && l2current != NULL)
  {
    if (l1current->val <= l2current->val)
    {
      queue_enqueue(queue, l1current->val);
      l1current = l1current->next;
    }
    else
    {
      queue_enqueue(queue, l2current->val);
      l2current = l2current->next;
    }
  }

  if (l1current == NULL && l2current == NULL)
  {
    return queue->head;
  }
  /* we get here and only 1 list has ended then we need to iterate throgh the rest of the list
     and add it to the end */
  if (l1current != NULL && l2current == NULL)
  {
    while (l1current != NULL)
    {
      queue_enqueue(queue, l1current->val);
      l1current = l1current->next;
    }
    return (queue->head);
  }
  else
  {
    while (l2current != NULL)
    {
      queue_enqueue(queue, l2current->val);
      l2current = l2current->next;
    }
    return (queue->head);

  }

}

void main()
{
  struct ListNode *finallist;
  struct ListNode *l1;
  struct ListNode *l2;

  finallist = mergeTwoLists();
}
