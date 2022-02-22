def findPeak(arr):
  left = 0
  right = len(arr) - 1

  while(left < right):
    mid = (left+right)//2

    if(arr[mid] < arr[mid+1]):
      left = mid+1
    else:
      right = mid

  return left


arr=[-5,-2,-1,19,19]
ret = findPeak(arr)

print(ret)


