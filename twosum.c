#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    if (nums == NULL || returnSize == NULL)
    {
        return NULL;
    }
    int i = 0;
    int j = 0;
    int *returnarray = NULL;
        
    returnarray = (int*)malloc(sizeof(int) * 2);
    if (returnarray == NULL)
    {
        return NULL;
    }
    for(i = 0; i < numsSize-1; i++)
    {
        for (j = i+1; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                returnarray[0] = i;
                returnarray[1] = j;
                *returnSize = 2;
                return (returnarray);
            }
        }
    }
    *returnSize = 0;
    return NULL;
    
}
void main()
{
 // printf("result = %d\n", add2numbersnooperators(15, -32));
  int nums[] = {0,4,3,0};
  int returnSize;

  int *retarray = twoSum(nums, sizeof(nums)/sizeof(nums[0]), 0, &returnSize);
  int i = 0 ;
  for (i = 0; i < returnSize; i++)
  {
    printf("%d ", retarray[i]);
  }
  printf("\n");

}
