# Parameters:
#  amount: int
#  coins: Set[int]
# return type: int

def coinChange(amount, coins):
  dp = []
  for i in range (0, amount+1) :
    dp.append(0)
  for j in range (1, amount+1):
    for i in range(0, len(coins)):
      if (coins[i] == j):
        dp[j] = 1
        
        break
      elif(dp[j - coins[i]] > 0 ):
        if(dp[j] == 0):
          dp[j] = 1+dp[j-coins[i]]
          
        else:
          dp[j] = min(dp[j], 1+dp[j-coins[i]])
      else:
        pass
  if(dp[amount] > 0):
    return(dp[amount])
  else:
    return -1


print(coinChange(34, [5,13]))


