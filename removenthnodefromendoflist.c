#include <stdio.h>
#include <stdlib.h>

/**
  Definition for singly-linked list. */
  struct ListNode {
      int val;
      struct ListNode *next;
  };


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (head == NULL || head->next == NULL)
    {
      return NULL;
    }
    struct ListNode *current = head;
    struct ListNode *fwdcurrent = head;
    int i = 0;

    for (i = 0; i < n; i++)
    {
      if (fwdcurrent->next  != NULL)
      {
        fwdcurrent = fwdcurrent->next;
      }
      else
      {
        break;
      }
    }
    /* if the list is not long enough */
    if (n > (i+1))
    {
      return NULL;
    }
    else if (n == i+1)
    {
      return (head->next);
    }
    /* move both pointers until we reach the end*/
    while (fwdcurrent->next != NULL)
    {
      fwdcurrent= fwdcurrent->next;
      current = current->next;
    }
    /* at this point the current->next should point to the elem to be removed*/
    current->next = current->next->next;
    return head;
}

void main()
{
  struct ListNode head;
  struct ListNode node;
  //removeNthFromEnd

}
