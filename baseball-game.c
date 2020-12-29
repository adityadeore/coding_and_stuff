#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int calPoints(char ** ops, int opsSize)
{
  int *record = malloc(sizeof(int) * 1000);
  int count = 0;
  int index = 0;
 // char *ops1[1] = {"1"};
  //opsSize = 1;
  while (count < opsSize)
  {
    char *str = ops[count];
    //printf("%s\n", str);
    if (0 == strcmp(str, "+"))
    {
      /* plus found */
      int val1 = record[index-1];
      int val2 = record[index-2];
      int newval = val1+val2;
      record[index] = newval;
      index++;
    }
    else if (0 == strcmp(str, "C"))
    {
      /* C found */
      index--;
    }
    else if (0 == strcmp(str, "D"))
    {
      /* D found */
      int newval = 2 * record[index-1];
      record[index] = newval;
      index++;
    }
    else
    {
      int negative = 0;
      if (str[0] == '-')
      {
        negative = 1;
        str++;
      }
      int val=0;
      while (*str != '\0')
      {
        val = val * 10 + *str - '0';
        str++;
      }
      if (negative)
      {
        val = -1 * val;
      }
     // printf("Adding val %d\n", val);
      record[index] = val;
      index++;
    }
    count++;
  }
  int i = 0;
  int sum = 0;
  for (i = 0; i < index; i++)
  {
    sum = sum + record[i];
  }
  free (record);
  return sum;
}
 
int main()
{
  char **ops = {"5","2","C","D","+"};
  printf("return sum = %d\n", calPoints(ops, 5));

  return 0;
}
