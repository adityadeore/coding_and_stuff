def paths(matrix):
  def isvalid(matrix, i,j):
    numrows = len(matrix)
    numcols = len(matrix[0])
    if(i >= 0 and i < numrows and j >= 0 and j < numcols):
      return True
    return False

  def recpaths(matrix, i, j, lp={}):
    m = len(matrix)
    n = len(matrix[0])
    if lp.get((i,j)) is not None:
      return lp[(i,j)]
    elif(i == m-1 and j == n-1 and matrix[i][j] == 0):
      return 1
    elif (i == m-1 and j == n-1 and matrix[i][j] == 1):
      return 0
    else:
      pd = 0
      pr = 0
      if (isvalid(matrix, i+1, j) and matrix[i+1][j] == 0):
        pd = recpaths(matrix, i+1, j, lp)
      if (isvalid(matrix, i, j+1) and matrix[i][j+1] == 0):
        pr = recpaths(matrix, i, j+1, lp)

      lp[(i,j)] = pd + pr
      return lp[(i,j)]
  if(matrix[0][0] == 1):
    return 0
  return recpaths(matrix, 0,0,{})

