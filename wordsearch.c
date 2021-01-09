int isvalid(int i,int j, int numrows, int numcols)
{
  if (i >= 0 && i < numrows && j >= 0 && j < numcols)
  {
    return 1;
  }
  return 0;
}
int backtrack(char **board, int i , int j, char *word, int **shadowgrid, int found, int numrows, int numcols)
{
  /* check around this square */
  //word = word + 1;
  if (*word == '\0' )
  {
    return 1;
  }
    char temp;// = malloc(sizeof(char) * 4);
    //strcpy(temp, board[i][j])
    temp = board[i][j]    ;
    board[i][j] = ' ';
    int ret = 0;
    /* check i, j+1 */
    if (ret == 0 && isvalid(i,j+1, numrows, numcols) && board[i][j+1] == *word)
    {
      shadowgrid[i][j+1] = -1;
      ret = backtrack(board, i , j + 1, word + 1, shadowgrid, 1, numrows, numcols);
      
    }
    if (ret == 0 && isvalid(i,j-1, numrows, numcols)  && board[i][j-1] == *word)
    {
      shadowgrid[i][j-1] = -1;
      ret = backtrack(board, i , j-1, word + 1, shadowgrid, 1, numrows, numcols);

    }
    if (ret == 0 && isvalid(i-1,j, numrows, numcols)  && board[i-1][j] == *word)
    {
      shadowgrid[i-1][j] = -1;
      ret = backtrack(board, i -1 , j, word + 1, shadowgrid, 1, numrows, numcols);

    }
    if (ret == 0 && isvalid(i+1,j, numrows, numcols) && board[i+1][j] == *word)
    {
      shadowgrid[i+1][j] = -1;
      ret = backtrack(board, i+1 , j, word + 1, shadowgrid, 1, numrows, numcols);

    }
    board[i][j] =  temp;
    //free(temp);
    return ret;
}

bool exist(char** board, int boardSize, int* boardColSize, char * word){
  int i = 0;
  int j = 0;
  int numrows = boardSize;
  int numcols = *boardColSize;
  /* malloc shadow grid as int.
     1. we use 0 as unused
     2. -1 as visited
     3. increment from 0 as we find a match
     */
  int **shadowgrid;
  shadowgrid = malloc(sizeof(int) * 1024);
  for (i = 0; i < numrows; i++)
  {
    shadowgrid[i] = malloc(sizeof(int) * 1024);
   // memset(shadowgrid[i], 0 , sizeof(int) * numcols);
  }
  for (i = 0; i < numrows; i++)
  {
      for (j = 0; j < numcols; j++)
      {
        shadowgrid[i][j] = 0;
      }  
  }
  for (i = 0; i < numrows; i++)
  {
    for (j = 0; j < numcols; j++)
    {
      if ((board[i][j]) != word[0])
      {
        //shadowgrid[i][j] = -1;
        continue;
      }
      else
      {
        shadowgrid[i][j] = -1; 
        int ret = backtrack(board, i, j, word+1, shadowgrid, 1, numrows, numcols);
        if (ret == 1)
        {
          return 1;
        }
        else
        {
              int k = 0;
              int l = 0;
              for (k = 0; k < numrows; k++)
              {
                for (l = 0; l < numcols;l++)
                {
                    shadowgrid[k][l] = 0;
                }      
              }
        }
      }
    }
  }
  return 0;


}
