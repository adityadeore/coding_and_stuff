#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int myAtoi(char * s){
    if (s == NULL)
    {
        return -1;
    }
    char *start = s;
    char *c = s;
    int array[20];
    long long temp=0;
    int i = 0;
    //printf("%c\n", *c);
    //exit(0);
    if ((*c < '0' || *c > '9') && *c != '-' && *c != ' ')
    {
        printf("Cannot perform conversion since first char is not right\n");
        return -2;
    }
    int negative = 0;
    while(*c == ' ')
    {
        c++;
        continue;
    }
    if (*c == '-')
    {
        negative = 1;
        c++;
    }
        
    while(*c >= '0' && *c <= '9')
    {
        
        array[i] = *c - 0x30;
        //printf("array[i]=%d",array[i]);
        i++;
        c++;
        
    }
    //printf("\n%d",i);
    int sizeofarray = i;
    i = 0;
    int expindex = 0;
    int multfactor = 1;
    
    for(i = sizeofarray-1; i >= 0; i--)
    {
        int j = 0;
        for (j = 0;j < expindex;j++)
        {
          multfactor = multfactor * 10;
        }
        temp = temp + (array[i] * multfactor);
        if (temp > 2147483648)
        {
          if (negative == 1)
          {
            //printf("returning ");
            return -2147483648;
          }
          else
          {
            //printf("returning 1");
            return 2147483647;
          }
        }
        multfactor = 1;
        expindex++;
    }
    if (negative == 1)
    {
        temp = -1*temp;        
    }

    printf("\n\ntemp=%d\n", temp);
    if (temp < -2147483648)
    {
        return (-2147483648);
    }
    if (temp > (2147483648 - 1))
    {
        return (2147483648 - 1);
    }
    return temp;
}

void main()
{
  myAtoi("5656565");
}
