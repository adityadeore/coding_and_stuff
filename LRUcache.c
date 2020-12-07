#include<stdlib.h>
#include<string.h>
#include<stdio.h>


struct Node
{
  int key;
  int val;
  struct Node *next;
  struct Node *prev;
};

struct Queue
{
  int size;
  struct Node *head;
  struct Node *tail;
};

typedef struct {
   int capacity;
   struct Queue queue;
   struct Node* ptrNode[3000];
} LRUCache;

/* this function moves the node to the head of the list
   this maintains the LRU functionality */
void changeLRU(struct Queue *queue, struct Node *node)
{
  /* set the node passed here to the head */
  
  struct Node *prevnode = node->prev;
  struct Node *headnext = queue->head->next;
  if (node == queue->head->next)
  {
      // nothing to change 
      return;
  }
  prevnode->next = node->next;
  node->next->prev = prevnode;
  headnext->prev = node;
  node->prev = queue->head;
  node->next = headnext;
  queue->head->next = node;
}
int cacheGet(LRUCache* lruobj, struct Queue *queue, int key)
{
  struct Node *nodetoget = lruobj->ptrNode[key];
  if (nodetoget == NULL)
  {
      return -1;
  }
  changeLRU(queue, nodetoget);  
  return nodetoget->val;

}
void cachePut(LRUCache* lruobj, struct Queue *queue, int key, int val)
{
  struct Node *node = NULL;
  node = malloc(sizeof(struct Node));
  printf("size=%d, cap=%d\n",  queue->size,lruobj->capacity);
  if (lruobj->ptrNode[key] != NULL)
  {
     /* this key exists update the val */
     lruobj->ptrNode[key]->val = val;
     changeLRU(queue, lruobj->ptrNode[key]);
     return; 
  }
  if (lruobj->capacity == queue->size)
  {
    struct Node *nodetoremove; 
    /* remove from the tail */
    nodetoremove = queue->tail->prev;
    nodetoremove->prev->next = queue->tail;
    queue->tail->prev = nodetoremove->prev;
    /* set the O(1) array to NULL */
    printf("nodetoremovekey=%d",nodetoremove->key);  
    lruobj->ptrNode[nodetoremove->key] = NULL;
    free(nodetoremove);
    queue->size--;
  }
  node->key = key;
  node->val = val;
  /* special case where we are using a dummy head and tail
     */
  if (queue->size == 0)
  {
    node->next = queue->tail;
    queue->tail->prev = node;
    node->prev = queue->head;
    queue->head->next = node;
    lruobj->ptrNode[key] = node;
    queue->size++;
  }
  /* special case where we add to the head */
  else
  {
    /* store the node at the key numbered index of the array
         if it does not exist */
      node->next = queue->head->next;
      node->prev = queue->head;
      queue->head->next->prev = node;
      queue->head->next = node;
      /* store the node at the key numbered index of the array */
      lruobj->ptrNode[key] = node;
      queue->size++;
    
  }
  return;
}


LRUCache* lRUCacheCreate(int capacity) {
  int i = 0;
  LRUCache *lrucache;
  lrucache = (LRUCache*)malloc(sizeof(LRUCache));
  for (i = 0; i < 3000; i++)
  {
    lrucache->ptrNode[i] = NULL;
  }
  /* maloc the set the dummy head and tail */
  
  struct Node *node = malloc(sizeof(struct Node));

  lrucache->queue.head = node;
  lrucache->queue.head->prev = NULL;

  struct Node *node1 = malloc(sizeof(struct Node));

  lrucache->queue.tail = node1;
  lrucache->queue.tail->prev = lrucache->queue.head;
  lrucache->queue.head->next = lrucache->queue.tail;
  lrucache->queue.size = 0;
  lrucache->capacity = capacity;

  return lrucache;
}

int lRUCacheGet(LRUCache* obj, int key) {
  return (cacheGet(obj,  &obj->queue, key));
}

void lRUCachePut(LRUCache* obj, int key, int value) {
  cachePut(obj,  &obj->queue, key, value);
}

void lRUCacheFree(LRUCache* obj) {
  struct Node *current = obj->queue.head;
  struct Node *tofree;

  while (current != NULL)
  {
    tofree = current;
    current = current->next;
    free(tofree);
  }
  free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/ 


/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
void main()
{

}
