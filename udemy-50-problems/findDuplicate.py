from collections import defaultdict
def findDuplicate(arr):
  d= defaultdict()

  for elem in arr :
    if elem in d:
      return elem
    else:
      d[elem]=True

  return None

