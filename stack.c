#include "common.h"

struct Stack
{
  int size;
  struct ListNode *top;
};

int stack_pop(struct Stack *stack)
{
  struct ListNode *returnnode = NULL;
  int val;
  /* pop from the top of the stack */
  if (stack->size == 0)
  {
    return -1;
  }
  returnnode = stack->top;
  stack->top = returnnode->next;
  stack->size--;
  val = returnnode->num;
  free(returnnode);

  return val;
}

void stack_push(struct Stack *stack, int num)
{
  struct ListNode *node = NULL;
  node = malloc(sizeof(struct ListNode));

  node->num = num;
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
void main()
{
  struct Stack *stack;
  stack = malloc(sizeof(struct Stack));
  stack->size = 0;
  stack->top = NULL;

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

}



