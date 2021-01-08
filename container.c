#define MIN(a,b)   (a<b)?(a):(b)
#include <stdio.h>
#if 0
int maxArea(int* height, int heightSize){
    int i = 0;
    int j = 0;
    int curmax = 0;
    int max = 0;
    for(i = 0; i < heightSize - 1; i++)
    {
        for (j = i+1; j < heightSize; j++)
        {
            printf("\n %d, %d,%d,%d", height[i], height[j],j,i);
            max = (MIN(height[i],height[j])) * (j-i);
            if (max > curmax)
            {
                printf("maxcalc=%d\n", max);
                curmax = max;
            }
        }
    }
    printf("max = %d\n", curmax);
    return curmax;
}
#endif

int maxArea1(int* height, int heightSize){
    int xstart = 0;
    int xend = heightSize - 1;
    int curmax = 0;
    int max = 0;
    
    int *start = height + xstart;
    int *end = height + xend;

    while (xstart < xend)
    {
      printf("start=%d, end=%d, %d, %d\n", *start, *end, xstart, xend);
      max = (MIN(*start,*end)) * (xend-xstart);
      if (max > curmax)
      {
          printf("maxcalc=%d\n", max);
          curmax = max;
      }
      if (*start < *end)
      {
        start++;
        xstart++;
      }
      else
      {
        end--;
        xend--;
      }
    }

    printf("max = %d\n", curmax);
    return curmax;
}

void main()
{
  int height[20]={1,2,4,3};

  
  maxArea1(height, 4);
}
