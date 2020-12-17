#include "common.h"


struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
};
 
struct Queue
{
  int size;
  struct ListNode1 *head;
  struct ListNode1 *tail;
};

void* queue_dequeue(struct Queue *queue)
{
  void *returnelem = NULL;
  struct ListNode1 *returnnode = NULL;
  int val;
  /* pop from the top of the stack */
  if (queue->size == 0)
  {
    return NULL;
  }
  returnelem = queue->head->elem;
  returnnode = queue->head;
  queue->head = queue->head->next;
  queue->size--;

  free(returnnode);

  return returnelem;
}

void queue_enqueue(struct Queue *queue, void *elem)
{
  struct ListNode1 *node = NULL;
  node = malloc(sizeof(struct ListNode1));

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
  struct ListNode1 *printnode;
  printnode = queue->head;

  for (i=0; i <size; i++)
  {
    printf("Elem = %d\n", (int)printnode->elem);
    printnode = printnode->next;
  }
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
  struct Queue *queue;
  queue = malloc(sizeof(struct Queue));
  queue->size = 0;
  queue->head = NULL;
  queue->tail = NULL;
  
  int *ptrArray[2048];
  returnColumnSizes = malloc(sizeof(int) * 2048); 
  int i = 0;
  int j = 0;
  for(i=0; i<2048;i++)
  {
      ptrArray[i]=malloc(sizeof(int) * 2048);
  }
  if (root == NULL)
  {
    *returnSize = 0;
    return NULL;
  }
  int totalcount = 0;
  queue_enqueue(queue, root);
  struct TreeNode* current;
  while (queue->size > 0)
  {
    printf("size = %d\n", queue->size);
    int size = queue->size;  
    for (i = 0; i < size; i++)
    {
      current = (struct TreeNode *)queue_dequeue(queue);
      
      *(ptrArray +j+i) = current->val;
         printf("val=%d,%d,%d\n", *(ptrArray+i+j),j,i); 
      totalcount++;
      if (current->left != NULL)
      {
        //printf("queueval=%d\n", current->left->val);
        queue_enqueue(queue,current->left);
      }
      if (current->right != NULL)
      {
       // printf("queueval=%d\n", current->right->val);  
        queue_enqueue(queue, current->right);
      }
    
    }
    *(returnColumnSizes+j) = i ;
    printf("retcol=%d,j=%d\n",*(returnColumnSizes+j),j);  
    //printf("ptrarray=%d,j=%d\n", *(ptrArray[0][j]),j);    
    j++;
  }
   printf("\nretsize=%d\n",j); 
  *returnSize=j-1;  
  return (ptrArray);}

void main()
{
  struct Queue *queue;
  queue = malloc(sizeof(struct Queue));
  queue->size = 0;
  queue->head = NULL;
  queue->tail = NULL;

  queue_enqueue(queue,(void*)6);
  queue_enqueue(queue,(void*)2);
  queue_enqueue(queue,(void*)3);
  queue_enqueue(queue,(void*)4);
  queue_enqueue(queue,(void*)5);
  queue_enqueue(queue,(void*)6);
  printqueue(queue);

  printf("dequeue=%d\n",(int)queue_dequeue(queue));
  printf("dequeue=%d\n",(int)queue_dequeue(queue));
  printf("dequeue=%d\n",(int)queue_dequeue(queue));
  printf("dequeue=%d\n",(int)queue_dequeue(queue));
  printf("dequeue=%d\n",(int)queue_dequeue(queue));
  printf("dequeue=%d\n",(int)queue_dequeue(queue));
  printf("size=%d\n",queue_size(queue));
  printqueue(queue);

}



