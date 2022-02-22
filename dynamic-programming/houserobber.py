def rob(arr):
  def recrob(arr, i, memo={}):
    if memo.get(i) is not None:
      return memo[i]
    elif i >= len(arr):
      return 0
    elif i == len(arr):
      return arr[i]
    else:
      money_2 = 0
      money_3 = 0
      money_2 = arr[i] + recrob(arr, i+2, memo)
      money_3 = arr[i] + recrob(arr, i+3, memo)
      memo[i] = max(money_2, money_3)
      
      return memo[i]

  memo={}
  recrob(arr, 0,memo)
  if(len(arr) > 1):
    recrob(arr, 1,memo)
  else:
    return arr[0]

  return max(memo[0], memo[1])

print(rob([4,8,12,1,2,10,3,6,8]))
