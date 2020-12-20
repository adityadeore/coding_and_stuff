
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isnotsafe(int i, int j, int numrows, int numcols)
{
    if (i >= 0 && i < numrows && j >= 0 && j < numcols)
        return 1;
    return 0;
}

int orangesRotting(int** grid, int gridSize, int* gridColSize)
{
  
  int *shadowgrid[100];
  int changed = 0;
  int i = 0;  
  int j = 0;
  //int shadowgrid[3][3] = {{2,1,1},{1,1,0},{0,1,1}};
 /* int  shadowgrid[3][5] = { { 2, 1, 0, 2, 1 },
                            { 1, 0, 1, 2, 1 },
                             { 1, 0, 0, 2, 1 } 
                          }; */
  int numrows = gridSize;
  int numcols = *gridColSize;
  //printf("numrows = %d, numcols = %d\n", numrows, numcols);
#if 1
  for (i = 0; i < numrows; i++)
  {
    shadowgrid[i] = (int*)malloc(sizeof(int) * numcols);
    
  }
#endif
#if 1
  for (i = 0; i < numrows; i++)
  {
    for (j = 0; j < numcols; j++)
    {
    //  printf("here");exit(1);
      //shadowgrid[i][j] = grid[i][j];
      printf("%d", grid[i][j]); exit(1);
    }
  }
#endif
  int rotval = 2;
  while (1)
  {
    for (i = 0; i < numrows; i++)
    {
      for (j = 0; j < numcols; j++)
      {
        /* directions to check (i+1,j), (i-1,j), (i, j-1), (i,j+1) */
        if (shadowgrid[i][j] == rotval)
        {
         // printf("here1");
          if (isnotsafe(i+1,j, numrows, numcols) && shadowgrid[i+1][j] == 1)
          {
            shadowgrid[i+1][j] = shadowgrid[i][j] + 1;
            changed = 1;
          }
          if (isnotsafe(i-1,j, numrows, numcols) && shadowgrid[i-1][j] == 1)
          {
            shadowgrid[i-1][j] = shadowgrid[i][j] + 1;
            changed = 1;
          }
          if (isnotsafe(i,j-1, numrows, numcols) && shadowgrid[i][j-1] == 1)
          {
            shadowgrid[i][j-1] = shadowgrid[i][j] + 1;
            changed = 1;
          }
          if (isnotsafe(i,j+1, numrows, numcols) && shadowgrid[i][j+1] == 1)
          {
            shadowgrid[i][j+1] = shadowgrid[i][j] + 1;
            changed = 1;
          }
        }
      }
    }
    if (changed == 0)
    {
      break;
    }
    else
    {
      changed = 0;
      rotval++;
    }
  }

  for (i = 0; i < numrows; i++)
  {
    for (j = 0; j < numcols; j++)
    {
      if (shadowgrid[i][j] == 1)
      {
        for (i = 0; i < numrows; i++)
        {
          free(shadowgrid[i]);
        }

        return -1;
      }
    }
  }
  for (i = 0; i < numrows; i++)
  {
    free(shadowgrid[i]);
  }

  return (rotval - 2);

}

void main()
{
  int **input = {{2,1,1},
                 {1,1,0},
                 {0,1,1}
                };
  for ()
  {
  }
  int colsize = 3;
  printf("minutes = %d\n", orangesRotting(input, 3,&colsize));
}



