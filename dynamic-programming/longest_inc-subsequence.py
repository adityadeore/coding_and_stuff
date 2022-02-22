def lis(arr):
  def reclis(arr, index, prev = float('-inf'), memo={}):
    if(memo.get((prev,index)) is not None):
      return memo[(prev,index)]
    if(index == len(arr)):
      return 0
    else:
      if arr[index] > prev:
        memo[(prev,index)] =  max(1+reclis(arr, index+1, arr[index], memo),  reclis(arr, index+1, prev, memo))
      else:
        memo[(prev,index)]= reclis(arr, index+1, prev, memo)
      return memo[(prev,index)]

  print((reclis(arr, 0)))

lis([7,5,2,4,7,2,3,6,4,5,12,1,7])


          

