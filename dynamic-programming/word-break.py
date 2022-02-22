def word_break(s, words):
  def recwordbreak(s, words, s_i, e_i, memo={}):
    if(memo.get((s_i, e_i)) is not None):
      return memo[(s_i, e_i)]
    if(s_i == len(s)):
      return True
    else:
      while(e_i < len(s)):
        for i in range(0, len(words)):
          if(s[s_i:e_i+1] == words[i]):
            memo[(s_i,e_i)] =  recwordbreak(s,words, e_i+1, e_i+1, memo)
            if(memo[(s_i,e_i)] == True):
              return memo[(s_i,e_i)]
        e_i += 1
      memo[(s_i,e_i)] = False
      return memo[(s_i,e_i)]
  print(recwordbreak(s, words, 0,0,{}))
s = "catsandogsareanimals"
words=["cats", "dogi", "sand","and","cat", "mals","san", "doga","are","animal", "ani", "og","sar"]
word_break(s, words)

