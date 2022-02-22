def maximumSubarray(arr):
  dp = [0]*len(arr)
  dp[0]=arr[0]

  for i in range (1, len(arr)):
    dp[i] = max(dp[i-1]+arr[i], arr[i])

  return max(dp)

arr = [2,3,-6,4,2,-8,3]
arr1 = [2,3,-1,4,-10,2,5]
val = maximumSubarray(arr)
print(val)
