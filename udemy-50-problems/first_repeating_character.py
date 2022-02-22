from collections import defaultdict
def firstRepeatingCharacter(s):
  d=defaultdict()
  for char in s:
    if char in d:
      return char
    else:
      d[char]=1

  return None

