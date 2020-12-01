#include<stdlib.h>
#include<string.h>
#include <stdio.h>

struct ListNode
{
  int val;
  struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
  /* handle all NULL situations */
  if (l1 == NULL && l2 == NULL)
  {
    return NULL;
  }

  if (l1 == NULL)
  {
    return l2;
  }

  if (l2 == NULL)
  {
    return l1;
  }

  struct ListNode *l1current = l1;
  struct ListNode *l2current = l2;
  struct ListNode *sumcurrent = NULL;
  struct ListNode *sumhead = NULL;
  int carryover = 0;
  int newval;
  /* add the numbers from head of the list  */
  while (l1current != NULL && l2current != NULL)
  {
    newval = l1current->val + l2current->val + carryover;
    if (newval >= 10)
    {
      newval = newval - 10;
      carryover = 1;
    }
    /* malloc the memory */
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = newval;
    node->next = NULL;
    /* first node of sum list */
    if (sumhead == NULL)
    {
      sumhead = node;
      sumcurrent = node;
      sumcurrent->next = NULL;
    }
    else
    {
      sumcurrent->next = node;
      sumcurrent = node;
    }
    l1current = l1current->next;
    l2current = l2current->next;
  }

  /* 3 things can happen
   
     1. both are the same length
     2. l1 longer than l2
     3. l2 longer than l1 */
  /* case 1 */
  if (l1current == NULL && l2current == NULL && carryover == 1 )
  {
    struct ListNode *node = malloc(sizeof(struct ListNode));
    node->val = 1;
    node->next = NULL;
    sumcurrent->next = node;
    return sumhead;
  }
  else if (l1current == NULL && l2current != NULL)
  {
    /*complete the l2 list */
    while (l2current != NULL)
    {
      newval = l2current->val + carryover;
      if (newval >= 10)
      {
        newval = newval - 10;
        carryover = 1;
      }
      /* malloc the memory */
      struct ListNode *node = malloc(sizeof(struct ListNode));
      node->val = newval;
      node->next = NULL;
      sumcurrent->next = node;
      sumcurrent = node;
      l2current = l2current->next;
    }
    if (carryover == 1)
    {
      struct ListNode *node = malloc(sizeof(struct ListNode));
      node->val = 1;
      node->next = NULL;
      sumcurrent->next = node;
      return sumhead;
    }
    else
    {
      return sumhead;
    }
  }
  else if (l2current == NULL && l1current != NULL)
  {
    /*complete the l1 list */
    while (l1current != NULL)
    {
      newval = l1current->val + carryover;
      if (newval >= 10)
      {
        newval = newval - 10;
        carryover = 1;
      }
      /* malloc the memory */
      struct ListNode *node = malloc(sizeof(struct ListNode));
      node->val = newval;
      node->next = NULL;
      sumcurrent->next = node;
      sumcurrent = node;
      l1current = l1current->next;
    }
    if (carryover == 1)
    {
      struct ListNode *node = malloc(sizeof(struct ListNode));
      node->val = 1;
      node->next = NULL;
      sumcurrent->next = node;
      return sumhead;
    }
    else
    {
      return sumhead;
    }
  }
  else
  {
    return NULL;
  }

}

void main()
{

}
