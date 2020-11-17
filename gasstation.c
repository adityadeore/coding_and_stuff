#include<stdlib.h>
#include<string.h>
#include <stdio.h>

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize){
    if (gasSize != costSize) return -1;
    if (gasSize == 1) 
    {
        if (*gas >= *cost)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
    
    int loopcount = 0;
    int startstation = 0;
    int i = 0;
    int endstation = gasSize - 1;
    int succeed = 1;
    int gasval = *(gas);
    int j = 0;
    /* loop through the array */
    while(startstation <= gasSize-1)
    {
        if (startstation == 0)
        {
          endstation = gasSize - 1;
        }
        /* we have started in the middle */
        else
        {
          endstation = startstation - 1;
        }
        //printf("\nstartstation=%d, end station=%d",startstation, endstation);
        gasval = *(gas+startstation);
        succeed = 1;
        for (i = startstation; i != endstation;)
        {
         //   printf("\ni=%d,gasval=%d,cost=%d",i,gasval,*(cost+i));
            if (gasval >= *(cost+i))
            {
              if (i == (gasSize - 1))
              {
                j = 0;
              }
              else
              {
                j = i+1;
              }
              gasval = (gasval) - (*(cost+i)) + (*(gas+j));
       //       printf("\nj=%d,newgasval=%d, newgasadded=%d",j,gasval,*(gas+j));
              if (i == (gasSize - 1))
              {
                i = 0;
              }
              else
              {
                i++;
              }
            }
            else
            {
              succeed = 0;
              break; // for loop
            }
        }
       // printf("\nsucceed=%d", succeed);
        if (succeed == 1)
        {
          /* check the last station */
       //   printf("\n11i=%d,gasval=%d,cost=%d",i,gasval,*(cost+i));
          if (gasval >= *(cost+i))
          {
            return startstation;
          }
          else
          {
            return -1;
          }
        }
        else
        {
          startstation++;
        }
    }
    return -1;
}
void main()
{
  int gas[]={5,1,2,3,4};
  int cost[]={4,4,1,5,1};

  printf("\nret=%d\n",canCompleteCircuit((int*)&gas, 5, (int*)&cost, 5));
}
