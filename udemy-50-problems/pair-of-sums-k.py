from collections import defaultdict
def findPair(arr: List, k):
 
  d= defaultdict(List)
  for i, elem in enumerate(arr):
    d[elem].append(i)

  for i, elem in enumerate(arr):
    target = k - elem
    if(target in d and target != elem):
      return True
    elif (target in d and target == elem):
      indices = d[target]
      for index in indices:
        if(index != i):
          return True
    else:
      continue
  return False


arr = [4,5,1,-3,6]
target = 11
ret = findPair(arr, target)

print(ret)

