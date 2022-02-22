def rod(prices, n):
  def recrod(prices, n, memo={}):
    if(memo.get(n) is not None):
      return memo[n]
    if(n == 0):
      return 0
    else:
      total = float('-inf')
      for i in range(1, len(prices)):
        if(i <= n):
          total =  max(total, prices[i]+recrod(prices, n-i, memo))
      memo[n]=total
      return memo[n]

  return(recrod(prices,n, {}))

rod([0,1,3,5,6,7,9,10,11], 8)

