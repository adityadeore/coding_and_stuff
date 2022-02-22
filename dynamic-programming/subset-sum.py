def subsets(arr, k):
  def recsubsets(arr, i, k, memo={}):
    if memo.get((i,k) is not None):
      return memo[(i,k)]
    if k == 0:
      return 1
    elif (k < 0):
      return 0
    elif i == len(arr):
      return 0
    else:
       memo[(i,k)] = recsubsets(arr, i+1, k - arr[i], memo) + recsubsets(arr, i+1, k, memo)
       return memo[(i,k)]

  return  (recsubsets(arr, 0, k, {}))
arr=[1,2,3,1,4]
k = 6
subsets(arr, k)
