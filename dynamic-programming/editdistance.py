def dist(word1, word2):
  def recdist(word1, word2, i, j, memo={}):
    if(memo.get((i,j)) is not None):
      return memo[(i,j)]
    elif (i == len(word1)):
      return len(word2) - j
    elif (j == len(word2)):
      return len(word1) - i
    elif (word1[i] == word2[j]):
      vs = 0
      vs= recdist(word1, word2, i+1, j+1, memo)
      memo[(i,j)]=vs
      return memo[(i,j)]
    else:
      vi=0
      vr = 0
      vd = 0
      vi = 1+recdist(word1, word2, i,j+1, memo)
      vr = 1+recdist(word1, word2, i+1, j+1, memo)
      vd = 1+recdist(word1, word2, i+1, j, memo)
      memo[(i,j)] = min(vi,vr,vd)
      
      return memo[(i,j)]

  print(recdist(word1, word2, 0, 0, {}))
dist('f', "fcd")
