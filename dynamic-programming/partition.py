def partition(arr):
  def recpartition(arr, arrsum, subsetsum, i, memo={}):
    if(memo.get((arrsum,subsetsum,i)) is not None):
      return memo[(arrsum,subsetsum,i)]
    if(arrsum == subsetsum):
      return True
    elif(arrsum < subsetsum):
      return False
    elif(i == len(arr)):
      return False
    else:
      memo[(arrsum,subsetsum,i)] =  recpartition(arr, arrsum - arr[i], subsetsum+arr[i], i+1) or recpartition(arr, arrsum, subsetsum, i+1)
      return memo[(arrsum,subsetsum,i)]

  total = sum(arr)
  if(total % 2):
    return False
  return(recpartition(arr, total, 0 , 0, {}))

partition([5,6,2,3,1,8])
