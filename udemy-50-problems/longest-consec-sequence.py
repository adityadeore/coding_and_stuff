# Parameters:
#  arr: List[int]
# return type: List[List[int]]
  
# Parameters:
#  arr: List[int]
# return type: int
from collections import defaultdict
 
def longestConsecutiveSequence(arr):
  d= defaultdict()
  for i  in range(0, len(arr)):
    if arr[i] not in d:
      d[arr[i]] = 1

print(longestConsecutiveSequence([14,1,8,4,0,13,6,9,2,7]))


