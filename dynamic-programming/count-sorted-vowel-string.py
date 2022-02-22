def count(n):
    def reccount(n, s, memo={}):
      vowel = ['a','e','i','o','u']
      if(memo.get((n,s)) is not None):
        return memo[(n,s)]
      if n == 0:
        return 1
      else:
        total = 0
        for i in range(0, len(vowel)):
          if(len(s) == 0):
            total += reccount(n-1, s+vowel[i], memo)
          else:
            if s[-1] == 'a':
              total += reccount(n-1, s+vowel[i], memo)
            elif s[-1] == 'e':
              if(i >= 1):
                total += reccount(n-1, s+vowel[i], memo)
            elif s[-1] == 'i':
              if(i >= 2):
                total += reccount(n-1, s+vowel[i],memo)
            elif s[-1] == 'o':
              if(i >= 3):
                total += reccount(n-1, s+vowel[i], memo)
            elif s[-1] == 'u':
              if(i >= 4):
                total += reccount(n-1, s+vowel[i], memo)
        memo[(n,s)]=total
        return memo[(n,s)]

    print (reccount(n,'',{}))
count(9)

