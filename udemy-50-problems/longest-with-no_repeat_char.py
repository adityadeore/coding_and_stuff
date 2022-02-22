from collections import defaultdict
def longestSubstringWithoutRepeating(s):
  d = defaultdict()
  startindex = 0
  endindex = 0
  
  for i, char in enumerate(s):
    if(char not in d):
      d[char] = i
    else:
      if(d[char] >= startindex):
        curmax = max(curmax, i-startindex)
        startindex = d[char] + 1
        d[char] = i
      else:
        d[char] = i
        
  return (max(curmax, len(s)-startindex))
      
