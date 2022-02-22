def vowelstrings(n):
  res = []
  def recVowelStrings(n, vowels, output, index):
    nonlocal res
    if(n == len(output)):
      res.append(''.join(output))
      return

    for i in range(index, len(vowels)) :
      output.append(vowels[i])
      recVowelStrings(n, vowels, output, i+1)
      output.pop()

  recVowelStrings(n, ['a','e','i','o','u'], [], 0)
  print(res)

vowelstrings(2)
