# Parameters:
#  arr: List[int]
# return type: List[List[int]]
  

def getPermutations(arr):
  res =[]
  def getallperm(arr):
    n= len(arr)
    i = 0
    j = n - 1
    nonlocal res
    while(j >= 1):
      if(arr[j-1] < arr[j]):
        s1 = j-1
        s2 = j
        k = n - 1
        while(arr[k] <= arr[s1] and k > s2):
          k-=1
        arr[s1], arr[k] = arr[k], arr[s1]
        arr[s1+1:]=arr[:s1:-1]
        res.append(arr)
        print(arr)
        break
      else:
        j -= 1

    if(j == 0):

      res.append(arr)
      #print(arr)
      return False
    else:
      return True
  arr.sort()
  res.append(arr)
  print(arr)
  while(getallperm(arr)):
    continue
  #print(res)

getPermutations([1,2,3,4,5,6,7,8])
  
