#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int asciitoint(char *s)
{
  int res = 0;
 // printf("atoi %s\n", s);
  while (*s != '\0')
  {
    res = 10 * res + (*s - '0');
    s++;
  }

  return res;
}
int numDecodings(char * s)
{
  char *backptr;
  char *fwdptr;
  char *origptr = s;
  int size = strlen(s);
  int *dp = malloc(sizeof(int) * (size + 1));
  memset(dp, 0, sizeof(int) * (size + 1));

  dp[0] = 1;
  
  if (strlen(s) == 1)
  {
    int val = asciitoint(s);
    if (val == 0)
    {
      return 0;
    }
    else
    {
      return 1;
    }
  }
  backptr = s;
  /* check the back ptr */
  int val = *backptr - '0';
  if (val > 0)
  {
    dp[1] = 1;
  }
  else
  {
    dp[1] = 0;
  }
  fwdptr = s+1;
  int i = 0;
  for (i = 2; i <= size; i++)
  {
    /* one digit */ 
    char *str2 = malloc(sizeof(char)*2);
    str2[0] = s[i-1];
    str2[1] = '\0';
    int val =  asciitoint(str2);
    free(str2);
    if (val > 0)
    {
      dp[i] = dp[i] + dp[i-1];
    }
    
    /* two digits */
    char *str3 = malloc(sizeof(char)*3);
    str3[0] = s[i-2];
    str3[1] = s[i-1];
    str3[2] = '\0';
    val =  asciitoint(str3);
    free(str3);  
    if (val >= 10 && val <= 26)
    {
      dp[i] = dp[i] + dp[i-2];
    }

  }
  /* print the dp array */
    
  for (i=0; i <= size; i++)
  {
    printf("dp[%d]=%d\n", i, dp[i]);
  }
  return dp[size];
}

int main()
{
  char *string = malloc(sizeof(char)*100);
  strcpy(string, "226");//2626262626262626262626");

  printf("ret=%d\n", numDecodings(string));
}
