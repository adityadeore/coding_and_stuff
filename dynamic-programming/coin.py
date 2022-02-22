def coins(amount, possible_coins):
  def reccoins(amount, possible_coins, memo={}):
    if(memo.get(amount) is not None):
      return memo[amount]
    if(amount == 0):
      return 0
    else:
      total = float('inf')
      for coin in possible_coins:
        if (amount >= coin):
          total = min(total, 1+reccoins(amount-coin, possible_coins))
      
      memo[amount]=total
      return memo[amount]
  ret = reccoins(amount, possible_coins, {})
  if(ret == float('inf')):
    return (-1)
  else:
    return(ret)

coins(15, [1])
