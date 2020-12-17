#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
  int *returnarray = malloc(sizeof(int)*numsSize);
  *returnSize = numsSize;
  if (numsSize <= 1)
  {
    *returnSize=0;
    return NULL; 
  }

  int i = 0;
  int product = 1;
  for (i = 0; i < numsSize; i++)
  {
    product = product * nums[i];
  }

  for (i=0; i < numsSize; i++)
  {
    returnarray[i] = product/nums[i];
    printf("%d\n", returnarray[i]);
  }

  return returnarray;
}
void main()
{
  //int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
  //int nums[]={0};
  //int nums[]={1};
  //int nums[]={-1};
  int nums[]={1,2,3,4};
  int returnSize;
  int *retarray;
  retarray = productExceptSelf(nums, sizeof(nums)/sizeof(nums[0]), &returnSize);
  printf("ret %d\n", retarray[0]);
}
