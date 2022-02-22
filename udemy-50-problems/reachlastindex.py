# Parameters:
#  arr: List[int]
# return type: List[int]

def productExceptSelf(arr):
  n = len(arr)
  if(arr[0] == 0):
    return False

  def checkpossible(z_index):
    distfromz = 1
    for i in range(z_index-1, -1,-1):
      if(arr[i] != 0 and arr[i] <= distfromz):
        distfromz += 1
        continue
      else:
        return True

  for i in range (1, n):
    if(arr[i] == 0):
      if(checkpossible(i)):
        continue
      else:
        return False




