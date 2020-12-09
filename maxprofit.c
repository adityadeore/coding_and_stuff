#include<stdlib.h>
#include<string.h>
#include<stdio.h>



int maxProfit(int* prices, int pricesSize)
{
  int currentbuyindex = 0;
  int currentsellindex = 1;
  int i = 0;
  int currentmaxprofit = 0;
  int maxprofitbuyindex = 0;
  int maxprofitsellindex = 1;
  int diff = 0;

  while ((currentbuyindex <= (pricesSize - 2)) && currentsellindex <= (pricesSize-1) )
  {
    diff = prices[currentsellindex] - prices[currentbuyindex];
   // printf("%d %d %d %d\n", currentsellindex, currentbuyindex, diff, currentmaxprofit);
    if (diff > currentmaxprofit)
    {
      currentmaxprofit = diff;
      maxprofitbuyindex = currentbuyindex;
      maxprofitsellindex = currentsellindex;
      currentsellindex++;
    }
    else
    {
      if (diff <= 0)
      {
        currentbuyindex = currentsellindex;
        currentsellindex = currentbuyindex + 1;
      }
      else
      {
        currentsellindex++;
      }
    }
  }
  //if ((prices[currentbuyindex+1] - prices[currentbuyindex]) > currentmaxprofit)
 // {
 //   currentmaxprofit = prices[currentbuyindex+1] - prices[currentbuyindex];
 // }
  return currentmaxprofit;
}

void main()
{
  int prices[]={7,6,4,3,1};
  printf("%d\n", maxProfit(prices, sizeof(prices)/sizeof(prices[0])));
  return;
  
}
