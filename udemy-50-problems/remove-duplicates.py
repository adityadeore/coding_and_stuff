from collections import defaultdict
def removeDuplicates(arr):
  res = []
  d= defaultdict()

  for elem in arr :
    if elem in d:
      continue
    else:
      d[elem]=True
      res.append(elem)

  return res

