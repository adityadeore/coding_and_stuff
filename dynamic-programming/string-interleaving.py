def inter(s1, s2, s3):
    def recinter(s1,s2,s3,i,j,k, memo={}):
      if(memo.get((i,j,k)) is not None):
        return memo[(i,j,k)]
      if k == len(s3):
        return True
      elif j == len(s2):
        if s3[k:] == s1[i:]:
          return True
        else:
          return False
      elif i == len(s1):
        if s3[k:] == s2[j:]:
          return True
        else:
          return False
      else:
        if s1[i] == s3[k] and s2[j] == s3[k]:
          memo[(i,j,k)] = recinter(s1,s2,s3,i+1,j,k+1) or recinter(s1,s2,s3,i,j+1,k+1)
          return memo[(i,j,k)]
        elif s1[i] == s3[k]:
          memo[(i,j,k)] = recinter(s1,s2,s3,i+1,j,k+1)
          return memo[(i,j,k)]
        elif s2[j] == s3[k]:
          memo[(i,j,k)] = recinter(s1,s2,s3,i,j+1,k+1)
          return memo[(i,j,k)]
        else:
          memo[(i,j,k)]= False
          return memo[(i,j,k)]

    return (recinter(s1,s2,s3,0,0,0, {}))

inter("aabcc","dbbca","adbbcbcac")


