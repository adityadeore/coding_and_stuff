# Parameters:
#  arr: List[int]
# return type: List[int]

def productExceptSelf(arr):
  n = len(arr)
  left = [0] * len(arr)
  right = [0] * len(arr)
  prod=[0]*n

  left[0] = arr[0]
  right[n-1] = arr[n-1]

  for i in range(1, n):
    left[i] = left[i-1] * arr[i]

  for j in range (n-2, -1,-1) :
    right[j] = right[j+1] * arr[j]

  prod[0] = right[1]
  prod[n-1] = left[n-2]

  for i  in range(1, n-1):
    prod[i] = left[i-1] * right[i+1]

  return prod

