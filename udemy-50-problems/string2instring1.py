def substrIndex(str1, str2):

  l_s2 = len(str2)
  l_s1 = len(str1)

  if(l_s2 == 0 or l_s1 == 0 or l_s2 > l_s1):
    return -1
  
  for i in range(0, l_s1-l_s2+1):
    if(str2 == str1[i:i+l_s2]):
      return i

  return -1

ret = substrIndex('abcdefgh', 'gh')
print(ret)
