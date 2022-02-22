# Parameters:
#  num: str
#  k: int
# return type: str

def smallestAfterRemoving(num, k):
  wnum = num
  l_wnum = list(wnum)
  if(k == 0):
    return num

  if(num[0] != '0'):
    i = 1
    while(num[i] == '0'):
      i+=1
    if(i > 1):
      str1 = num[0:i]
      str2 = num[i:]
      k = k-1
    else:
      str2 = num
  print(str2)
  if(k == 0):
    return str2
 
  l_wnum = list(str2)
  #l_wnum1 = int(l_wnum)
  l_wnum1=[]
  for i, x in enumerate(str2):
    l_wnum1.append( int(x))

  for i in range(0,k):
    valtr = max(l_wnum1)
    l_wnum1.remove(valtr)
  output = ''
  for i,x in enumerate(l_wnum1):
    output = output + str(l_wnum1[i])
  print(output)

smallestAfterRemoving("9251024740", 7)
