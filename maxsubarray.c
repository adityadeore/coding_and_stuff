#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int maxSubArray(int* nums, int numsSize){
  int i = 0;
  int currentmax = 0;
  int currentmaxstart = 0;
  int currentmaxend = 0;
  currentmax = nums[i];
  int sum = 0;
  sum = nums[i];
  for (i=1; i < numsSize; i++)
  {
    sum = sum + nums[i];
    if (sum > currentmax)
    {
      currentmax = sum;
    }
    //printf("currentmax = %d, sum=%d\n", currentmax, sum);
    if (sum < nums[i])
    {

      sum = nums[i];
      if (nums[i] > currentmax)  
      currentmax = nums[i];  
     // printf("currntmaxstart=%d\n",i);
    }
    else
    {
      currentmaxend = i;
  //    printf("currntmaxend=%d\n",i);
    }
  }
  return currentmax;
}

void main()
{
  //int nums[] = {-2,1,-3,4,-1,2,1,-5,4};
  //int nums[]={0};
  //int nums[]={1};
  //int nums[]={-1};
  int nums[]={-2,1};
  
  printf("retval=%d\n\n",maxSubArray((int*)&nums, sizeof(nums)/sizeof(nums[0])));
}
