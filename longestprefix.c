#include<stdlib.h>
#include<string.h>
#include<stdio.h>



char *longestCommonPrefix(char ** strs, int strsSize)
{
  char *prefix = malloc(sizeof(char) * 200);
  if (strsSize == 0)
  {
    return "";
  }
  int index = 0;
  for (int i = 0; i < strsSize ; i++)
  {
    if (strlen(strs[i]) == 0)
    {
      return "";
    }
  }
  int firststringlen = strlen(strs[0]);
  for (int j = 0; j < firststringlen; j++)
  {
    char c = strs[0][j];
    for (int i = 1; i < strsSize; i++)
    {
      if (strs[i][j] == '\0' || c != strs[i][j])
      {
        prefix[index]='\0';
        return prefix; 
      }
    }
    prefix[index]=c;
    index++;
  }
  prefix[index] = '\0';
  //printf("Prefix = %s", prefix);
  return prefix;
}

int main()
{
  char **strs;

  strs = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++)
  {
    strs[i] = malloc(sizeof(char) * 20);
  }
  strcpy(strs[0], "flower");
  strcpy(strs[1], "flow");
  strcpy(strs[2], "flight");

  printf("prefix = %s\n",longestCommonPrefix(strs, 3));
}
