# Parameters:
#  values: List[int]
#  weights: List[int]
#  maxWeight: int
# return type: int

def knapsack(values, weights, maxWeight):
  def recknapsack(values, weights, maxWeight, i = 0, memoiz={}):
    key = str(i)+" "+str(maxWeight)

    if memoiz.get(key) is not None:
      return memoiz[key]
    elif i == len(values):
      return 0
    elif weights[i] > maxWeight:
      output=knapsack(values, weights, maxWeight, i+1)
      memoiz[key] = output
      return output
    else:
      output = max(values[i]+recknapsack(values, weights,maxWeight-weights[i], i+1, memoiz), recknapsack(values, weights,maxWeight, i+1))
      memoiz[key]=output
      return output


