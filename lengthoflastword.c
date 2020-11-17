#include<stdlib.h>
#include<string.h>
#include <stdio.h>

int lengthOfLastWord(char * s){
  if (s == NULL)
  {
    return 0;
  }

  char *start = s;
  while (*start == ' ')
  {
    start++;
  }

  if (*start == '\0')
  {
    /* there are no non-space char */
    return 0;
  }
  /* start of the first word*/
  char *startofword = start;
  char *endofword=startofword;
  int newwordstarted = 1;

  while (*start != '\0')
  {
    if (*start == ' ')
    {
      if (newwordstarted == 1)
      {
        endofword = start - 1;
        newwordstarted = 0;
        start++;
      }
      else
      {
        start++;
      }
    }
    else
    {
      if (newwordstarted == 0)
      {
        startofword = start;
        newwordstarted = 1;
      }
      start++;
    }
  }
  if (newwordstarted == 1)
  {
    endofword = start - 1;
  }

  int count = 0;
  while (endofword != startofword)
  {
    endofword--;
    count++;
  }
  return (count + 1);
}
void main()
{

  printf("ret = %d", lengthOfLastWord("       The cat jumped over the moon "));
}
