
int checkpalindrome(char *start, char *end)
{
  int length = 0;
  int ispalindrome = 1;
  //printf("in palindrome");
  //printf("%c, %c\n", *start, *end);
  while (start < end)
  {
    if (*start != *end)
    {
      ispalindrome = 0;
      break;
    }
    
    start++;
    end--;
  }

  if (ispalindrome)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
char * longestPalindrome(char * s){
  //printf("%s",s);
  //exit(1);
  if (s == NULL)
  {
    return NULL;
  }
  if (strlen(s) == 1)
  {
    return s;
  }
  char *origstring = (char*)malloc(strlen(s)+1);
  strcpy(origstring, s);
  //printf("here1");
  //exit(1);
  /* convert to lower case */
  char *start = origstring;
  #if 0
  while (*start != '\0')
  {
    //printf("here");
    //exit(1);
    if ((*start) >= 'A' && (*start) <= 'Z')
    {
      /* means this is upper case */
     // printf("%c\n", *start);
      *start = (int)(*start) + 0x20;
    //  printf("%c\n", *start);
    }
    start++;
  }
  #endif  
 // printf("all lower = %s\n", origstring);
//  exit(1);

  int i = 0;
  int j = 0;
  int ispalin = 0;
  int curmaxlength = 0;
  int length = 0;
  char *maxpalinstart=NULL;
  char *maxpalinend=NULL;
  char *resultstring  = NULL;
  resultstring = (char*)malloc((sizeof(char)*1000) + 1);

  for (i = 0; i < (strlen(origstring) - 1); i++)
  {
    for (j = i+1; j < strlen(origstring); j++)
    {
      ispalin = checkpalindrome(origstring+i, origstring+j);
      //printf("ispalin = %d, i = %d, j = %d\n", ispalin, i, j);
      if (ispalin)
      {
        length = j - i;
        if (length > curmaxlength)
        {
          curmaxlength = length;
          maxpalinstart = origstring+i;
          maxpalinend = origstring+j;
        }
        //printf("curmaxlength = %d\n", curmaxlength);
        memcpy(resultstring, maxpalinstart, curmaxlength+1);
        *(resultstring + curmaxlength + 1) = '\0';
      }
    }
  }
  if (curmaxlength > 0)
  {
    
    return resultstring;
  }
  else
  {
    *(origstring+1)='\0';
    return origstring;
  }
  

}

void main
{
  char *res = longestPalindrome("aa");
  printf("string res = %s", res);
}
