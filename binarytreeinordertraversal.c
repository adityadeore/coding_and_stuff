#include "common.h"


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};

struct Stack
{
  int size;
  struct ListNode *top;
};

void* stack_pop(struct Stack *stack)
{
  struct ListNode *returnnode = NULL;
  void* elem;
  /* pop from the top of the stack */
  if (stack->size == 0)
  {
    return NULL;
  }
  returnnode = stack->top;
  stack->top = returnnode->next;
  stack->size--;
  elem = returnnode->elem;
  free(returnnode);

  return elem;
}

void stack_push(struct Stack *stack, void *elem)
{
  struct ListNode *node = NULL;
  node = malloc(sizeof(struct ListNode));

  node->elem = elem;
  if (stack->size == 0)
  {
    node->next = NULL;
  }
  else
  {
    node->next = stack->top;
  }
  stack->top = node;
  stack->size++;

  return;
}

int stack_size(struct Stack *stack)
{
  return stack->size;
}

#if 0
void printstack(struct Stack *stack)
{
  int size;
  int i = 0;
  if (size == 0)
  {
    return;
  }
  size = stack->size;
  printf("Size is %d\n", size);
  struct ListNode *printnode;
  printnode = stack->top;

  for (i=0; i <size; i++)
  {
    printf("Elem = %d\n", printnode->num);
    printnode = printnode->next;
  }
}
#endif
//struct TreeNode 
//{
 //     int val;
//      struct TreeNode *left;
//      struct TreeNode *right;
// };
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
  struct Stack *stack;
  stack = malloc(sizeof(struct Stack));
  stack->size = 0;
  stack->top = NULL;
  int i = 0;
  int *inOrderArray = (int*) malloc(sizeof(int) * (*returnSize));
  struct TreeNode* current = root;
  if (root == NULL)
  {
    *returnSize = 0;
    return NULL;
  }
 // stack_push(stack, root);

  while ((current != NULL) || (stack->size > 0))
  {
    while (current != NULL)
    {
      stack_push(stack,  current);
      current = current->left;
    }
    current = stack_pop(stack);
    *(inOrderArray + i) = current->val;
    i++;
    current = current->right;
  }
  *returnSize = i;
  return inOrderArray;
}
void main()
{
//  struct Stack *stack;
//  stack = malloc(sizeof(struct Stack));
//  stack->size = 0;
//  stack->top = NULL;
#if 0
  stack_push(stack, 1);
  stack_push(stack, 2);
  stack_push(stack, 3);
  stack_push(stack, 4);
  stack_push(stack, 5);
  stack_push(stack, 6);

  printstack(stack);

  printf("pop=%d\n",stack_pop(stack));
  printf("pop=%d\n",stack_pop(stack));
  printf("pop=%d\n",stack_pop(stack));
  printf("pop=%d\n",stack_pop(stack));
  printf("pop=%d\n",stack_pop(stack));
  printf("pop=%d\n",stack_pop(stack));
  printf("size=%d\n",stack_size(stack));
  printstack(stack);
#endif
}



