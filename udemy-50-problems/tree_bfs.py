class Tree:
    def __init__(self, data, left = None, right = None):
        self.data = data
        self.left = left
        self.right = right
        
# Parameters:
#  root: Tree
# return type: None

# WARNING: There are no testcases for this problem, compare your solution with the one explained in the video
from collections import deque
def bfs(root):
  if(root == None):
    return root
  queue = deque()
  queue.append(root)

  while(queue):
    node = queue.pop()
    print(node.val)

    if(node.left != None):
      queue.append(node.left)
    if(node.right != None):
      queue.append(node.right)

