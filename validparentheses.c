#include <stdio.h>
#include <stdlib.h>

int  isValid(char * s)
{
  char openbraces[2048];
  int isvalid = 1;
  int i = 0;
  int topofstack = 0;
  if (s == NULL)
  {
    return 0;
  }
  while (*s != '\0')
  {
    /* if open braces push it onto the array*/
    if (*s == '[' || *s == '(' || *s == '{')
    {
      
    //  printf("i1=%d\n",i);
      openbraces[i] = *s;
      topofstack = i;
      i++;

    }
    /* if close brace check the last open brace */
    else if (*s == ']' || *s == '}' || *s == ')')
    {
      if (i == -1)
      {
        return 0;
      }

      if (*s == ']')
      {
        if (openbraces[topofstack] != '[')
        {
          return 0;
        }
        else
        {
          //i = i-i;
    //      printf("i2=%d\n",i);
           i = topofstack;
           topofstack--;
        }
      }
      else if (*s == ')')
      {
        
        if (openbraces[topofstack] != '(')
        {
          return 0;
        }
        else
        {
          //i = i-1;
      //    printf("i=%d\n",i);
          i = topofstack;
          topofstack--;
        }
      }
      else if (*s == '}')
      {
        if (openbraces[topofstack] != '{')
        {
          return 0;
        }
        else
        {
          //i = i-1;
       //   printf("i3=%d\n",i);
           i = topofstack;
           topofstack--;
        }
      }
    }
    else
    {
      return 0;
    }
    s++;
  } /* while*/
  //printf("i4=%d",i);
  if (i == 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


void main()
{
  int ret;
  ret = isValid("(]");
  printf("ret=%d\n",ret);

  ret = isValid("([)]");
  printf("ret=%d\n",ret);

  ret = isValid("(((((((");
  printf("ret=%d\n",ret);

  ret = isValid("({{}}}}}}}}");
  printf("ret=%d\n",ret);

  ret = isValid("()[]{}");
  printf("ret=%d\n",ret);
  ret = isValid("(");
  printf("ret=%d\n",ret);

  ret = isValid("((((((");
  printf("ret=%d\n",ret);


  ret = isValid("{[]}");
  printf("ret=%d\n",ret);

}
