def squarematrixes(matrix):
  numrows = len(matrix)
  numcols = len(matrix[0])
  dp=[]
  for i  in range(0, numrows):
    dp.append([])
    for j in range (0, numcols) :
      dp[i].append(matrix[i][j])
  #maxval = 0
  for i in range(1, numrows):
    for j in range(1, numcols):
      if(dp[i][j] != 0):
        dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])
      #maxval = max(maxval, dp[i][j])
  #print (dp)
  return max(map(max,dp)) ** 2

'''matrix = [
  [0,0,1,1,1,0],
  [1,0,1,1,1,1],
  [0,1,1,1,1,0],
  [1,1,1,1,0,1],
  [0,1,0,1,1,1],
  ]'''
matrix=[[1],[0]]
print (squarematrixes(matrix))

