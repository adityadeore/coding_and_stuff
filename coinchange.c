#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MIN(a, b) ((a < b) ? (a) : (b))
int coinChange(int* coins, int coinsSize, int amount)
{
  int *dp = malloc(sizeof(int) * (amount+1));
  int i = 0, j = 0;
  
#if 1
  for (i = 0; i <= amount; i++)
  {
    //printf("dp[%d]=%d\n",i, dp[i]);
    dp[i] = amount+1;
    
  }
  //exit(1);
#endif
  dp[0] = 0;
  
  for (i = 0; i <= amount; i++)
  {
    for (j = 0; j < coinsSize; j++)
    {
      if (coins[j] <= i)
      {
        int val = 1 + dp[i - coins[j]];
        dp[i] = MIN(dp[i], val);
      }
    }
  }
#if 0
  for (i = 0; i <= amount; i++)
  {
    printf("dp[%d]=%d\n",i, dp[i]);
  }
#endif
  return (dp[amount] <= amount  ? dp[amount] : -1);
}

int main()
{
  int *coins = malloc(sizeof(int) * 100);
//[186,419,83,408]
  coins[0] = 186;
  coins[1] = 419;
  coins[2] = 483;
  coins[3] = 408;
  //coins[3] = 408;

  printf("ret=%d\n", coinChange(coins, 4, 6249));
}
