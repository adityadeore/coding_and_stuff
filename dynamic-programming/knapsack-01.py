def knapsack(values, weights, k):
  def recknapsack(values, weights, k, index, memo={}):
    if(memo.get((k, index)) is not None):
      return memo[(k,index)]
    if (index == len(values)):
      return 0
    elif(weights[index] > k):
      total = 0
      total = recknapsack(values, weights, k, index+1,memo)
      memo[(k,index)]=total
      return memo[(k,index)]
    else:
      total = 0
      total = max(values[index]+recknapsack(values, weights, k-weights[index], index+1,memo), recknapsack(values, weights, k, index+1,memo))
      memo[(k,index)]=total
      #print(memo)
      return memo[(k,index)]

  return (recknapsack(values, weights, k, 0, {}))
knapsack([20,30,15,25,10], [6,13,5,10,3],20)
