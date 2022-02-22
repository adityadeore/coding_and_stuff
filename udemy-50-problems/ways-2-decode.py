# Parameters:
#  n: int
#  possibleSteps: Set[int]
# return type: int
# Parameters:
#  arr: List[int]
#  k: int
# return type: int

def waysToDecode(str):
  n=len(str)
  if n == 0 or str[0] == "0":
    return 0

  beforePrevious = 1
  previous = 1

  for i in range(1,n) :
    current = 0
    if str[i] != "0":
      current += previous
    if("10"<= (str[i-1]+str[i]) <= "26"):
      current += beforePrevious
    beforePrevious = previous
    previous = current
  return previous
