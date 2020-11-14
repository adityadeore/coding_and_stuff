#include<stdlib.h>
#include<string.h>
#include <stdio.h>
int  isPalindrome(int x){
    char stringform[32];
    //itoa(x,stringform,10);
    /* if x is negatinve return 0 */
    if (x < 0)
    {
        return 0;
    }
    /* if only 1 digit return true */
    if (0 == x/10)
    {
        return 1;
    }
    
    
    int  j = 0;
    /* keep dividing until we get all the numbers */
    int number = x;
    do
    {
        stringform[j] = (number % 10) + 0x30;
        number = number/10;
        //printf("%c\n", stringform[j]);
        j++;        
    }while(number > 0);
    /* this is in reverse form */
    stringform[j] = '\0';    
    printf("strignform = %s\n", stringform);

    /* reverse the string again */
    char reverse[32];
    char *start = stringform;
    while(*start != '\0')
    {
        start++;
    }
    start--;
    /* this is the last number in char form */
    printf("0x%x, 0x%x", stringform, start);
    int i = 0;
    while(stringform <= start)
    {
      //printf("here1");
      reverse[i] = *start;
      printf("%c\n",  reverse[i]);
      i++;
      start--;
    }
    //i++;
    reverse[i]='\0';
    printf("\nreverse = %s", reverse);

    /*check again*/
    if (0 == strcmp(stringform, reverse))
    {
        return 1;
    }
    return 0;
        
}

void main()
{
  printf("\nres =  %d\n",isPalindrome(1000000001));
}
