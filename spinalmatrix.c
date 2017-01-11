/* 
  To build:
  gcc -g spinalmatrix.c  -o spinalmatrix 
  
  This code prints a matrix in a spinal loop*/
#include <stdio.h>
#include <stdlib.h>

/* test array */
int spinalloop[3][4] = {1,2,3,11,4,5,6,12,7,8,9,13};

int totaldone = 0;
void go_right(int row, int colstart, int colend)
{
  int col;
  for (col = colstart; col <= colend; col++)
  {
    printf("right: row = %d, col = %d, num = %d \n", row, col, spinalloop[row][col]);
    totaldone++;
  }
}
void go_down(int col, int rowstart, int rowend)
{
  int row;
  for (row = rowstart; row <= rowend; row++)
  {
    printf("down: row = %d, col = %d, num = %d \n", row, col, spinalloop[row][col]);
    totaldone++;
  }
}
void go_left(int row, int colstart, int colend)
{
  int col;
  for (col = colend; col >= colstart; col--)
  {
    printf("left: row = %d, col = %d, num = %d \n", row, col, spinalloop[row][col]);
    totaldone++;
  }
}
void go_up(int col, int rowstart, int rowend)
{
  int row;
  for (row = rowend; row >= rowstart; row--)
  {
    printf("up: row = %d, col = %d, num = %d \n", row, col, spinalloop[row][col]);
    totaldone++;
  }

}
void printspinal(int numrows, int numcols)
{
  int row = 0;
  int rowstart = 0;
  int colstart = 0;
  int rowend = numrows;
  int colend = numcols;
  while (1)
  {
      go_right(rowstart, colstart, colend);
      if (totaldone == ((numrows+1) * (numcols+1)))//0 == isdone(numrows, numcols))
      {
        break;      
      }
      rowstart = rowstart + 1;
      go_down(colend, rowstart, rowend);
      if (totaldone == ((numrows+1) * (numcols+1)))//0 == isdone(numrows, numcols))
      {
        break;      
      }
      colend = colend-1;
      go_left(rowend, colstart, colend);
      if (totaldone == ((numrows+1) * (numcols+1)))//0 == isdone(numrows, numcols))
      {
        break;      
      }
      rowend = rowend-1;
      go_up(colstart, rowstart, rowend);
      if (totaldone == ((numrows+1) * (numcols+1)))//0 == isdone(numrows, numcols))
      {
        break;      
      }
      colstart = colstart+1;
  }
  printf("\n");
}
int main()
{
  int numrows = 2; /*from the test array -- count from 0*/
  int numcols = 3; /* from the test array -- count from 0*/
  printspinal(numrows, numcols);
  return 0;
}

