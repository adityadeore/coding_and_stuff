#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode1
{
  int val;
  struct ListNode1 *next;
  struct ListNode1 *prev;
};

struct Queue
{
  int size;
  struct ListNode1 *head;
  struct ListNode1 *tail;
};

typedef struct {
  int isoddmedian;
  int isevenmedian;
  struct ListNode1 *evenmedian[2];
  struct ListNode1 *oddmedian;
  struct Queue *queue;
} MedianFinder;

/* maintain a sorted queue here */
void queue_enqueue(MedianFinder* obj, struct Queue *queue, int num)
{
  struct ListNode1 *nodetoadd = malloc(sizeof(struct ListNode1));
  nodetoadd->val = num;
  int crossed_odd = 0;
  int crossed_evenleft = 0;
  int crossed_evenright = 0;

  if (queue->size == 0)
  {
    //printf("adding");
    //exit(1);
    queue->head->next = nodetoadd;
    queue->tail->prev = nodetoadd;
    nodetoadd->next = queue->tail;
    nodetoadd->prev = queue->head;
    queue->size++;
    obj->oddmedian = nodetoadd;
    obj->isoddmedian = 1;
  }
  else
  {
    /* insert in order */
    struct ListNode1 *current = queue->head->next;

    while (current != queue->tail)
    {
      if (current->val > nodetoadd->val)
      {
        nodetoadd->prev = current->prev;
        nodetoadd->next = current;
        current->prev->next = nodetoadd;
        current->prev = nodetoadd;
        queue->size++;
        break;
      }
      
      if (obj->isoddmedian)
      {
        /* we have odd median right now */
        if (current == obj->oddmedian)
        {
          crossed_odd = 1;
        }
      }
      else
      {
        /* we have even median now */
        if (current == obj->evenmedian[0])
        {
          crossed_evenleft = 1;
        }
        if (current == obj->evenmedian[1])
        {
          crossed_evenright = 1;
        }
      }
      current = current->next;
    }
    /* add to tail */
    if (current == queue->tail)
    {
      nodetoadd->prev = queue->tail->prev;
      nodetoadd->next = queue->tail;
      queue->tail->prev->next = nodetoadd;
      queue->tail->prev = nodetoadd;
      queue->size++;
      if (obj->oddmedian)
      {
        crossed_odd = 1;
      }
      else
      {
        crossed_evenleft = 1;
        crossed_evenright = 1;
      }
    }
    if (obj->isoddmedian == 1)
    {
      //printf("here1 %d\n", crossed_odd);
      if (crossed_odd == 1)
      {
        obj->evenmedian[0] = obj->oddmedian;

        obj->evenmedian[1] = obj->oddmedian->next;
        obj->isoddmedian = 0;
        obj->isevenmedian = 1;
        obj->oddmedian = NULL;
      }
      else
      {
        obj->evenmedian[0] = obj->oddmedian->prev;
        obj->evenmedian[1] = obj->oddmedian;
        obj->isoddmedian = 0;
        obj->isevenmedian = 1;
        obj->oddmedian = NULL;

      }
    }
    else
    {
      /* even median */
      if (crossed_evenleft == 0 && crossed_evenright == 0)
      {
        //printf("here 2");
        obj->isevenmedian = 0;
        obj->isoddmedian = 1;
        obj->oddmedian = obj->evenmedian[0];
        obj->evenmedian[0] = NULL;
        obj->evenmedian[1] = NULL;
      }
      else if (crossed_evenleft == 1 && crossed_evenright == 1)
      {
        obj->isevenmedian = 0;
        obj->isoddmedian = 1;
        obj->oddmedian = obj->evenmedian[1];
        obj->evenmedian[0] = NULL;
        obj->evenmedian[1] = NULL;

      }
      else
      {
        obj->isevenmedian = 0;
        obj->isoddmedian = 1;
        obj->oddmedian = nodetoadd;
        obj->evenmedian[0] = NULL;
        obj->evenmedian[1] = NULL;
      }
    }
  }
}
/** initialize your data structure here. */

MedianFinder* medianFinderCreate() {
    MedianFinder *obj = malloc(sizeof(MedianFinder));
    obj->isevenmedian = 0;
    obj->isoddmedian = 0;
    obj->oddmedian = NULL;
    obj->evenmedian[0] = NULL;
    obj->evenmedian[1] = NULL;

    obj->queue = malloc(sizeof(struct Queue));
    obj->queue->head = malloc(sizeof(struct ListNode1));
    obj->queue->tail = malloc(sizeof(struct ListNode1));
    obj->queue->size = 0;
    return obj;
}

void medianFinderAddNum(MedianFinder* obj, int num) {
  queue_enqueue(obj, obj->queue, num);
}

float medianFinderFindMedian(MedianFinder* obj) {
  if (obj->isevenmedian)
  {
    printf("even vals  %d %d \n", obj->evenmedian[0]->val, obj->evenmedian[1]->val);
    return (obj->evenmedian[0]->val + obj->evenmedian[1]->val)/2.0;
  }
  else
  {
   printf("odd vals  %d\n", obj->oddmedian->val);
    return ((obj->oddmedian->val));
  }
}

void medianFinderFree(MedianFinder* obj) {
  struct ListNode1 *current = obj->queue->head->next;
  struct ListNode1 *next;
  while (current != obj->queue->tail);
  {
    next = current->next;
    free(current);
    current = next;
    //printf("here");
  }

  free(obj->queue->head);
  free(obj->queue->tail);

  free(obj->queue);
  free(obj);
}

void main()
{
  MedianFinder *obj;
  obj = medianFinderCreate();
  medianFinderAddNum(obj, -1);
  printf("Median = %f\n", medianFinderFindMedian(obj));
  medianFinderAddNum(obj, -2);
  printf("Median = %f\n", medianFinderFindMedian(obj));
  medianFinderAddNum(obj, -3);
  printf("Median = %f\n", medianFinderFindMedian(obj));
  medianFinderAddNum(obj, -4);
  printf("Median = %f\n", medianFinderFindMedian(obj));
  medianFinderAddNum(obj, -5);
  printf("Median = %f\n", medianFinderFindMedian(obj));
  //medianFinderFree(obj);
}
/**
 * Your MedianFinder struct will be instantiated and called as such:
 * MedianFinder* obj = medianFinderCreate();
 * medianFinderAddNum(obj, num);
 
 * double param_2 = medianFinderFindMedian(obj);
 
 * medianFinderFree(obj);
*/
