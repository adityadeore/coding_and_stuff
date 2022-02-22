def mincostpath(matrix):

  def recmincostpath(matrix, m, n, lp={}):
    numrows = len(matrix)
    numcols = len(matrix[0])
    key = str(m)+" "+str(n)
    if (lp.get(key) != None):
      return lp[key]
    elif (m == numrows - 1 and n == numcols - 1):
      return matrix[m][n]
    else:
      cost = 0
      if(m >= 0 and m < numrows - 1 and n >= 0 and n < numcols -1):
        cost = min(recmincostpath(matrix, m+1, n, lp), recmincostpath(matrix, m,n+1, lp))
      elif m >= 0 and m < numrows - 1:
        cost = recmincostpath(matrix, m+1, n, lp)
      else:
        cost = recmincostpath(matrix, m, n+1, lp)

      cost += matrix[m][n]
      lp[key] = cost
      return lp[key]

  return recmincostpath(matrix,0,0,{})
              

