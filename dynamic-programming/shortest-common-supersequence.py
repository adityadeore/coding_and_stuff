def scs(s1, s2):
  def recscs(s1, s2, i, j, memo={}):
    if(memo.get((i,j)) is not None):
      return memo[(i,j)]
    if(len(s1) == i ):
      return len(s2)-j
    elif(j == len(s2) ):
      return len(s1)-i
    elif(s1[i] == s2[j]):
      vs = 0
      vs = 1 + recscs(s1,s2,i+1, j+1, memo)
      memo[(i,j)]=vs
      return memo[(i,j)]
    else:
      v1 = 0
      v2 = 0
      v1 = 1+recscs(s1,s2,i+1,j, memo)
      v2 = 1+recscs(s1,s2,i,j+1, memo)
      memo[(i,j)]=min(v1,v2)
      return memo[(i,j)]
  
  print (recscs(s1, s2, 0,0, {}))
scs("f","aaf")
