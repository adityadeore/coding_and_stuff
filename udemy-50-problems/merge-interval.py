def mergeIntervals(intervals, newInterval):
  res = []
  newset = []
  inserted = 0
  for i in range(0, len(intervals)):
    if(inserted == 0):
      if(intervals[i][0] < newInterval[0]):
        newset.append(intervals[i])
      else:
        newset.append(newInterval)
        newset.append(intervals[i])
        inserted = 1
    else:
      newset.append(intervals[i])
  if(inserted == 0):
    newset.append(newInterval)

  current = [newset[0][0], newset[0][1]]


  for i in range (1, len(newset)) :
    if(newset[i][0] > current[1]):
      res.append(current)
      current = [newset[i][0],newset[i][1]]
    else:
      if current[1] < newset[i][1]:
        current = [current[0], newset[i][1]] 
      else:
        current = [current[0], current[1]]
         
  res.append(current)
  print (res)
  return res

mergeIntervals([[1,3],[4,6]], [7,10])
