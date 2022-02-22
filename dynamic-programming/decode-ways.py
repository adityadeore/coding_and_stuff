def ways(s):
    def recways(s, index, memo={}):
      if(memo.get(index) is not None):
        return memo[index]
      if(index == len(s)):
        return 1
      elif (s[index] == 0):
        return 0
      else:
        total = 0
        if(s[index] >= '1' and s[index] <= '9'):
          total += recways(s, index+1)
        if(index < len(s)-1):
          if(s[index]+s[index+1] >= '10' and s[index]+s[index+1] <= '26'):
            total += recways(s, index+2)
        memo[index] = total
        return memo[index]

    print(recways(s,0, {}))
ways('512810120129')
