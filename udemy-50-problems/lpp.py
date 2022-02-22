# Parameters:
#  str: str
# return type: bool
from collections  import defaultdict
def lpp(str):
  occ = []
  for i in range(len(str)):
    if(ord(str[i]) > 91):
      occ[ord(str[i]) - 97] += 1
    else:
      occ[ord(str[i]) - 65] += 1

  length = 0
  for occ1 in occ in :
    length += occ1 if occ1 % 2 == 0 else occ1 - 1
  if length < len(str):
    length += 1

  return length


