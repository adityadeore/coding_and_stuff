#include<stdlib.h>
#include<string.h>
#include<stdio.h>

#define MIN(a,b) ((a) < (b) ? (a) : (b))

int minPathSum(int** grid, int gridSize, int* gridColSize)
{
  if (gridSize == 0 || *gridColSize == 0)
  {
    return  0;
  }

  /* allocate the dp grid */

  int **dpgrid;
  int numrows = gridSize;
  int numcols = *gridColSize;
  int i = 0;
  int j = 0;

  dpgrid = malloc(sizeof(int) * numrows);
  for (i = 0; i < numrows; i++)
  {
    dpgrid[i] = malloc(sizeof(int) * numcols);
  }
  dpgrid[0][0] = grid[0][0];
  printf("%d %d\n", numrows, numcols);
  /* calc the mim value needed */
  for (i = 0; i < numrows; i++)
  {
    for (j = 0; j < numcols; j++)
    {
      if (i > 0 && j > 0)
      {
        dpgrid[i][j] = grid[i][j] + MIN(dpgrid[i-1][j], dpgrid[i][j-1]);
      }
      else if (i > 0 && j == 0 )
      {
        dpgrid[i][0] = grid[i][0] + dpgrid[i-1][0];
      }
      else if (i == 0 && j > 0)
      {
        dpgrid[0][j] = grid[0][j] + dpgrid[0][j-1];
      }
    }
  }

  return ((dpgrid[numrows-1][numcols-1]));
}

int main()
{
  int **dpgrid;
  int i = 0;
  int j = 0;
  int numrows = 3;
  int numcols = 3;
  dpgrid = malloc(sizeof(int) * 10);

  for (i = 0; i < numrows; i++)
  {
    dpgrid[i] = malloc(sizeof(int) * 10);
  }

  dpgrid[0][0] = 1; 
  dpgrid[0][1] = 2; 
  dpgrid[0][2] = 3; 
  dpgrid[1][0] = 4; 
  dpgrid[1][1] = 5; 
  dpgrid[1][2] = 6; 
  dpgrid[2][0] = 4; 
  dpgrid[2][1] = 2; 
  dpgrid[2][2] = 1; 

  printf("sum=%d\n", minPathSum(dpgrid, 2, &numcols));
}
