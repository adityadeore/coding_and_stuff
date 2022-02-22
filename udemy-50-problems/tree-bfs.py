class Tree:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        
# Parameters:
#  root: Tree
# return type: List[List[int]]
from collections import deque
def getValuesByLevel(root):
  res=[[]]
  queue=deque()
  level = 0
  queue.append([level,root])

  while(queue):
    lvl, node = queue.pop()
    if(res[lvl] == None):
      res.append([])
    res[-1].append(node.data)

    if(node.left):
      queue.append(lvl+1, node.left)
    if(node.right):
      queue.append(lvl+1, node.right)

  return res




