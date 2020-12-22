//#include "common.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode1
{
  int num;
  struct ListNode1 *next;
  struct ListNode1 *prev;
};

struct Queue
{
  int size;
  struct ListNode1 *head;
  struct ListNode1 *tail;

};

void queue_enqueue(struct Queue *queue, int num)
{
  /* first elem */
  struct ListNode1 *node;
  //printf("here %d", num);
  node = malloc(sizeof(struct ListNode1));
  node->num = num;
  if (queue->size == 0)
  {
    node->next = queue->tail;
    node->prev = queue->head;
    queue->head->next = node;
    queue->tail->prev = node;
    queue->size++;
  }
  else
  {
    struct ListNode1 *current = queue->head->next;
    /* iterate through the list to put this in sorted way */
    while (current != queue->tail)
    {
      if (current->num >= node->num)
      {
        if (current->num == node->num)
        {
          return;
        }
        node->next = current;
        node->prev = current->prev;
        current->prev->next = node;
        current->prev = node;
        break;
      }
      current = current->next;
    }
    /*reached end without finding a place */
    if (current == queue->tail)
    {
      node->next = queue->tail;
      node->prev = queue->tail->prev;
      queue->tail->prev->next = node;
      queue->tail->prev = node;
    }
    queue->size++;
  }
  
  return;
}

int firstMissingPositive(int* nums, int numsSize)
{
  struct Queue *queue;
  queue = malloc(sizeof(struct Queue));
  queue->head = malloc(sizeof(struct ListNode1));
  queue->tail = malloc(sizeof(struct ListNode1));
  queue->size = 0;
  queue->head->next = queue->tail;
  queue->tail->prev = queue->head;
  int i = 0;
  for (i = 0; i < numsSize; i++)
  {
    if (nums[i] > 0)
    {
      queue_enqueue(queue, nums[i]);
    }
  }
  if (queue->head->next->num != 1)
  {
    return 1;
  }
//  printf("here2\n");
  /* iterate through the queue to find the missing */
  struct ListNode1 *current = queue->head->next;
  while (current != queue->tail)
  {
    if ((current->num + 1) != current->next->num)
    {
      return ((current->num) + 1);
    }
    current = current->next;
  }
  return (0);
}

void main()
{
  int nums[]={0,2,2,1,1};
  printf("missing = %d\n", firstMissingPositive(nums, sizeof(nums)/sizeof(nums[0])));
  
}




