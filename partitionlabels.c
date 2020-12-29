#include<stdlib.h>
#include<string.h>
#include<stdio.h>

 
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct occurranceinfo
{
  int letter;
  int highestpos;
};

int check_occurance(char s, struct occurranceinfo *occurance, int pos)
{
  int i = 0;
  int index = s - 'a';
  int prevhighestpos = -1;
  if (occurance[index].highestpos != -1)
  {
    occurance[index].letter = 1;
    prevhighestpos = occurance[index].highestpos;
    occurance[index].highestpos = pos;
  }
  else
  {
     occurance[index].letter = 1;
     occurance[index].highestpos = pos;
  }
 // printf("prevhighestpos=%d\n",prevhighestpos);
  return prevhighestpos;
}

int* partitionLabels(char * S, int* returnSize)
{
  char *string = S;
  struct occurranceinfo occurance[26] = {};

  int i = 0;

  for (i = 0; i < 26; i++)
  {
    occurance[i].highestpos = -1;
  }

  if (S == NULL)
  {
    *returnSize = 0;
    return NULL;
  }
  // "ababcbacadefegdehijhklij"
  int partitionstart[26]={};
  for (i = 0; i < 26; i++)
  {
    partitionstart[i] = -1;
  }

  int pos = 0;
  int occuredpos = 0;
  while (*S != '\0')
  {
    occuredpos = check_occurance(*S, occurance, pos);
    if (occuredpos != -1)
    {
      /* this has occured earlier */
      /* 1. if this has occured all partitions greater than that occurance are voided out*/
      for (i = 0; i < 26; i++)
      {
        if (partitionstart[i] > occuredpos)
        {
           partitionstart[i] = -1;
        }
      }
    }
    else
    {
      /* this has not occured earlier */
      /* add a new partition */
      for (i = 0; i < 26; i++)
      {
        if (partitionstart[i] == -1)
        {
          partitionstart[i] = pos;
          printf("i = %d, partitionstart[i]=%d\n", i, partitionstart[i]);
          break;
        }
      }
    }
    pos++;
    S++;
  }
  int *returnarray = malloc(sizeof(int) * 26);
  int *origreturnarray = returnarray;
  int partitionlength[26];
  for (i = 0; i < 25; i++)
  {
    if (partitionstart[i] != -1 && partitionstart[i+1] != -1)
    {
      (*returnSize)++;
     // printf("partitionstart[%d]=%d\n",i,partitionstart[i]);
      partitionlength[i] = partitionstart[i+1] - partitionstart[i];
    //  printf("%d\n", partitionlength[i]);
      //returnarray++;
    }
    else
    {
      break;
    }
  }
  
  partitionlength[i] =  strlen(string) - partitionstart[i];
  (*returnSize)++;
  printf("%d size=%d\n", partitionlength[i], *returnSize);
  //exit(1);
  
  for (i = 0; i < *returnSize; i++)
  {
    (*returnarray) = partitionlength[i];
    returnarray++;
  }
  return (origreturnarray);
}
 
void main()
{
  int *ret;
  int  i = 0;
  int returnSize = 0;
  ret = partitionLabels("ababcbacadefegdehijhklij", &returnSize);
  for (i = 0; i < returnSize; i++)
  {
    printf("%d ", ret[i]);
  }
  //printf("");
  printf("\n");
}
