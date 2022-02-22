def getSubsequences(str):
  res = []
  def recGetSubsequences(str, i, subseq):
    if(len(str) == i):
      res.append(subseq)
    else:
      recGetSubsequences(str,i+1, subseq+str[i])
      recGetSubsequences(str,i+1, subseq)
    
#  res.append("")
#  res.append(str)
  recGetSubsequences(str,0,"")
  print(res)
getSubsequences("abcd")
