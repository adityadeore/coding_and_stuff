# Parameters:
#  n: int
#  possibleSteps: Set[int]
# return type: int

def waysToClimb(n, possibleSteps):
  def recWaystoClimb(n, possiblesteps, visited):
    if(n == 0):
      return 1
    elif (visited[n] != -1):
      return visited[n]
    numways_at_n = 0  
    for elem in possiblesteps:
      if(n - elem >= 0):
        numways_at_n += recWaystoClimb(n - elem, possiblesteps, visited)
    visited[n] = numways_at_n
    return numways_at_n

  visited = [-1] * (n+1)
  recWaystoClimb(n, possibleSteps,visited)
  print(visited)


waysToClimb(10, [2,4,5,8])
