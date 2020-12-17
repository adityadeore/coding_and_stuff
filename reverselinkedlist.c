#include <stdio.h>
#include <stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
      int val;
      struct ListNode *next;
};


struct ListNode* reverseList(struct ListNode* head)
{
  if (head  == NULL)
  {
    return NULL;
  }
  if (head->next == NULL)
  {
    return head;
  }

  struct ListNode *current = head;
  struct ListNode *currentnext = head->next;
  struct ListNode* temp = NULL;
  while (currentnext != NULL)
  {
    
    temp = current;
   // printf("temp = 0x%x, val=%d\n", temp, temp->val);    
    current = currentnext;
 //   printf("current = 0x%x, val=%d\n", current, current->val);   
    currentnext = currentnext->next;
    current->next = temp;
 //    printf("current = 0x%x, curent->next=0x%x\n", current, current->next); 
    if (temp == head)
    {
      temp->next = NULL;
    }
  }
//  printf("current = 0x%x, val=%d\n", temp, temp->val);  
  return current;
}

void main()
{
  struct ListNode Node1;
  struct ListNode Node2;
  struct ListNode Node3;
  struct ListNode Node4;
  struct ListNode Node5;

}
