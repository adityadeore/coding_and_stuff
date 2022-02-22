def paths(matrix):
    pathcount = 0
    def recPaths(matrix, row, col):
      numrows = len(matrix)
      numcols = len(matrix[0])
      if(row == numrows - 1 and col == numcols -1):
        nonlocal pathcount
        pathcount += 1
        return

      if(row >= 0 and row < numrows-1 and matrix[row+1][col] == 0):
        recPaths(matrix, row+1, col)
      if(col >= 0 and col < numcols-1 and matrix[row][col+1] == 0):
        recPaths(matrix, row, col+1)

      return

    recPaths(matric,0,0)
    return pathcount

# Dynamic programming 
def paths(matrix):
  dp=[[0]*len(matrix[0])]*len(matrix)

  dp[0][0] = 1

  for i in range(1, len(matrix)):
    if(matrix[i][0] == 0):
      dp[i][0] = dp[i-1][0]
    else:
      dp[i][0] = 0

  for j in range(1, len(matrix[0])):
    if(matrix[0][j] == 0):
        dp[0][j] = dp[0][j-1]
      else:
        dp[0][j] = 0

  for i in range (1, len(matrix)) :
    for j in range (1, len(matrix[0])) :
      if(matrix[i][j] == 0):
        dp[i][j] = dp[i-1][j] + dp[i][j-1]
      else:
        dp[i][j] = 0

  return (dp[len(matrix)-1][len(matrix[0])-1])


