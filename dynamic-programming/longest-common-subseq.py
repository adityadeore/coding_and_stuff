def lcs(s1, s2):
  def reclcs(s1, s2, i, j, memo={}):
    if(memo.get((i,j)) is not None):
      return memo[(i,j)]
    elif(i == len(s1) or j == len(s2)):
      return 0
    elif (s1[i] == s2[j]):
      val = 0
      val = 1 + reclcs(s1, s2, i+1, j+1)
      memo[(i,j)] = val
      return memo[(i,j)]
    else:
      val = 0
      val = max(reclcs(s1,s2,i+1,j), reclcs(s1,s2,i, j+1))
      memo[(i,j)] = val
      return memo[(i,j)]

  memo={}
  reclcs(s1,s2,0,0,memo)
  maxkey = max(memo, key=memo.get)
  return (memo[maxkey])
lcs("abdacbab", "acebfca")

