def gold(mine):
  def isvalid(matrix, i,j):
    nr = len(matrix)
    nc = len(matrix[0])
    if(i >= 0 and i < nr and j >= 0 and j < nc):
      return True
    return False

  def recgold(mine, i, j, memo):
    nr = len(mine)
    nc = len(mine[0])
    if(memo.get((i,j)) is not None):
      return memo[(i,j)]
    elif (i == nr-1):
      memo[(i,j)] = mine[i][j]
      return mine[i][j]
    else:
      val_b = 0
      val_bl = 0
      val_br = 0
      if isvalid(mine,i+1,j):
        val_b = mine[i][j]+recgold(mine,i+1,j,memo)
      if isvalid(mine,i+1,j-1):
        val_bl = mine[i][j]+recgold(mine,i+1,j-1,memo)
      if isvalid(mine,i+1,j+1):
        val_br = mine[i][j]+recgold(mine,i+1,j+1,memo)
      val = max(val_b, val_br, val_bl)
      memo[(i,j)]=val
      return memo[(i,j)]

  memo={}
  maxgold = 0
  for j in range(0, len(mine[0])):
    maxgold = max(maxgold, recgold(mine, 0, j, memo))

  return maxgold
#[[3,2,12,15,10],[6,19,7,11,17],[8,5,12,32,21],[3,20,2,9,7]]
print( gold([[3,2,12,15,10],[6,19,7,11,17],[8,5,12,32,21],[3,20,2,9,7]]))
