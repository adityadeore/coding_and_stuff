# Parameters:
#  arr: List[int]
# return type: int

def lis(arr):
  if(len(arr) == 1):
    return 1
  if(len(arr) == 0):
    return 0
  dp=[1]*len(arr)

  for i in range(1, len(arr)):
    for j in range(i-1, -1, -1):
      if (arr[i] > arr[j]):
        dp[i] = max(dp[i], 1+dp[j])

  return (max(dp))

lis([7,5,2,4,7,2,3,6,4,5,12,1,7])

