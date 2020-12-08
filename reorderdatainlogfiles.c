#include<stdlib.h>
#include<string.h>
#include<stdio.h>
#define MAX 100

char ** reorderLogFiles(char ** logs, int logsSize, int* returnSize)
{
    char *diglogs[100];
    char *letlogs[100];
    char *allogs[100];
    
    char *S;
    char *start;
    int i = 0;
    int digcount = 0;
    int letcount = 0;
  
    for (i = 0; i < logsSize; i++)
    {
      allogs[i] = (char*)malloc(sizeof(char)*100);
    }
    char **retlog = &allogs[0];
    /* let us sort the logs into dig and let */
    
    for(i = 0; i < logsSize; i++)
    {
       // printf("%s\n", logs[i]);
        S = *(logs+i);
        start = S;
        //printf("%s\n", start);
       // exit(1);
        while(*S != ' ')
        {
            S++;        
        }
        S++;
        //printf("%s\n", S);
        if (*S > 0x39)
        {
            /* this is a let log */
            letlogs[letcount] = start;
            //printf("%s,%d\n", letlogs[letcount], letcount);
            letcount++;
        }
        else
        {
            /* this is a dig log */
            diglogs[digcount] = start;
            //printf("%s,%d\n", diglogs[digcount], digcount);
            digcount++;
        }
    }
    
    /* we have 2 arrays done. now sort the let array  */
    int j = 0;
    char *afteridentifier1;
    char *afteridentifier2;
    char identifier1[100];
    char identifier2[100];
    char *ptridentifier1 = &identifier1; 
    char *ptridentifier2 = &identifier2;
    char *ptridentifier1start = &identifier1; 
    char *ptridentifier2start = &identifier2;

    char *temp;
  //  printf("letcount = %d\n", letcount);
    for (i = 0; i < letcount-1; i++)
    {
   //   printf("here1\n");
        for (j = 0; j < letcount-i-1; j++)
        {
            
            //exit(1);
           // printf("%s, %s\n", letlogs[j], letlogs[j+1]);
            afteridentifier1 = letlogs[j];
            afteridentifier2 = letlogs[j+1];
            //identifier1 = letlogs[j];
            //identifier2 = letlogs[j+1];
            
            while(*afteridentifier1 != ' ')
            {
                afteridentifier1++;
            }
            afteridentifier1++;
            while(*afteridentifier2 != ' ')
            {
                afteridentifier2++;
            }
            afteridentifier2++;
            //printf("j = %d %s, %s\n", j, afteridentifier1, afteridentifier2);
            if(0 < strcmp(afteridentifier1, afteridentifier2))
            {
                //strcpy(temp, letlogs[j]);
                //strcpy(letlogs[j], letlogs[j+1]);
                //strcpy(letlogs[j+1], temp);
              temp = letlogs[j];
              letlogs[j] = letlogs[j+1];
              letlogs[j+1] = temp;
            }
            else
            {
                
                if (0 == strcmp(afteridentifier1, afteridentifier2))
                {
                  //printf("here");
                    /* if this is the same then check the identifier */
                    char *string = letlogs[j];
                    while(*string != ' ')
                    {
                        memcpy(ptridentifier1, string, sizeof(char));
                        ptridentifier1++;
                        string++;
                    }
                    ptridentifier1 = '\0';
                    char *string1 = letlogs[j+1];
                    while(*string1 != ' ')
                    {
                        memcpy(ptridentifier2, string1, sizeof(char));
                        ptridentifier2++;
                        string1++;
                    }
                    ptridentifier2 = '\0';
                    if (0 < strcmp(ptridentifier1start, ptridentifier2start))
                    {
                        temp = letlogs[j];
                        letlogs[j] = letlogs[j+1];
                        letlogs[j+1] = temp;
                    }
                }
            }
        }
    }
    /* now set the full log with the let array */
 //   printf("size = %d\n", letcount + digcount);
    
    for(i = 0; i < letcount; i++)
    {
//        printf("%s\n", letlogs[i]);
        strcpy(allogs[i], letlogs[i]);
    }
    
    /* now copy the dig log */
     j = 0;
    for(i = letcount; i < letcount + digcount; i++)
    {
//        printf("%s\n", diglogs[j]);
        //exit(1);
        strcpy(allogs[i], diglogs[j]);
        j++;
    }
    //exit(1);
    *returnSize = logsSize;
    
    return (retlog);
}

void main()
{
  /*
  logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"] 
   
  */
/*  ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo","a2 act car"]
*/ 

  /*
  ["l5sh 6 3869 08 1295", "16o 94884717383724 9", "43 490972281212 3 51", "9 ehyjki ngcoobi mi", "2epy 85881033085988", "7z fqkbxxqfks f y dg", "9h4p 5 791738 954209", "p i hz uubk id s m l", "wd lfqgmu pvklkdp u", "m4jl 225084707500464", "6np2 bqrrqt q vtap h", "e mpgfn bfkylg zewmg", "ttzoz 035658365825 9", "k5pkn 88312912782538", "ry9 8231674347096 00", "w 831 74626 07 353 9", "bxao armngjllmvqwn q", "0uoj 9 8896814034171", "0 81650258784962331", "t3df gjjn nxbrryos b"]
  */
  char *logs[] = {"l5sh 6 3869 08 1295", "16o 94884717383724 9", "43 490972281212 3 51", "9 ehyjki ngcoobi mi", 
                  "2epy 85881033085988", "7z fqkbxxqfks f y dg", "9h4p 5 791738 954209", "p i hz uubk id s m l", 
                  "wd lfqgmu pvklkdp u", "m4jl 225084707500464", "6np2 bqrrqt q vtap h", "e mpgfn bfkylg zewmg", 
                 "ttzoz 035658365825 9", "k5pkn 88312912782538", "ry9 8231674347096 00", "w 831 74626 07 353 9", 
                 "bxao armngjllmvqwn q", "0uoj 9 8896814034171", "0 81650258784962331", "t3df gjjn nxbrryos b"};
  int returnsize;
  char **alllogs;
  alllogs = reorderLogFiles(logs, 20, &returnsize);

  int i = 0;
  for (i = 0; i < returnsize; i++)
  {
    printf("%s\n", alllogs[i]);
  }

}
