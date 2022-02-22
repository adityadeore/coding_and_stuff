def cost(train_days, costs, n):
  def reccost(td, cost, n, index,dc):
    #print(index, dc)
    if(index == len(td)):
      return 0
    elif (dc >= td[-1]):
      return 0
    else:
      total = float('inf')
      i = 0
      for i in range(index, len(td)):
        if(td[i] > dc):
          break
      c_1 = cost[0]+reccost(td,cost,n,i+1, td[i])
      c_7 = cost[1]+reccost(td,cost,n,i+1, td[i]+6)
      c_30 = cost[2]+reccost(td,cost,n,i+1, td[i]+29)
      total = min(c_1, c_7, c_30)
      return total

  return(reccost(train_days, costs, n, 0, 0))
train_days = [1,3,8,9,22,23,28,31]
costs = [4,10,25]
n  = 32
cost(train_days, costs, n)
